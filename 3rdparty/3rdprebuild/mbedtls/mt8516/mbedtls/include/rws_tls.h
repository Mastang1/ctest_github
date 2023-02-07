#ifndef __RWS_TLS_H__
#define __RWS_TLS_H__ 1

#include "librws.h"
#include "rws_socket.h"

void* rws_tls_connect(rws_socket s, int iMaxRetry, int iRetryDelay);
int rws_tls_close(void* channel);
int rws_tls_send(void* channel, const char* pData, int iLen, int* err);
int rws_tls_recv(void* channel, char* pBuf, int iBufLen, int* err);

#endif  // __RWS_TLS_H__
