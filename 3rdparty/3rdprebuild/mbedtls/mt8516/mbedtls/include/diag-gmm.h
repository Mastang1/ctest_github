
#include "base/kaldi-common.h"
#include "matrix/matrix-lib.h"

namespace kaldi {

class DiagGmm {

 public:
  /// Empty constructor.
  DiagGmm() : valid_gconsts_(true) { }

  /// Returns the dimensionality of the Gaussian mean vectors
  int32 Dim() const { return means_invvars_.NumCols(); }

  void Read(std::istream &in, bool binary);
  BaseFloat LogLikelihood(const VectorBase<BaseFloat> &data) const;
  void LogLikelihoods(const VectorBase<BaseFloat> &data,
                      Vector<BaseFloat> *loglikes) const;

  /// Const accessors
  const Vector<BaseFloat> &gconsts() const {
    KALDI_ASSERT(valid_gconsts_);
    return gconsts_;
  }

  const Matrix<BaseFloat> &means_invvars() const { return means_invvars_; }
  const Matrix<BaseFloat> &inv_vars() const { return inv_vars_; }
  bool valid_gconsts() const { return valid_gconsts_; }

 private:

  Vector<BaseFloat> gconsts_;
  bool valid_gconsts_;
  Vector<BaseFloat> weights_;
  Matrix<BaseFloat> inv_vars_;
  Matrix<BaseFloat> means_invvars_;

};


}
