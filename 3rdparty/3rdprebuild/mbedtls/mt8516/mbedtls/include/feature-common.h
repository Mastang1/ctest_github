
#ifndef KALDI_FEAT_FEATURE_COMMON_H_
#define KALDI_FEAT_FEATURE_COMMON_H_

#include <map>
#include <string>
#include "feature-window.h"

namespace kaldi {
/// @addtogroup  feat FeatureCommon
/// @{

/// This templated class is intended for offline feature extraction, i.e. where
/// you have access to the entire signal at the start.
template <class F>
class OfflineFeatureTpl {
 public:
  typedef typename F::Options Options;

  // Note: feature_window_function_ is the windowing function, which initialized
  // using the options class, that we cache at this level.
  OfflineFeatureTpl(const Options &opts):
      computer_(opts),
      feature_window_function_(computer_.GetFrameOptions()) { }

  // Computes the features for one file (one sequence of features).
  void Compute(const VectorBase<BaseFloat> &wave,
               BaseFloat vtln_warp,
               Matrix<BaseFloat> *output,
               Vector<BaseFloat> *deprecated_wave_remainder = NULL);

  // This const version of Compute() is a wrapper that calls the non-const version on a temporary object.
  void Compute(const VectorBase<BaseFloat> &wave,
               BaseFloat vtln_warp,
               Matrix<BaseFloat> *output,
               Vector<BaseFloat> *deprecated_wave_remainder = NULL) const;

  int32 Dim() const { return computer_.Dim(); }

  private:

  F computer_;
  FeatureWindowFunction feature_window_function_;
};

/// @} End of "addtogroup feat"
}  // namespace kaldi


#include "feature-common-inl.h"

#endif  // KALDI_FEAT_FEATURE_COMMON_H_
