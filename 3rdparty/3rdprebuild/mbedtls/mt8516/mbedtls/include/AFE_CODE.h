#ifndef _AFE_CODE_H
#define _AFE_CODE_H

typedef enum _AFE_CODE
{
		AFE_OK=0,
		AFE_NOT_SUPPORTED=-100,
		AFE_NOT_INITIALIZED,    //��ʼ��ʧ��
		AFE_NO_LICNENCE,        //�Ҳ�����Ч��licence�ļ�
		AFE_ERROR_PARAMETER,    //�������ô���
		AFE_ERROR_DATA,		 //�������ݴ���
		AFE_ERROR_INSUFFICIENT_BUF,		//�ڴ治��
} AFE_CODE;

#endif