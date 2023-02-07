#ifndef Tvqe_Java
#define Tvqe_Java

#ifdef __cplusplus
extern "C" {
#endif

#define 	VC_LEFT_MIC	//VC0358��LEFT MIC,RIGHT REF
#define COMM  0               // ͨ��ģʽ
#define VR    1              // ʶ��ģʽ
//SN226D��LEFT REF,RIGHT MIC
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

_LINKDLL int TVqe_Java_Init(int sampleRate,    //������Hz
							int aec_mode,
                            int mic_num,    //MICͨ����
                            int ref_num,    //�ο�ͨ����
                            int out_num    //���ͨ����
                            );
//TNS_Mode������ȡֵ��Χ 0---3
_LINKDLL int TVqe_Java_Set_Parameter(char* param_name,   //��������
                                     char* param_value    //����ֵ
                                     );
_LINKDLL int TVqe_Java_Process(short *in_buf_mic, //MICͨ������
                               short *in_buf_ref,  //�ο�ͨ������
                               short *output_buf, //���ͨ������
                               int aec_mode     //AECģʽ:����ȡCOMM(ͨ�ţ���VR��ʶ������ģʽ
                               );
_LINKDLL int TVqe_Java_Free(void);
_LINKDLL int TVqe_Java_Get_Version(char *versionStr, short length);

#ifdef __cplusplus
}
#endif

#endif

