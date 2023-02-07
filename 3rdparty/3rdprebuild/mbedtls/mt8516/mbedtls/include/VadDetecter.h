#ifndef __VAD_DETECTER_H__
#define __VAD_DETECTER_H__

#include "VadDefine.h"
#include "BufferHelper.h"

class VadProcessor;

class VadDetecter
{
public:
	VadDetecter(void);
	~VadDetecter(void);

public:
	int reset(const detectVadParam &param);
	int append_voice(const WavBuffer *wav,VAD_RESULT * pResult);

protected:
	bool is_check_stoped();
	bool no_voice_input(){return m_lastStatus == VAD_SPEECH_NO_VOICE;}
	bool is_find_begin(){return m_bFindBegin;}
	bool is_check_finish_and_shoud_return(VAD_SPEECH_STATUS eStatus);
	bool is_check_begin(){return m_bCheckBegin;}

private:
	VadProcessor * m_detector;
	//short * vad_result;
	unsigned int vad_len;
	bool m_bHasFull;				//是否已经缓存区满
	bool m_bFindBegin;				//是否已经检测到起点
	bool m_bFindEnd;				//是否已经检测到末端
	bool m_bCheckBegin;				//是否已经开启端点检测
	bool m_bStopWhenNoFindStart;
	bool m_bStopWhenFindEnd;
	VAD_SPEECH_STATUS m_lastStatus;	//上次检测的状态

	int nBeginPos;
	int nEngPos;
    bool m_bEnable;
};


#endif