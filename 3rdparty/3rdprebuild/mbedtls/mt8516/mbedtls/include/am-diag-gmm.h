#pragma once 

#include <vector>

#include "base/kaldi-common.h"
#include "gmm-4decode/diag-gmm.h"
#include "itf/options-itf.h"

namespace kaldi {

class AmDiagGmm {
 public:
  AmDiagGmm() {}
  ~AmDiagGmm();

  BaseFloat LogLikelihood(const int32 pdf_index, const VectorBase<BaseFloat> &data) const;
  
  void Read(std::istream &in_stream, bool binary);
  
  int32 Dim() const {
    return (densities_.size() > 0)? densities_[0]->Dim() : 0;
  }
  int32 NumPdfs() const { return densities_.size(); }

  const DiagGmm& GetPdf(int32 pdf_index) const;

  void RemovePdf(int32 pdf_index);  
  
 private:
  std::vector<DiagGmm*> densities_;

};

inline BaseFloat AmDiagGmm::LogLikelihood(
    const int32 pdf_index, const VectorBase<BaseFloat> &data) const {
  return densities_[pdf_index]->LogLikelihood(data);
}

inline const DiagGmm& AmDiagGmm::GetPdf(int32 pdf_index) const {
  KALDI_ASSERT((static_cast<size_t>(pdf_index) < densities_.size())
               && (densities_[pdf_index] != NULL));
  return *(densities_[pdf_index]);
}

}
