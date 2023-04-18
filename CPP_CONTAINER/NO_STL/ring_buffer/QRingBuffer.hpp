#ifndef QRINGBUFFER_H_
#define QRINGBUFFER_H_

#include "pthread.h"

namespace typ{
namespace common{


#ifndef RB_MAX_LEN
#define RB_MAX_LEN (16000*4) //2s
#endif


class QRingBuffer
{
public:
    QRingBuffer(int size = RB_MAX_LEN);
    ~QRingBuffer();

    int read(char *data, int count);  //read data frome ringbuffer
    int write(const char *data, int count);
    void clear();
    int size();
    void clearTo(int);

    int canRead();    //how much can read
    int canWrite();   //how much can write

    int bufferSize;       //buffer size
    unsigned char *rbBuf;
    /*环形缓冲区变量*/
    int rbCapacity; //容量
    unsigned char  *ptr_r;
    unsigned char  *ptr_w;
    unsigned char  *rbBuff;
    pthread_mutex_t _mutex;
};

}}

#endif /* QRINGBUFFER_H_ */
