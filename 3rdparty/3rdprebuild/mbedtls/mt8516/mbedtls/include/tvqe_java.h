#ifndef Tvqe_Java
#define Tvqe_Java

#ifdef __cplusplus
extern "C" {
#endif

#define 	VC_LEFT_MIC	//VC0358：LEFT MIC,RIGHT REF
#define COMM  0               // 通信模式
#define VR    1              // 识别模式
//SN226D：LEFT REF,RIGHT MIC
//#define	ANDROID_LOG
#ifdef ANDROID_LOG
#include <android/log.h>
#define jprintf(x, y...) __android_log_print(ANDROID_LOG_INFO, "TVQE", x" %s, %d\n", ##y, __FILE__, __LINE__)
#else
#define jprintf printf
#endif // jprintf

//#define BUILDDLL

#ifdef BUILDDLL 
#define _LINKDLL     __declspec(dllexport) 
#else 
#define _LINKDLL     //__declspec(dllimport) 
#endif

_LINKDLL int TVqe_Java_Init(int sampleRate,    //采样率Hz
							int aec_mode,
                            int mic_num,    //MIC通道数
                            int ref_num,    //参考通道数
                            int out_num    //输出通道数
                            );
//TNS_Mode参数的取值范围 0---3
_LINKDLL int TVqe_Java_Set_Parameter(char* param_name,   //参数名称
                                     char* param_value    //参数值
                                     );
_LINKDLL int TVqe_Java_Process(short *in_buf_mic, //MIC通道缓存
                               short *in_buf_ref,  //参考通道缓存
                               short *output_buf, //输出通道缓存
                               int aec_mode     //AEC模式:可以取COMM(通信）和VR（识别）两个模式
                               );
_LINKDLL int TVqe_Java_Free(void);
_LINKDLL int TVqe_Java_Get_Version(char *versionStr, short length);

#ifdef __cplusplus
}
#endif

#endif

