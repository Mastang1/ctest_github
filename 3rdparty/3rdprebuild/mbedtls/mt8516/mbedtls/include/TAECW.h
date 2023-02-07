#ifndef _TAECW_H
#define _TAECW_H


#include "aec_core.h"
// #define BUILDDLL
// 
// #ifdef BUILDDLL 
// #define _LINKDLL     __declspec(dllexport) 
// #else 
// #define _LINKDLL     __declspec(dllimport) 
// #endif

struct TAECWParameters_;
typedef struct TAECWParameters_ TAECWParameters;


typedef enum _TAECW_CODE
{
	    TAECW_OK=0,
		TAECW_NOT_SUPPORTED=-100,
		TAECW_NOT_INITIALIZED,    //��ʼ��ʧ��
		TAECW_NO_LICNENCE,        //�Ҳ�����Ч��licence�ļ�
		TAECW_ERROR_PARAMETER,    //�������ô���
		TAECW_ERROR_DATA,		 //�������ݴ���
		TAECW_ERROR_INSUFFICIENT_BUF,		//�ڴ治��
} TAECW_CODE;


/*
TAECWParameters*    TAECW_Init(
							TAECW_CODE* return_code,
							int sample_rate,
							int frame_length,
							short MODE_SELECT
							);
*/
TAECWParameters*    TAECW_Init(
							   TAECW_CODE* return_code,
							   int sample_rate,
							   int frame_length
							);
/*
TAECW_CODE  TAECW_Process (
							 TAECWParameters* st,
							 short *data_in,
							 short *reference_in,
							 short *data_out,
							 short *output_adapt
							 );
							 */
TAECW_CODE  TAECW_Process (
						   TAECWParameters* st,
						   short *data_in,
						   short *reference_in,
						   short *data_out,
						   //short *output_adapt,
						   short MODE_SELECT
						   );

TAECW_CODE  TAECW_Exit(TAECWParameters* st);


TAECW_CODE  TAECW_SetParameter(
								TAECWParameters* st,
								char *paraName, 
								char *paraVal
								);

/*
TAECW_CODE  TAECW_GetParameter(
								TAECWParameters* st,
								char *paraName, 
								char *buf
								 ); 

*/



#endif