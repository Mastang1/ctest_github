#ifndef _SOUNDCONNECT_VOICEAI_MESSAGE_H_
#define _SOUNDCONNECT_VOICEAI_MESSAGE_H_

#ifdef __cplusplus 
extern "C"
{ 
#endif

typedef struct SCVAICallBackMessageWakeup{
	int who;
	float angle;
}SCVAICallBackMessageWakeup;

typedef struct SCVAICallBackMessage{
	int messageSource;//message sender, 100-buder 
	
	int type ; //回调消息分类
	int value; //回调消息分类后的取值
	void *content;//回调消息中的内容，对应不同回调消息，内容不同
	int contentLen;//content中数据长度
	
	void *contentUrl;//对于音乐搜索时，音乐的URL
	int contentUrlLen;//contentUrl的长度
	int contentValue;//理解结果是否是music
	void *command;//回调消息返回的理解指令 目前只支持音乐服务的"Play" "Stop" "Continue"
}SCVAICallBackMessage;

typedef int (*SoundConnectVoiceAI_CallBack)(SCVAICallBackMessage *message);

/*
 * "type" and "value" of callback-message "SCVAICallBackMessage"	
*/
typedef enum SCVAICallBackMessageType{
	//for SDK
	SCVAICallBackMessageTypeWakeup = 1,
	SCVAICallBackMessageTypeOther = 10,//for other functions

	//for Interaction
	SCVAICallBackMessageTypeInit = 0,
	SCVAICallBackMessageTypeASR = 2,
	SCVAICallBackMessageTypeTTS = 3,
	SCVAICallBackMessageTypeService = 4,
	SCVAICallBackMessageTypeReadyAudio = 5,
	SCVAICallBackMessageTypeServiceUnderstanding = 6,//content after understanding, not used now
	SCVAICallBackMessageTypeFinal = 7,//
	
}SCVAICallBackContentType;

//for SDK start
typedef enum SCVAICallBackMessageTypeWakeupValue{
	SCVAICallBackMessageTypeWakeupValueSuccess    = 0,
	SCVAICallBackMessageTypeWakeupValueData       = 1,
	SCVAICallBackMessageTypeWakeupValueColdWUFail = -1,
	SCVAICallBackMessageTypeWakeupValueError      = -2,
	SCVAICallBackMessageTypeWakeupValueUnknown    = -10,
}SCVAICallBackMessageTypeWakeupValue;

typedef enum SCVAICallBackMessageTypeOtherValue{
	SCVAICallBackMessageTypeOtherValueOneshot = 0,
	SCVAICallBackMessageTypeOtherValueEnergy  = 1,
	SCVAICallBackMessageTypeOtherValueAsrdata = 2,
}SCVAICallBackMessageTypeOtherValue;
//for SDK end

//for Interaction start
typedef enum SCVAICallBackMessageTypeInitValue{
	SCVAICallBackMessageTypeInitValueSuccess = 0,
	SCVAICallBackMessageTypeInitValueError   = -1,
}SCVAICallBackMessageTypeInitValue;


typedef enum SCVAICallBackMessageTypeTTSValue{
	SCVAICallBackMessageTypeTTSValueBegin = 0,
	SCVAICallBackMessageTypeTTSValueFlushData = 1,
	SCVAICallBackMessageTypeTTSValueFinish = 2,
}SCVAICallBackMessageTypeTTSValue;

typedef enum SCVAICallBackMessageTypeASRValue{
	SCVAICallBackMessageTypeASRValueInit      = 0,
	SCVAICallBackMessageTypeASRValueStart     = 1,
	SCVAICallBackMessageTypeASRValueVadEnd    = 2,
	SCVAICallBackMessageTypeASRValueFlushData = 3,
	SCVAICallBackMessageTypeASRValueFinish    = 4,
	SCVAICallBackMessageTypeASRValueMeterLevel= 5,
	SCVAICallBackMessageTypeASRValueCancel    = 6,
    //SCVAICallBackMessageTypeASRValueError   = 7,// 鍙戠敓閿欒
    SCVAICallBackMessageTypeASRValueUnknown = 8,// 鍙戠敓閿欒
}SCVAICallBackMessageTypeASRValue;

typedef enum SCVAICallBackMessageTypeFinalValue{
	SCVAICallBackMessageTypeFinalValueSDKFinish  = 0x1000,
	SCVAICallBackMessageTypeFinalValueSDKError,
	SCVAICallBackMessageTypeFinalValueRegisterError,
	SCVAICallBackMessageTypeFinalValueWakeupError,
	SCVAICallBackMessageTypeFinalValueASRError,
	SCVAICallBackMessageTypeFinalValueTTSError ,
	SCVAICallBackMessageTypeFinalValueDUMIServerError,
	SCVAICallBackMessageTypeFinalValueErrorOther,
}SCVAICallBackMessageTypeFinalValue;
//for Interaction end


#ifdef __cplusplus 
}
#endif

#endif
