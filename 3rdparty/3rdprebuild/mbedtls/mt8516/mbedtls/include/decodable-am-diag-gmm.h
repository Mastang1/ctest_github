#pragma once 

#include <vector>
#include <unordered_map>

#include "base/kaldi-common.h"
#include "gmm-4decode/am-diag-gmm.h"
#include "itf/decodable-itf.h"

namespace kaldi {

class DecodableAmDiagGmmScaled : public DecodableInterface {
 public:
  /// If you set log_sum_exp_prune to a value greater than 0 it will prune
  /// in the LogSumExp operation (larger = more exact); I suggest 5.
  /// This is advisable if it's spending a long time doing exp 
  /// operations. 
  DecodableAmDiagGmmScaled(const AmDiagGmm &am,
                             const Matrix<BaseFloat> &feats,
							 BaseFloat scale,
                             BaseFloat log_sum_exp_prune = -1.0):
    acoustic_model_(am), feature_matrix_(feats), 
    previous_frame_(-1), log_sum_exp_prune_(log_sum_exp_prune), scale_(scale), 
    data_squared_(feats.NumCols()) {
    ResetLogLikeCache();
  }

  // Note, frames are numbered from zero.  But state_index is numbered
  // from one (this routine is called by FSTs).
  virtual BaseFloat LogLikelihood(int32 frame, int32 tid) {
    return LogLikelihoodZeroBasedSimple(frame, id2pdf_[tid]);
  }
  virtual int32 NumFramesReady() const { return feature_matrix_.NumRows(); }
  
  // Indices are one-based!  This is for compatibility with OpenFst.
  virtual int32 NumIndices() const { return acoustic_model_.NumPdfs(); }

  virtual bool IsLastFrame(int32 frame) const {
    KALDI_ASSERT(frame < NumFramesReady());
    return (frame == NumFramesReady() - 1);
  }
  
  std::tr1::unordered_map<int32, int32> id2pdf_;  
  
  
 protected:
  void ResetLogLikeCache();
  virtual BaseFloat LogLikelihoodZeroBasedSimple(int32 frame, int32 state_index);

  const AmDiagGmm &acoustic_model_;
  const Matrix<BaseFloat> &feature_matrix_;
  int32 previous_frame_;
  BaseFloat log_sum_exp_prune_;

  struct LikelihoodCacheRecord {
    BaseFloat log_like;  ///< Cache value
    int32 hit_time;     ///< Frame for which this value is relevant
  };
  std::vector<LikelihoodCacheRecord> log_like_cache_;

  
 private:
 
  BaseFloat scale_;
  Vector<BaseFloat> data_squared_;

  KALDI_DISALLOW_COPY_AND_ASSIGN(DecodableAmDiagGmmScaled);
};


}  
