#pragma once
#include "../doa/tssl_2.h"
#include "../doa/AFE_CODE.h"

#include "../doa/SegSSLNoHead_Code.h"



int  calculateSegSSL(short data[], int len, int micNum,float* doaMean, float* doaVar);


