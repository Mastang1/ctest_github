//version 2.0 by wangxiaofei @2012
#ifndef _TAGC_H
#define _TAGC_H

/*
#define BUILDDLL
#ifdef BUILDDLL 
#define _LINKDLL     __declspec(dllexport) 
#else 
#define _LINKDLL     __declspec(dllimport) 
#endif
*/
typedef struct TAGCParameters_
{
	void* agc_st;
	short frame_size;
	int   analog_capture_level_;
	int	  saturation_warning_;
//	TAgc_config_t agcConfig;
}TAGCParameters;

typedef enum _TAGC_CODE
{
		TAGC_OK=0,
		TAGC_NOT_SUPPORTED=-100,
		TAGC_NOT_INITIALIZED,    //初始化失败
		TAGC_NO_LICNENCE,        //找不到有效的licence文件
		TAGC_ERROR_PARAMETER,    //参数设置错误
		TAGC_ERROR_DATA,		 //输入数据错误
		TAGC_ERROR_INSUFFICIENT_BUF,		//内存不足
} TAGC_CODE;


TAGCParameters *TAGC_Init(TAGC_CODE *return_code, int sample_rate, int frame_length);

TAGC_CODE TAGC_Process(TAGCParameters* st, short *data_in, short *data_out, int agcMode);

TAGC_CODE TAGC_Exit(TAGCParameters* st);

TAGC_CODE TAGC_SetParameter(TAGCParameters* st, char *ParaName, char *ParaVal);

#endif
