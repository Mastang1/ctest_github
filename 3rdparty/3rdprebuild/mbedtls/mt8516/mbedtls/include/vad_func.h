/**************************************************************************************************
	功能：	基于时域能量与过零率的实时vad
	作者：	原道德
	版本：	1.1
	日期：	2016年9月30日
	修改1：	2016年10月9日，加入结束状态
***************************************************************************************************/

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#ifndef __UAI_VAD_FUNC_H__
#define __UAI_VAD_FUNC_H__

namespace uai { namespace asr {

// 用于保存vad历史信息
typedef struct StruVadRes
{
	float start;
	float end;
	struct StruVadRes *next;
} VadRes;

class VadProc
{

public:

	VadProc();
	~VadProc();

	// 设置各类参数
	void SetAllowance( int s, int e, int stop );
	void SetLenNoiseInit( int len_noise_init );
	void SetTrhSnr( float trh_snr_h, float trh_snr_l );
	void SetTrhEnergy( float trh_energy_h, float trh_energy_l );
	void SetTrhZcr( int trh_zcr_h, int trh_zcr_l );
	void SetTrhZcrEne( float trh_zcr_ene );
	void SetWinLen( float win_len ) { Win_Len=win_len; return; }
	
	// 初始化vad
	void Init();
	
	// 停止检测
	void Stop();
	
	// 处理一帧数据
	int ProcFrame( short* wav_frame, int sample_frame );
	
	// 获取当前语音状态
	int GetState() { return state; }
	
	// 获取历史信息
	VadRes * GetRes() { return res_head; }

private:
	void clear();

private:

	// 能量,过零率等参数
	int allowance_s,allowance_e,allowance_stop;
	int Len_Noise_Init;
	float Trh_Snr_H;
	float Trh_Snr_L;
	float Trh_Energy_H;
	float Trh_Energy_L;
	int Trh_Zcr_H;
	int Trh_Zcr_L;
	float Trh_Zcr_Ene;
	int Win_Len;
	
	// 语音状态
	int state;
	
	int flag;
	
	// 累计帧数
	int numframe;
	
	//初始段噪声能量
	float EneNoiseInit;
	
	int NumSpeech;
	int NumNonspeech;
	int NumSegm;
	
	// 历史结果
	VadRes *res_head, *res_preseg;
	
	// 更新语音状态
	void StateUpdate( int vad_frame );

};

}
}
#endif // __UAI_VAD_FUNC_H__
