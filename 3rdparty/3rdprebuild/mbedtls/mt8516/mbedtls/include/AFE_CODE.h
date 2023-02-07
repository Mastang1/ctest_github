#ifndef _AFE_CODE_H
#define _AFE_CODE_H

typedef enum _AFE_CODE
{
		AFE_OK=0,
		AFE_NOT_SUPPORTED=-100,
		AFE_NOT_INITIALIZED,    //初始化失败
		AFE_NO_LICNENCE,        //找不到有效的licence文件
		AFE_ERROR_PARAMETER,    //参数设置错误
		AFE_ERROR_DATA,		 //输入数据错误
		AFE_ERROR_INSUFFICIENT_BUF,		//内存不足
} AFE_CODE;

#endif