/*
ƽ���������ж�λ�����ó�����Զ�������ڵ�������Mic���꣺ֱ�����ꡣ��λ�������Զ����Ϊ��������ƽ��180���ڶ�λ���Զ����Ϊƽ��������ƽ��360���ڶ�λ��
*/

#include "../fft/kiss_fft.h"
#include "../fft/kiss_fftr.h"
#include "Para_SegSSLNoHead.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct 	//һ��Mic��
{
	int MicIdx[2];
	float PairCrossSpec[BIN_NUMBER];	
	float PairRevEnergy[BIN_NUMBER], PairSignalEnergy[BIN_NUMBER], PairGroundNoise[BIN_NUMBER];
	short PairBinUseful[BIN_NUMBER];
}OnePair;

typedef struct 	//һ��Mic�ԵĲ�����ÿ�ԵĽǶȡ����붼��ȫ��ͬ��IPD��Ϣ���Թ���ÿ�ԵĶ�λ��Χ����180�ȡ�
{	
	float MicDis;
	float OriginDegree;	//��λ���Ƕ�ֵ����׼0-360��
	short BinLow, BinHigh;
	float IPDRange[BIN_NUMBER];//����֪MicDis�£�ÿ��Bin��IPD��Χ��ע����������ֵ��Χ�����Կ���Զ����2PI
	float IPD2PISectorNum[BIN_NUMBER];	//IPD�仯2PI��TDOA����Sector�ƣ��仯���Χ��ֻ�и�Ƶ�����������ֵ�������塣
	int LowBandBorder;

	int SectorMapDegree[SECTOR_NUM][2];	//ÿ��sector��Ӧ��360���е��Ǹ�Degree��ÿ��sector��Ӧ�˾����2��degree
	int DegreeMapSector[DEGREE_NUM];	//360���ڣ�ÿ���Ƕ�ӳ��Ϊ��ǰcouple���ĸ�sector����Ϊsector��С������ֻ�㵱ǰdegree��Ӧ��������sector��
	
	
	float CrossReal[BIN_NUMBER], CrossIm[BIN_NUMBER];//����ϵ��
	
	float IPDSectorStep[BIN_NUMBER];	//ÿ��bin��ÿ��sector�ж���IPD���
	int TDOAHist[BIN_NUMBER][SECTOR_NUM];	//��ǰMic������λ��2pi��Χ�ڣ�����sector��hist��DOA��Χ180�ȣ�
	int TDOAHistSumBin[BIN_NUMBER]; //��ǰMic�ԣ�ÿ��bin�б�����ͳ�Ƶ�ʱƵ���ܸ���

	int SoundSelect;//0����1������SectorMapDegree�У�ȡ������Դ0����1

	int PairNumber;	//��һ��Mic���У�һ���������ٶԣ����¶���ÿһ�ԵĲ���
	OnePair *PairMembers;
}MicGroupPara;


typedef struct  
{
	int ChannelNumber;

	short Loc360;		//�Ƿ��ܶ�λ360��
	short FullFrame;			//���ݻ���������Ƿ���1֡��
	int  HistoryDataLen;
	int NewDataLen;		//���ݻ���
	short *NewDataPosition;	//���������У���ʼ��������ݵ�λ�á�	
	float Frequency[BIN_NUMBER];
	float Window[DOA_FFT_SIZE];
	int  FrameCount;
	int FrameInBuf;
	
/*
	short FrameSignal[CHANNEL_NUMBER][FFT_SIZE];
	float Spec[CHANNEL_NUMBER][FFT_SIZE];	//ÿ��Channel����ɢ����Ҷ�任��ϵ��
	kiss_fftr_cfg  CfgForward[CHANNEL_NUMBER];
	short DataBuffer[CHANNEL_NUMBER][FFT_SIZE];	//��������ݣ�����һ֡��
*/


	short *FrameSignal;		//FFT_SIZE0, FFT_SIZE1, FFT_SIZE2, ...
	float *Spec;	//ÿ��Channel����ɢ����Ҷ�任��ϵ�� //FFT_SIZE0, FFT_SIZE1, FFT_SIZE2, ...
	kiss_fftr_cfg  *CfgForward;
	short *DataBuffer;	//��������ݣ�����һ֡��


	int PreviousDOA;
	int FinalDOA;

	float Dif[BIN_NUMBER];

	MicGroupPara *Groups;
	int GroupNumber;

	//����Mic������360�ȷ�Χ�ڵ�hist
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


