
//#include "util/stl-utils.h"
#include "itf/options-itf.h"
#include "util/hash-list.h"
#include "fsts/fstlib.h"
#include "itf/decodable-itf.h"

namespace fst {

template<class Arc>
void RemoveEpsLocal(MutableFst<Arc> *fst);

}

namespace kaldi {

struct FasterDecoderOptions {
  BaseFloat beam;
  int32 max_active;
  int32 min_active;
  BaseFloat beam_delta;
  BaseFloat hash_ratio;
  FasterDecoderOptions(): beam(16.0),
                          max_active(std::numeric_limits<int32>::max()),
                          min_active(20),
                          beam_delta(0.5),
                          hash_ratio(2.0) { }
  void Register(OptionsItf *opts, bool full) {  /// if "full", use obscure
    /// options too.
    /// Depends on program.
    opts->Register("beam", &beam, "Decoding beam.  Larger->slower, more accurate.");
    opts->Register("max-active", &max_active, "Decoder max active states.  Larger->slower; "
                   "more accurate");
    opts->Register("min-active", &min_active,
                   "Decoder min active states (don't prune if #active less than this).");
    if (full) {
      opts->Register("beam-delta", &beam_delta,
                     "Increment used in decoder [obscure setting]");
      opts->Register("hash-ratio", &hash_ratio,
                     "Setting used in decoder to control hash behavior");
    }
  }
};

class FasterDecoder {
 public:
  typedef fst::StdArc Arc;
  typedef Arc::Label Label;
  typedef Arc::StateId StateId;
  typedef Arc::Weight Weight;

  FasterDecoder(const fst::Fst<fst::StdArc> &fst, const FasterDecoderOptions &config);

  void SetOptions(const FasterDecoderOptions &config) { config_ = config; }

  ~FasterDecoder() { ClearToks(toks_.Clear()); }

  void Decode(DecodableInterface *decodable);

  /// Returns true if a final state was active on the last frame.
  bool ReachedFinal();

  /// GetBestPath gets the decoding traceback. 
  bool GetBestPath(fst::MutableFst<Arc> *fst_out, bool use_final_probs = true);

  /// As a new alternative to Decode(), you can call InitDecoding
  /// and then (possibly multiple times) AdvanceDecoding().
  void InitDecoding();


  /// This will decode until there are no more frames ready in the decodable
  /// object, but if max_num_frames is >= 0 it will decode no more than
  /// that many frames.
  void AdvanceDecoding(DecodableInterface *decodable, int32 max_num_frames = -1);

  /// Returns the number of frames already decoded.
  int32 NumFramesDecoded() const { return num_frames_decoded_; }

 protected:

  class Token {
   public:
    Arc arc_; // contains only the graph part of the cost;
    // we can work out the acoustic part from difference between
    // "cost_" and prev->cost_.
    Token *prev_;
    int32 ref_count_;
    // if you are looking for weight_ here, it was removed and now we just have
    // cost_, which corresponds to ConvertToCost(weight_).
    double cost_;
    inline Token(const Arc &arc, BaseFloat ac_cost, Token *prev):
        arc_(arc), prev_(prev), ref_count_(1) {
      if (prev) {
        prev->ref_count_++;
        cost_ = prev->cost_ + arc.weight.Value() + ac_cost;
      } else {
        cost_ = arc.weight.Value() + ac_cost;
      }
    }
    inline Token(const Arc &arc, Token *prev):
        arc_(arc), prev_(prev), ref_count_(1) {
      if (prev) {
        prev->ref_count_++;
        cost_ = prev->cost_ + arc.weight.Value();
      } else {
        cost_ = arc.weight.Value();
      }
    }
    inline bool operator < (const Token &other) {
      return cost_ > other.cost_;
    }

    inline static void TokenDelete(Token *tok) {
      while (--tok->ref_count_ == 0) {
        Token *prev = tok->prev_;
        delete tok;
        if (prev == NULL) return;
        else tok = prev;
      }
/*	  
#ifdef KALDI_PARANOID
      KALDI_ASSERT(tok->ref_count_ > 0);
#endif
*/
    }
  };
  typedef HashList<StateId, Token*>::Elem Elem;


  /// Gets the weight cutoff.  Also counts the active tokens.
  double GetCutoff(Elem *list_head, size_t *tok_count,
                   BaseFloat *adaptive_beam, Elem **best_elem);

  void PossiblyResizeHash(size_t num_toks);

  // ProcessEmitting returns the likelihood cutoff used.
  double ProcessEmitting(DecodableInterface *decodable);

  // TODO: first time we go through this, could avoid using the queue.
  void ProcessNonemitting(double cutoff);

  HashList<StateId, Token*> toks_;
  const fst::Fst<fst::StdArc> &fst_;
  FasterDecoderOptions config_;
  std::vector<StateId> queue_;  // temp variable used in ProcessNonemitting,
  std::vector<BaseFloat> tmp_array_;  // used in GetCutoff.
  // make it class member to avoid internal new/delete.

  // Keep track of the number of frames decoded in the current file.
  int32 num_frames_decoded_;

  void ClearToks(Elem *list);

  FasterDecoder(const FasterDecoder&);
  void operator = (const FasterDecoder&);
  
};


}

