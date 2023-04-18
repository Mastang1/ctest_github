/**
 *  step1. uart received data, and save them to tmp buffer,which always are XX;
 *  step2. call qringuffer.canwrite(),tmp buffer must big enough, and then called write();
 *  step3. on loop, 10ms,read data;if no , break current status;
*/
#include <stdio.h>
#include "pthread.h"
#include "QRingBuffer.hpp"
#include <string.h>
#include "sys/time.h" //some function for time process
#include <unistd.h>

using namespace typ::common;

QRingBuffer gl_ring_buffer(1024);
int gl_runing = 1;

void * data_sender(void * arg);
void * data_receiver(void *arg);

int main()
{
    gl_runing = 1;
    pthread_t sender;
    pthread_t receiver;

    if(pthread_create(&sender, NULL, data_sender, NULL) != 0){
        printf(" \n -- error.\n");
        _exit(1);
    }
    // sleep(1);
    if(pthread_create(&receiver, NULL, data_receiver, NULL) != 0){
        printf(" \n -- error.\n");
        _exit(1);
    }
    
    pthread_join(sender, NULL);
    pthread_join(receiver, NULL);

    

    return 0;
}

void * data_sender(void * arg)
{
    char send_buffer[100]="";

    for(int i=0; i<10;i++){
        memset(send_buffer, 'A'+i, 100);
        if(gl_ring_buffer.canWrite() > 100){
            gl_ring_buffer.write(send_buffer, 100);
            printf(" \n -- write 100 bytes.\n");
        }else{
            printf(" -- current ringbuffer is not enough.\n");
            sleep(2);
        }
        usleep(100*1000);
    }
    sleep(2);
    gl_runing = 0;
}

void * data_receiver(void *arg)
{
    char receive_buffer[120] = "";
    while (gl_runing)
    {
        if(gl_ring_buffer.canRead() >= 25){
            gl_ring_buffer.read(receive_buffer, 25);
            printf(" \n -- read 25 bytes.\n");
            for(int i=0;i<100;i++){
                printf("%c ", receive_buffer[i]);
            }
            printf("\n -- end \n");
        }else{
            printf(" receive enough.\n");
            usleep(100*1000);
        }
        usleep(10*1000);
    }

}