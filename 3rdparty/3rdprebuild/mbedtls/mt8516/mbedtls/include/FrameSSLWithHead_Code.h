/*
平面任意阵列定位，适用场景：远场，无遮挡。输入Mic坐标：直角坐标。定位能力：自动检测为线阵，则在平面180度内定位；自动检测为平面真，则在平面360度内定位。
*/

#include "../fft/kiss_fft.h"
#include "../fft/kiss_fftr.h"
#include "Para_FrameSSLWithHead.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct 	//一个Mic单体
{
	int MicIdx;
	float *BinEnergy[BIN_NUMBER];
	float BinGround[BIN_NUMBER];
	float OriginalDegree;
	int BackMic[2];	//跟它背靠背的Mic是哪个

}OneMic;

typedef struct 	//一个Mic对
{
	int MicIdx[2];
	float PairCrossSpec[BIN_NUMBER];	
	float PairRevEnergy[BIN_NUMBER], PairSignalEnergy[BIN_NUMBER], PairGroundNoise[BIN_NUMBER];
	short *PairBinUseful[BIN_NUMBER];
	short *PairTDOAHitBuf[BIN_NUMBER][SECTOR_NUM]; //记录buffer中每个Bin落入哪个sector，命中则为1，否则为0


	float MicDis;
	float OriginDegree;	//单位：角度值，标准0-360度
	float IPDRange[BIN_NUMBER];//在已知MicDis下，每个Bin的IPD范围，注意它不是主值范围，所以可以远大于2PI
	float IPD2PISectorNum[BIN_NUMBER];	//IPD变化2PI，TDOA（以Sector计）变化多大范围。只有高频混叠情况下这个值才有意义。
	int LowBandBorder;
	
	float CrossReal[BIN_NUMBER], CrossIm[BIN_NUMBER];//互谱系数
	
	float IPDSectorStep[BIN_NUMBER];	//每个bin，每个sector有多大的IPD宽度

	int TDOAHist[BIN_NUMBER][SECTOR_NUM];	//当前Mic对在相位差2pi范围内，基于sector的hist（DOA范围180度）
	int TDOAHistSumBin[BIN_NUMBER]; //当前Mic对，每个bin中被计入统计的时频点总个数
	int TDOAHistLowBand[SECTOR_NUM];
	int TDOAHistFinal[SECTOR_NUM];


}OnePair;



typedef struct  
{
	int ChannelNumber;
	short BinLow, BinHigh;

	short FullFrame;			//数据缓存情况（是否满1帧）
	int  HistoryDataLen, NewDataLen;		//数据缓存
	short *NewDataPosition;	//新来数据中，开始处理的数据的位置。	
	int BufferFrameNum;
	float Frequency[BIN_NUMBER];
	float Window[FFT_SIZE];
	int  FrameCount, FrameInBuf;
	


	short *FrameSignal;		//FFT_SIZE0, FFT_SIZE1, FFT_SIZE2, ...
	float *Spec;	//每个Channel的离散傅里叶变换的系数 //FFT_SIZE0, FFT_SIZE1, FFT_SIZE2, ...
	kiss_fftr_cfg  *CfgForward;
	short *DataBuffer;	//缓存的数据（不足一帧）


	int PreviousDOA, FinalDOA;

	float Dif[BIN_NUMBER];

	OnePair *MicPairs;
	OneMic  *SingleMic;

	int PairNumber;


	
#ifdef SHOW_LOG
	FILE *fp_DOA;
	FILE *fp_rawspec, *fp_crossspec, *fp_hist0, *fp_hist1, *fp_ipd;
	FILE *fp_binRaw, *fp_binSig, *fp_binRev, *fp_binGrd;
	FILE *fp_selectMic;
	int ShowBin;
#endif
}SSTParameters;

SSTParameters *FrameSSLWithHead_Init_float(int MicNum, float *MicPosMM, int SampleRateHz, int DelayPointNum, AFE_CODE *ReturnCode);

AFE_CODE FrameSSLWithHead_Process_float(SSTParameters *st, short *MicIn, int PointNum, int *DOADegree);


AFE_CODE FrameSSLWithHead_Exit_float(SSTParameters *st);

int FrameWithGetOneFrame(SSTParameters *st);
	
int FrameWithGetCrossSpec(SSTParameters *st, float Spec0[FFT_SIZE], float Spec1[FFT_SIZE],  OnePair *PairPt);

int FrameSSLWithHead_ProcessOnePair(SSTParameters *st, OnePair *PairPt, int PairIdx);


int FrameWithTrackNoise(SSTParameters *st, OnePair *PairPt, int PairIdx);

int FrameWithRecordIPD(SSTParameters *st, OnePair *PairPt, int BinCountIn, float IPD, int PairIdx);

int FrameSSLWithHead_SelectDirectMic(SSTParameters *st);

int FrameSSLWithHead_PairSSL(SSTParameters *st, OnePair *PairPt);