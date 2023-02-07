/*
平面任意阵列定位，适用场景：远场，无遮挡。输入Mic坐标：直角坐标。定位能力：自动检测为线阵，则在平面180度内定位；自动检测为平面阵，则在平面360度内定位。
*/

#include "../fft/kiss_fft.h"
#include "../fft/kiss_fftr.h"
#include "Para_SegSSLNoHead.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct 	//一个Mic对
{
	int MicIdx[2];
	float PairCrossSpec[BIN_NUMBER];	
	float PairRevEnergy[BIN_NUMBER], PairSignalEnergy[BIN_NUMBER], PairGroundNoise[BIN_NUMBER];
	short PairBinUseful[BIN_NUMBER];
}OnePair;

typedef struct 	//一组Mic对的参数，每对的角度、距离都完全相同，IPD信息可以共享。每对的定位范围都是180度。
{	
	float MicDis;
	float OriginDegree;	//单位：角度值，标准0-360度
	short BinLow, BinHigh;
	float IPDRange[BIN_NUMBER];//在已知MicDis下，每个Bin的IPD范围，注意它不是主值范围，所以可以远大于2PI
	float IPD2PISectorNum[BIN_NUMBER];	//IPD变化2PI，TDOA（以Sector计）变化多大范围。只有高频混叠情况下这个值才有意义。
	int LowBandBorder;

	int SectorMapDegree[SECTOR_NUM][2];	//每个sector对应了360度中的那个Degree。每个sector对应了镜像的2个degree
	int DegreeMapSector[DEGREE_NUM];	//360度内，每个角度映射为当前couple的哪个sector。因为sector较小，所以只算当前degree对应的最中心sector。
	
	
	float CrossReal[BIN_NUMBER], CrossIm[BIN_NUMBER];//互谱系数
	
	float IPDSectorStep[BIN_NUMBER];	//每个bin，每个sector有多大的IPD宽度
	int TDOAHist[BIN_NUMBER][SECTOR_NUM];	//当前Mic对在相位差2pi范围内，基于sector的hist（DOA范围180度）
	int TDOAHistSumBin[BIN_NUMBER]; //当前Mic对，每个bin中被计入统计的时频点总个数

	int SoundSelect;//0或者1，即在SectorMapDegree中，取镜像声源0还是1

	int PairNumber;	//这一组Mic对中，一共包含多少对，以下都是每一对的参数
	OnePair *PairMembers;
}MicGroupPara;


typedef struct  
{
	int ChannelNumber;

	short Loc360;		//是否能定位360度
	short FullFrame;			//数据缓存情况（是否满1帧）
	int  HistoryDataLen;
	int NewDataLen;		//数据缓存
	short *NewDataPosition;	//新来数据中，开始处理的数据的位置。	
	float Frequency[BIN_NUMBER];
	float Window[DOA_FFT_SIZE];
	int  FrameCount;
	int FrameInBuf;
	
/*
	short FrameSignal[CHANNEL_NUMBER][FFT_SIZE];
	float Spec[CHANNEL_NUMBER][FFT_SIZE];	//每个Channel的离散傅里叶变换的系数
	kiss_fftr_cfg  CfgForward[CHANNEL_NUMBER];
	short DataBuffer[CHANNEL_NUMBER][FFT_SIZE];	//缓存的数据（不足一帧）
*/


	short *FrameSignal;		//FFT_SIZE0, FFT_SIZE1, FFT_SIZE2, ...
	float *Spec;	//每个Channel的离散傅里叶变换的系数 //FFT_SIZE0, FFT_SIZE1, FFT_SIZE2, ...
	kiss_fftr_cfg  *CfgForward;
	short *DataBuffer;	//缓存的数据（不足一帧）


	int PreviousDOA;
	int FinalDOA;

	float Dif[BIN_NUMBER];

	MicGroupPara *Groups;
	int GroupNumber;

	//所有Mic在整个360度范围内的hist
	int DegreeOverlapHist[DEGREE_NUM];
	int DegreeSingleHist[DEGREE_NUM];
	int SectorFinalHist[SECTOR_NUM];

///only for test!!!!	
	float ParaSpeechDown[BIN_NUMBER];
	float ParaGroundUp[BIN_NUMBER];
	float ParaGroundDown[BIN_NUMBER];
	float ParaRevUp[BIN_NUMBER];
	float ParaRevDown[BIN_NUMBER];
	
#ifdef SHOW_LOG
	FILE *fp_DOA;
	FILE *fp_rawspec, *fp_spec, *fp_hist0, *fp_hist1, *fp_ipd;
	FILE *fp_binRaw, *fp_binSig, *fp_binRev, *fp_binGrd;
	FILE *fp_singleSpec;
	FILE *fp_degreeHist;
	int ShowBin;	
#endif
}SSTParameters;

SSTParameters *SegSSLNoHead_Init_float(int MicNum, float *MicPosMM, int SampleRateHz, AFE_CODE *ReturnCode, short* isCircular);

AFE_CODE SegSSLNoHead_Process_float(SSTParameters *st, short *MicIn, int PointNum, int *DOADegree, int *doa_inst);

AFE_CODE SegSSLNoHead_Exit_float(SSTParameters *st);

int SegNoGetOneFrame(SSTParameters *st);
	
int SegNoGetCrossSpec(float Spec0[DOA_FFT_SIZE], float Spec1[DOA_FFT_SIZE],  MicGroupPara *GroupPt, int GroupIdx, int PairIdx);

int SegSSLNoHead_ProcessOneGroup(SSTParameters *st, MicGroupPara *CouplePt, int GroupIdx);

int SegNoTrackNoise(SSTParameters *st, MicGroupPara *GroupPt, int GroupIdx, int PairIdx);

int SegNoRecordIPD(SSTParameters *st, MicGroupPara *GroupPt, int BinCountIn, float IPD, int GroupIdx, int PairIdx);

/*
int GetInstDOA(SSTParameters *st);

*/


