#ifndef _FE_INTF_H_
#define _FE_INTF_H_



typedef void* HANDLE;

//#define _FINAL_RELEASE
/*typedef struct FE_HDR {
	int		nFsKHz;			//	����Ƶ�ʣ�ǧ���ȣ�
	int		nFrmMs;			//	֡�������룩
	int		nSftMs;			//	֡�ƣ����룩
	int		nMaxFrm;		//	���֡��?	int		nFtrDim;		//	����ά��
	//char	szFtrInfo[256];	//	������Ϣ		
	//char	szVersion[256];	//	�汾��Ϣ		
} FE_HDR;*/

//	������ȡģ��������
typedef enum HAIER_FE_CODE {
	FE_OK = 0,			//	ִ�гɹ�
	FE_OVERFLOW =-1,
	FE_MEM_ERR  = 1,	//	�ڴ�������
	FE_MATH_ERR = 2,	//	��ѧ�������?	FE_OVERFLOW = 3,	//	�ڴ�Խ�����?	FE_FILE_ERR = 4		//	�ļ���������
} HAIER_FE_CODE;




#ifdef __cplusplus
extern "C" {
#endif

HANDLE HAIER_OpenFE(char* cmvn_model);
//HAIER_FE_CODE RunFE( HANDLE hFE,short* pWave, int nLen, float*& pFeature,
//			  int*& pSNR, int& nFrm, bool bComp);
//HAIER_FE_CODE Run1FE( HANDLE hFE, short* pWave, float*& pFeature );
HAIER_FE_CODE HAIER_CloseFE( HANDLE hFE );
HAIER_FE_CODE HAIER_WarpFE( HANDLE hFE,float Alpha );
HAIER_FE_CODE HAIER_ResetFE( HANDLE hFE );
//HAIER_FE_CODE ContinueFE(HANDLE hFE, short* pWave, int nLen);
//HAIER_FE_CODE NormDiffFE(HANDLE hFE, float*& pFeature, int*& pSNR, int& nFrm, bool bEndflag);
//void ResetOutIdx(HANDLE hFE);

#ifdef __cplusplus
}
#endif
////	������ȡģ���ʼ������������ռ䣬���� FE_OK ��ʾ�ɹ�
//typedef HANDLE (*lpOpenFE)(	char*	szWorkDir,	//	���룺����Ŀ¼
//							FE_HDR&	feInfo		//	�����ģ�����?//							);
//
////	������ȡ���������� FE_OK ��ʾ�ɹ�
//typedef HAIER_FE_CODE (*lpRunFE)(HANDLE	hFE,			//  �������?//						   short*	pWave,			//	��������
//						   int		nLen,			//	��������
//						   float*&	pFeature,		//	��������
//						   int*&	pSNR,			//	snr ��Ϣ
//						   int&		nFrm,			//	֡��
//						   bool		bComp			//	����
//						   );
//
////	������ȡģ���˳�����������ռ�//typedef HAIER_FE_CODE (*lpCloseFE)( HANDLE hFE );
//
////new interface for VTLN Training
//
//typedef HAIER_FE_CODE (*lpWarpFE)( HANDLE hFE,float Alpha );
//
////һ���µ�������ʼǰ����֤�ڴ����?//typedef HAIER_FE_CODE (*lpResetFE)( HANDLE hFE );
//
////������������
//typedef HAIER_FE_CODE (*lpContinueFE)(HANDLE	hFE,
//								short*	pWave, 
//								int		nLen 
//								);
////�����������?//typedef HAIER_FE_CODE (*lpNormDiffFE)(HANDLE		hFE, 
//								float*&	pFeature, 
//								int*&		pSNR, 
//								int&		nFrm, 
//								bool		bEndflag 
//									 );
//


#endif
