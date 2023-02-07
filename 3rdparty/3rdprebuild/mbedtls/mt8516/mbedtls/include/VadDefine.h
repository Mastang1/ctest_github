#ifndef __VAD_DEINFE_H__
#define __VAD_DEINFE_H__
#include <stdio.h>

#define VAD_MAX_SECONDS_MIN		1
#define VAD_MAX_SECONDS_MAX		60
#define VAD_MAX_SECONDS_DEFAULT	30
#define VAD_HEAD_MIN		200
#define VAD_HEAD_MAX		60000
#define VAD_HEAD_DEFAULT	10000
#define VAD_TAIL_MIN		200
#define VAD_TAIL_MAX		30000
#define VAD_TAIL_DEFAULT	500

#define VAD_THREASHOLD_MIN		0
#define VAD_THREASHOLD_MAX		100
#define VAD_THREASHOLD_DEFAULT	10

#define VAD_INVALID_POS -1
/**
* @brief	端点检测状态
*/
typedef enum tag_VAD_SPEECH_STATUS
{
	VAD_SPEECH_NO_BEGIN = 0,			///< 检测，还没有检测到开始
	VAD_SPEECH_BEGIN,					///< 检测到开始端点
	VAD_SPEECH_PROGRESS,				///< 端点检测进行中
	VAD_SPEECH_END,						///< 检测到结束端点
	VAD_SPEECH_USER_STOP,				///< 用户终止音频输入
	VAD_SPEECH_NO_VOICE,				///< 没有发现音频输入（开始静音时间太长）
} VAD_SPEECH_STATUS;

//////////////////////////////////////////////////////////////////////////
// 数据结构定义

/**
* @brief	端点检测返回结果
*/
typedef struct _tag_VAD_RESULT
{
	/// 端点检测状态
	VAD_SPEECH_STATUS  eStatus;
	/// 起始端点位置
	int nBeginPos;
	/// 末尾端点位置
	int nEndPos;

}VAD_RESULT;

typedef enum _VAD_AUDIO_FORMAT_
{
	PCM16K16BIT = 0,
	PCM8K16BIT
}VAD_AUDIO_FORMAT;


class detectWavRes {

public:
	bool succ;			//成功
	bool voiced;		//检测到声音
	bool voiceEnded;	//检测到末端
	bool noVoiceInput;	//没有声音输入
	int beginPos;		//起始位置
	int engPos;			//结束位置

public:
	detectWavRes() {
		succ = false;
		voiced = false;
		voiceEnded = false;
		noVoiceInput = false;
		beginPos = VAD_INVALID_POS;
		engPos = VAD_INVALID_POS;
	}
};

class detectVadParam{
public:
	VAD_AUDIO_FORMAT eFormat;
	int nVadHead;
	int nVadTail;
	int nThreshold;
    bool bEnable;

public:
	detectVadParam() {
        bEnable = true;
		eFormat = PCM16K16BIT;
		nVadHead = VAD_HEAD_DEFAULT;
		nVadTail = VAD_TAIL_DEFAULT;
		nThreshold = VAD_THREASHOLD_DEFAULT;
	}

	detectVadParam(VAD_AUDIO_FORMAT eFormat,int nVadHead,int nVadTail,int nThreshold) {
        bEnable = true;
		this->eFormat = eFormat;
		this->nVadHead = nVadHead;
		this->nVadTail = nVadTail;
		this->nThreshold = nThreshold;
	}

	bool isValid()const
	{
		if (nVadHead < VAD_HEAD_MIN || nVadHead > VAD_HEAD_MAX
			|| nVadTail < VAD_TAIL_MIN || nVadTail > VAD_TAIL_MAX 
			|| nThreshold < VAD_THREASHOLD_MIN || nThreshold > VAD_THREASHOLD_MAX
			|| (eFormat != PCM16K16BIT && eFormat != PCM8K16BIT))
		{
			return false;
		}
		return true;
	}

};


typedef enum _tag_VadError
{
	kVadErrorUnknown = -1,
	kVadErrorNone = 0,
	kVadErrorParamInvalid,
	kVadErrorDetecterHasStart,
	kVadErrorDetecterNoStart,
}VadError;


#endif