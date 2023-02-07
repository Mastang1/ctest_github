
#ifndef KALDI_FEAT_FEATURE_COMMON_INL_H_
#define KALDI_FEAT_FEATURE_COMMON_INL_H_

// Do not include this file directly.  It is included by feature-common.h

namespace kaldi {

template <class F>
void OfflineFeatureTpl<F>::Compute(
    const VectorBase<BaseFloat> &wave,
    BaseFloat vtln_warp,
    Matrix<BaseFloat> *output,
    Vector<BaseFloat> *deprecated_wave_remainder) {
  if( !output )
  {
	printf("erro output!\n");
	return;
  }
  int32 rows_out = NumFrames(wave.Dim(), computer_.GetFrameOptions()),
      cols_out = computer_.Dim();
  if (rows_out == 0) {
    output->Resize(0, 0);
    if (deprecated_wave_remainder != NULL)
      *deprecated_wave_remainder = wave;
    return;
  }
  output->Resize(rows_out, cols_out);
  if (deprecated_wave_remainder != NULL)
    ExtractWaveformRemainder(wave, computer_.GetFrameOptions(),
                             deprecated_wave_remainder);
  Vector<BaseFloat> window;  // windowed waveform.
  bool use_raw_log_energy = computer_.NeedRawLogEnergy();
  for (int32 r = 0; r < rows_out; r++) {  // r is frame index.
    BaseFloat raw_log_energy = 0.0;
    ExtractWindow(0, wave, r, computer_.GetFrameOptions(),
                  feature_window_function_, &window,
                  (use_raw_log_energy ? &raw_log_energy : NULL));

    SubVector<BaseFloat> output_row(*output, r);
    computer_.Compute(raw_log_energy, vtln_warp, &window, &output_row);
  }
}

template <class F>
void OfflineFeatureTpl<F>::Compute(
    const VectorBase<BaseFloat> &wave,
    BaseFloat vtln_warp,
    Matrix<BaseFloat> *output,
    Vector<BaseFloat> *deprecated_wave_remainder) const {
  OfflineFeatureTpl<F> temp(*this);

  temp.Compute(wave, vtln_warp, output, deprecated_wave_remainder);
}

} // end namespace kaldi

#endif
