#ifndef _SOUNDCONNECT_VOICEAI_H_
#define _SOUNDCONNECT_VOICEAI_H_

#ifdef __cplusplus 
extern "C"
{ 
#endif

#include "my_fifo.h"
#include "debugLog.h"
#include "SoundConnectVoiceAIType.h"
#include "SoundConnectVoiceAIMessage.h"

typedef struct SCVAIReadyAudio_{
	int isValid ;//二次确认数据是否可用。SDK内部使用
	int isFinished ;//二次确认数据已经处理完毕。SDK内部使用
	int isWakeup ;//确认唤醒成功，回调时有效。
	char * buf ;//数据buffer
	int buflen;//数据长度
	int isZero ;//SDK内部使用
}SCVAIReadyAudio;

//define the error code of common usage
typedef enum SoundConnectVoiceAI_WAKEUP_CONTENT_{
	SOUNDCONNECT_VOICEAI__WAKEUP_CONTENT_DOAERR = 362,
}SoundConnectVoiceAI_WAKEUP_CONTENT;

#define SOUNDCONNECT_VOICEAI_RETURN_CODE_AFE_BASE (-40)
#define SOUNDCONNECT_VOICEAI_RETURN_CODE_WAKEUP_BASE (-100)
#define SOUNDCONNECT_VOICEAI_RETURN_CODE_INTERFACE_BASE (-200)
#define SOUNDCONNECT_VOICEAI_RETURN_CODE_VAD_BASE (-300)

//define the error code of common usage
typedef enum SoundConnectVoiceAI_RETURN_CODE_COMMON_{
	SOUNDCONNECT_VOICEAI_RETURN_CODE_SUCCESS = 0,
	SOUNDCONNECT_VOICEAI_RETURN_CODE_PARAMETER_ERROR = -1,
	SOUNDCONNECT_VOICEAI_RETURN_CODE_MALLOC_ERROR = -2,
	SOUNDCONNECT_VOICEAI_RETURN_CODE_SYSTEM_UNNORMAL = -3,
	SOUNDCONNECT_VOICEAI_RETURN_CODE_NOT_SUPPORTED = -10,// not supported now
	SOUNDCONNECT_VOICEAI_RETURN_CODE_INIT_ERROR = -11,
	SOUNDCONNECT_VOICEAI_RETURN_CODE_HANDLE_ISNULL = -12,//
	SOUNDCONNECT_VOICEAI_RETURN_CODE_SHOULDNOTCALL = -13,//USER should not call this at present.
	SOUNDCONNECT_VOICEAI_RETURN_CODE_OUTSUPPOTED = -14,//support, but out of value setted
	SOUNDCONNECT_VOICEAI_RETURN_CODE_LICENSE_ERROR = -50,
}SoundConnectVoiceAI_RETURN_CODE_COMMON;

typedef enum SoundConnectVoiceAI_RETURN_CODE_{
	SOUNDCONNECT_VOICEAI_RETURN_CODE_INTERFACE_MIN = -299,
	SOUNDCONNECT_VOICEAI_RETURN_CODE_INTERFACE_MAX = -200,
	
	SOUNDCONNECT_VOICEAI_RETURN_CODE_WAKEUP_MIN = -199,
	SOUNDCONNECT_VOICEAI_RETURN_CODE_WAKEUP_MAX = -101,
	
	SOUNDCONNECT_VOICEAI_RETURN_CODE_AFE_MIN = -100,
	SOUNDCONNECT_VOICEAI_RETURN_CODE_AFE_MAX = -41,
	
	SOUNDCONNECT_VOICEAI_RETURN_CODE_WRAPPER_MIN = -40,
	SOUNDCONNECT_VOICEAI_RETURN_CODE_WRAPPER_MAX = -1,

}SoundConnectVoiceAI_RETURN_CODE;

typedef enum SoundConnectVoiceAI_SETOPT_CMD_{
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_INTERACTIONSTART=-3, //without param. notify SDK that 交互开始 同 ASRSTART
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_INTERACTIONEND  =-2, //without param. notify SDK that 交互结束 同 ASREND
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_ASRSTART =-1,      //without param. notify SDK that 识别开始
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_ASREND   =0,       //without param. notify SDK that 识别结束
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_WAKEUPSUCCESS=1,//without param. notify SDK that 唤醒成功
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_ENTERLOWPOWER=2,//without param. notify SDK that 进入低功耗. NOT SUPPORTED now.
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_EXITLOWPOWER =3, //without param. notify SDK that 退出低功耗. NOT SUPPORTED now.
	
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_SETWAKEUPSCHEDULE =20, //设定唤醒调度模式. NOT SUPPORTED now.
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_SETWAKEUPPAUSE =21, //设定唤醒调度暂停 or 恢复, 1 暂停， 0恢复
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_SETASRCALLBACK =22, //设定唤醒后数据回调,1 start, 0 stop
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_SHUTWAKEUPWORD =23, //多唤醒词时，关闭制定词。必须在初始化之前调用. int*param,[1,2]
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_SETWAKEUPDATA  =24, //设置唤醒语音前后缀，参数int[2]={prefix,suffix}
	
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_SDKDATACLEAR =29, //without param. clear the audio data for *_getData(). just active for 'SoundConnectVoiceAI_NEEDAUDIODATA_CARD' and 'SoundConnectVoiceAI_NEEDAUDIODATA_WAI'
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_DEBUG_CONTROL = 30, //with 'int* param'. DONOT call this by yourself, just set 'xxx_InitParam.DebugJustAFEWakeup" before 'xxx_create()' 
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_STARTASR = 41, //without param. NOT SUPPORTED now.
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_STARTTTS = 42, //with "const char * param" to TTS. 
	SOUNDCONNECT_VOICEAI_SETOPT_CMD_MAX=60,//enum must small than MAX
		
}SoundConnectVoiceAI_SETOPT_CMD;

typedef enum SoundConnectVoiceAI_GETOPT_CMD_{
	SOUNDCONNECT_VOICEAI_GETOPT_CMD_ASRPROSTATE=0,       //with 'int* param'. get ASR state: is recognizing(1) or idle(0)
	SOUNDCONNECT_VOICEAI_GETOPT_CMD_WAKEUPPROSTATE=1,    //with 'int* param'. WAKEUPmodule status. NOT SUPPORTED now.
	SOUNDCONNECT_VOICEAI_GETOPT_CMD_ASRISRECOGNIZING =10,//same to xxx_ASRPROSTATE
	SOUNDCONNECT_VOICEAI_GETOPT_CMD_MAX=60,//enum must small than MAX
		
}SoundConnectVoiceAI_GETOPT_CMD;

typedef enum SoundConnectVoiceAI_RESULT_STATE_{
	SOUNDCONNECT_VOICEAI_RESULT_STATE_INTERFACE_LOGIN           = 0,//账户登陆结果
	SOUNDCONNECT_VOICEAI_RESULT_STATE_INTERFACE_SLEEPING        = 1,//休眠
	SOUNDCONNECT_VOICEAI_RESULT_STATE_INTERFACE_WAKEUPSUCCESS   = 2,//唤醒
	SOUNDCONNECT_VOICEAI_RESULT_STATE_INTERFACE_RECOGNIZING     = 3,//识别中
	SOUNDCONNECT_VOICEAI_RESULT_STATE_INTERFACE_RECOGNITION_PART= 4,//识别结果中间
	SOUNDCONNECT_VOICEAI_RESULT_STATE_INTERFACE_RECOGNITION_ALL = 5,//识别结果结束
	SOUNDCONNECT_VOICEAI_RESULT_STATE_INTERFACE_UNDERSTANDING   = 6,//理解结果
	SOUNDCONNECT_VOICEAI_RESULT_STATE_INTERFACE_TTS             = 7,//合成结果
	SOUNDCONNECT_VOICEAI_RESULT_STATE_INTERFACE_SEARCH          = 8,//搜索结果
	SOUNDCONNECT_VOICEAI_RESULT_STATE_INTERFACE_PLAY            = 9,//播报结果
	//SOUNDCONNECT_VOICEAI_RESULT_STATE_MAX,		
}SoundConnectVoiceAI_RESULT_STATE;

typedef enum schedule_{
	SCHEDULE_WAKEUP2ASR_TIME_SHARING,//wakeup and ASR scheduled in dif time slice
	SCHEDULE_WAKEUP2ASR_PARALLEL,    //wakeup and ASR scheduled meanwhile/simultaneously/at the same time
}SCHEDULE;

typedef enum ASRRUNNINGSTATE_{
	ASR_RUNNING_STATE_IDLE = 0,
	ASR_RUNNING_STATE_RECOGNIZING = 1,
	ASR_RUNNING_STATE_UNDERSTANDING = 2,// NOT USED NOW, may be same as RECOGNIZING
	ASR_RUNNING_STATE_TTS = 3,          // NOT USED NOW, 
	ASR_RUNNING_STATE_SEARCHING = 4,    // NOT USED NOW, 
}ASRRUNNINGSTATE;

typedef enum {
	SoundConnectVoiceAI_NEEDAUDIODATA_NO = 0,//not need audiodata after AFE
	SoundConnectVoiceAI_NEEDAUDIODATA_CARD = 1,//need audiodata, no wakeup and interaction, just as a soundcard,
	SoundConnectVoiceAI_NEEDAUDIODATA_WAI = 2,//need audiodata, need wakeup and interaciton		
}SoundConnectVoiceAI_NEEDAUDIODATA;

extern const char * SoundConnectVoiceAI_Version;

typedef struct soundconnectVoiceAI_InitParam{
	
	//for common
	SoundConnectVoiceAI_CallBack callback;//SDK回调函数,SDK内部所有回调信息都通过此回调返回。在回调函数中要分类处理回调消息内容
	const char * filePath;//所需文件的存放路径，例如"/mnt/SDCARD/resources/"
	SoundConnectVoiceAI_NEEDAUDIODATA needAudioData;//USER获取SDK内部语音数据的模式，取值类型，见 SoundConnectVoiceAI_NEEDAUDIODATA，通常使用SoundConnectVoiceAI_NEEDAUDIODATA_WAI（数值2）即可。
	
	//for AFE
	int micNum;//阵列算法处理的麦克通道数
	int refNum; //阵列算法处理的参考通道数
	int outNum; //阵列算法处理的输出通道数，取1。	
	int AFEprofile;//阵列算法模块配置参数，使用先声给定值。为0时，SDK内部使用默认值0X30000400，非0时SDK内部使用此值。
	float MicCoor[3*8];//麦克坐标,以（x,y,z）方式，以米为单位，最多存放8通道。

	//for wakeup
	int wakeupKey;//唤醒模块热词选择。目前支持 11-Alexa、12-小爱小爱、13-小度小度
	const char *sensitivity;//唤醒词模块配合wakeupKey使用的参数。wakeupKey 取值11-13时，此值为灵敏度参数。 NULL时，SDK使用内部默认值， 非NULL时，SDK使用此值。

	//for debug
	int DebugJustAFEWakeup;//是否只开启增强算法和唤醒模块，取值0/1。暂未使用
	int DebugPrintTimeFlag;//模块是否定时打印数据缓存log信息。 取值0/1 //whether have log in thread-in-so . 1 have, 0 none;
	int DebugPrintTime10ms;//模块打印数据缓存log信息的时间间隔，以10ms为单位。例如 200，设定打印间隔为2秒。 //the time interval at 10ms of log in thread-in-so;
	int DebugSaveFile;//控制SDK内部文件保存，取值0/1。暂时未使用 //whether save file

	int scheduleMode;//SDK内部模块之间的调度模式。取值见SCHEDULE类型，暂时设定为SCHEDULE_WAKEUP2ASR_PARALLEL（数值1）。 20171018SDK中不再使用
	int flagOneshot;//oneshot 检测控制，0关闭， 1 使用VAD起点判断，2使用VAD尾点判断
	int flagASRCallback;//启动ASR数据的回调接口控制。0 关闭， 1开启

	int modeCheck ;//sel diff mode, use 0

}soundconnectVoiceAI_InitParam;

/*
	函数功能：初始化语音增强SDK相关资源。
	函数原型：
		int soundconnectVoiceAI_creat(soundconnectVoiceAI_InitParam *initParam);

	参数：
		initParam : SDK初始化参数设定。 
		参数设置见 soundconnectVoiceAI_InitParam类型。

	返回值：
		成功返回 SOUNDCONNECT_VOICEAI_RETURN_CODE_SUCCESS。
		失败返回 负值。
*/
int soundconnectVoiceAI_creat(soundconnectVoiceAI_InitParam *initParam);

/*
	函数功能：释放语音增强SDK相关资源。
	函数原型：
		int soundconnectVoiceAI_destroy();

	参数：无
	返回值：
		成功返回 SOUNDCONNECT_VOICEAI_RETURN_CODE_SUCCESS。
		失败返回 负值。
*/
int soundconnectVoiceAI_destroy();

/*
	函数功能：向语音增强SDK内部送入原始语音数据。
	函数原型：
		int soundconnectVoiceAI_putData(void *data, int length);

	参数：
		data: 存放数据缓存的首地址。
		length: 要送入数据的字节数长度。
	返回值：
		成功返回 实际存入的长度。
		失败返回 负值。
*/
int soundconnectVoiceAI_putData(void *data, int length);

/*
	函数功能：从语音增强SDK内部获取算法处理后的语音数据。
	函数原型：
		int soundconnectVoiceAI_getData(void *data, int length);

	参数：
		data: 存放数据缓存的首地址。
		length: 要获取数据的字节数长度。
	返回值：
		成功返回 实际获取的长度。
		失败返回 负值。
	*此接口目前只对 SoundConnectVoiceAI_NEEDAUDIODATA_CARD 和SoundConnectVoiceAI_NEEDAUDIODATA_WAI两种模式有效，见SoundConnectVoiceAI_NEEDAUDIODATA类型。
*/
int soundconnectVoiceAI_getData(void *data, int length);

/*
	函数功能：设置语音增强SDK信息。
	函数原型：
		int soundconnectVoiceAI_setOpt(int cmd, void *param);

	参数：
		cmd : 需要设置的命令。 取值见 SoundConnectVoiceAI_SETOPT_CMD 结构。
		param: 具体设置的内容。 参数类型和cmd对应命令保持一致。
	返回值：
		成功返回 SOUNDCONNECT_VOICEAI_RETURN_CODE_SUCCESS。
		失败返回 负值。
*/
int soundconnectVoiceAI_setOpt(int cmd, void *param);

/*
	函数功能：获取SDK信息。
	函数原型：
		int soundconnectVoiceAI_getOpt(int cmd, void *param);

	参数：
		cmd : 需要获取的命令。 取值见 SoundConnectVoiceAI_GETOPT_CMD 结构。
		param: 返回获取的内容。 参数类型和cmd对应命令保持一致。
	返回值：
		成功返回 SOUNDCONNECT_VOICEAI_RETURN_CODE_SUCCESS，param中存储获取的内容。或者 直接返回 param中的内容。
		失败返回 负值。
*/
int soundconnectVoiceAI_getOpt(int cmd, void *param);

/*
	"int setDebugControl_beforWakeUpInit(int setValue)" variable for debug wakeup. 
	--- MUST CALL before soundconnectVoiceAI_creat()
	
	0: work normally, start all modules. default
	1: wakeup but not do other shedule processes

	**have been moved into 'xxx_create()' by 'xxx_param.DebugJustAFEWakeup', USER should not call this.
*/
int setDebugControl_beforWakeUpInit(int setValue);

/*
	"int setFormatSel_beforWakeUpInit(int newFormatBits)" set the format of voiceData. 
	--- MUST CALL before soundconnectVoiceAI_creat()
	
	16: format is 16bits, so just use short.
	24: format is 24bits, so should use int and 24bits2int conversion.
	243: format is 24bits but PCMparam is U24_3LE, so should use int and 24bits2int conversion. default
*/
int setFormatSel_beforWakeUpInit(int newFormatBits);

/*
	"int setReadyAudio_beforWakeUpInit(void *buf, int length)",set audio data for 2th_wakeup_verify.
	--- MUST CALL before soundconnectVoiceAI_creat()
	
	buf: char* buffer of 1CH/16000HZ/16BIT voice data;
	length: the length of buf, is bytes. 
*/
int setReadyAudio_beforWakeUpInit(void *buf, int length);

int getDeviceSerialNo(char * bufOut);



#ifdef __cplusplus 
}
#endif

#endif
