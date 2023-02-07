/**************************************************************************************************

	功能：	离线语音识别
	作者：	原道德
	版本：	1.0
	日期：	2016年12月28日
	
***************************************************************************************************/


#include "base/kaldi-common.h"
#include "fsts/fstlib.h"
#include "matrix/matrix-lib.h"
#include "feat-4decode/feature-common.h"
#include "feat-4decode/feature-functions.h"
#include "feat-4decode/feature-mfcc.h"

#include "gmm-4decode/am-diag-gmm.h"
#include "gmm-4decode/decodable-am-diag-gmm.h"
#include "decoder/faster-decoder.h"

#define max_wordlen 50

namespace kaldi {

class asr
{
public:

	asr() : decode_fst(NULL) {
		
	}
	~asr();
	bool Init(char *transfile, char *idmapfile, char *wordmapfile, char *amfile, char *fstfile);
	void Decode(short* pcmbuf, int len);
	void GetResWord(std::vector<char *> &resword);
	
private:

	bool ReadTramat(char *transfile);
	bool ReadIdmap(char *idmapfile);
	bool ReadWordmap(char *wordmapfile);
	bool ReadAm(char *amfile);
	bool ReadFst(char *fstfile);
	
	void ExtrFeat();
	
	template<class Arc, class I>
	bool GetLinearSymbolSequencetest(const fst::Fst<Arc> &fst, vector<I> *isymbols_out, vector<I> *osymbols_out); 

	
	int left_context, right_context;
	float acoustic_scale;

	FasterDecoderOptions decoder_opts;
	MfccOptions mfcc_opts;
	
	Matrix<float> tramat;
	unordered_map<int, int> id2pdf;
	unordered_map<int, char*> num2word;
	AmDiagGmm am_gmm;
	fst::Fst<fst::StdArc> *decode_fst;
	
	Vector<float> data;
	Matrix<float> feats;
	
	std::vector<int> alignment;
    std::vector<int> words;
};

}