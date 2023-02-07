#ifndef _detect_wav_h__
#define _detect_wav_h__

#include "VadAlgorithm.h"
#include "BufferHelper.h"
#include <string>
#include <vector>
using namespace std;

class VadProcessor
{
public:
	VadProcessor(int _sampleBit, int _sampleRate, int _headPackNum,
		int _tailPackNum, int _frame_length, int _frame_shift,
		int _frame_num_per_pack, double _adjustment, double _threshold,
		double _min_signal, int _average_number);
	~VadProcessor(void);
	
	void reset();
	detectWavRes detect(const WavBuffer & shrtBuff);
protected:
	
	void merge_data(const WavBuffer & shrtBuff,WavBuffer & retBuff);
	int reputData(short* body,unsigned int bodylen);
	

	void treateInterrupt();
	int getUnvoiced_num();
	void setUnvoiced_num(int unvoiced_num);

private:

	VadAlgorithm * mvad;	
	int frame_length;	
	int frame_shift;
	double adjustment;
	double threshold;
	double min_signal;
	int average_number;

	
	int headPackNum;	//head
	int tailPackNum;	//tail
	int currentPos;

	int frame_num_per_pack;
	int bytesPerSecond;
	int unvoiced_num;
	int validvoiced_num;
	int curdetectsize;
	bool voiced;
	bool voiceEnded;
	bool noVoiceInput;
	int maxFileSize;
	int headLen;
	WavBuffer remainWav;
	vector<int> milstoneIndex;	

	int sampleBit;
	int sampleRate;

	int SIZEOFSHORT;//
	int beginindex;//
	int endindex;//
	int curwavsize;//
	double voiceLen;//
	int voiceSize;//
	int endSpeechPack;//
	int endSilencePack;//
	bool interrupted;//
	string durOutString;//
	double durOuttmp;//
	double alpha;//

};


#endif
