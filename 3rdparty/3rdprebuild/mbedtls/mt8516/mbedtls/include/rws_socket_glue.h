#ifndef __RWS_SOCKET_GLUE_H__
#define __RWS_SOCKET_GLUE_H__ 1

#include "librws.h"
#include "rws_socket.h"


int rws_socket_glue_connect(rws_socket s, int iMaxRetry, int iRetryDelay);
int rws_socket_glue_close(rws_socket s);
int rws_socket_glue_send(rws_socket s, const char* pData, int iLen, int* err);
int rws_socket_glue_recv(rws_socket s, char* pBuf, int iBufLen, int* err);

#endif //__RWS_SOCKET_GLUE_H__