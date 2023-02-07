/*
ƽ���������ж�λ�����ó�����Զ�������ڵ�������Mic���꣺ֱ�����ꡣ��λ�������Զ����Ϊ��������ƽ��180���ڶ�λ���Զ����Ϊƽ���棬����ƽ��360���ڶ�λ��
*/

#include "../fft/kiss_fft.h"
#include "../fft/kiss_fftr.h"
#include "Para_FrameSSLWithHead.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct 	//һ��Mic����
{
	int MicIdx;
	float *BinEnergy[BIN_NUMBER];
	float BinGround[BIN_NUMBER];
	float OriginalDegree;
	int BackMic[2];	//������������Mic���ĸ�

}OneMic;

typedef struct 	//һ��Mic��
{
	int MicIdx[2];
	float PairCrossSpec[BIN_NUMBER];	
	float PairRevEnergy[BIN_NUMBER], PairSignalEnergy[BIN_NUMBER], PairGroundNoise[BIN_NUMBER];
	short *PairBinUseful[BIN_NUMBER];
	short *PairTDOAHitBuf[BIN_NUMBER][SECTOR_NUM]; //��¼buffer��ÿ��Bin�����ĸ�sector��������Ϊ1������Ϊ0


	float MicDis;
	float OriginDegree;	//��λ���Ƕ�ֵ����׼0-360��
	float IPDRange[BIN_NUMBER];//����֪MicDis�£�ÿ��Bin��IPD��Χ��ע����������ֵ��Χ�����Կ���Զ����2PI
	float IPD2PISectorNum[BIN_NUMBER];	//IPD�仯2PI��TDOA����Sector�ƣ��仯���Χ��ֻ�и�Ƶ�����������ֵ�������塣
	int LowBandBorder;
	
	float CrossReal[BIN_NUMBER], CrossIm[BIN_NUMBER];//����ϵ��
	
	float IPDSectorStep[BIN_NUMBER];	//ÿ��bin��ÿ��sector�ж���IPD���

	int TDOAHist[BIN_NUMBER][SECTOR_NUM];	//��ǰMic������λ��2pi��Χ�ڣ�����sector��hist��DOA��Χ180�ȣ�
	int TDOAHistSumBin[BIN_NUMBER]; //��ǰMic�ԣ�ÿ��bin�б�����ͳ�Ƶ�ʱƵ���ܸ���
	int TDOAHistLowBand[SECTOR_NUM];
	int TDOAHistFinal[SECTOR_NUM];


}OnePair;



typedef struct  
{
	int ChannelNumber;
	short BinLow, BinHigh;

	short FullFrame;			//���ݻ���������Ƿ���1֡��
	int  HistoryDataLen, NewDataLen;		//���ݻ���
	short *NewDataPosition;	//���������У���ʼ��������ݵ�λ�á�	
	int BufferFrameNum;
	float Frequency[BIN_NUMBER];
	float Window[FFT_SIZE];
	int  FrameCount, FrameInBuf;
	


	short *FrameSignal;		//FFT_SIZE0, FFT_SIZE1, FFT_SIZE2, ...
	float *Spec;	//ÿ��Channel����ɢ����Ҷ�任��ϵ�� //FFT_SIZE0, FFT_SIZE1, FFT_SIZE2, ...
	kiss_fftr_cfg  *CfgForward;
	short *DataBuffer;	//��������ݣ�����һ֡��


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