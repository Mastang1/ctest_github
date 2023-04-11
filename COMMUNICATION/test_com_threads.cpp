/*
 * @Author: tangyapeng tangyapeng@haier.com
 * @Date: 2023-04-11 09:41:22
 * @LastEditors: tangyapeng tangyapeng@haier.com
 * @LastEditTime: 2023-04-11 19:03:27
 * @FilePath: /ctest_gitnub/COMMUNICATION/test_com_threads.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "EVENT_WRAPPER/event_wrapper.hpp"
#include <iostream>
#include <stdio.h>
#include "unistd.h"
#include <stdarg.h>

#define SBUF_SIZE (1024)

void * thread_emit(void * arg);
void * thread_process(void * arg);
void printf_with_mutex(pthread_mutex_t * p_mutex ,const char * format, ... );

Event evt_test;
pthread_mutex_t mutex_test;
bool is_run;

int main()
{
    pthread_t pthread_sender;
    pthread_t pthread_receiver;
     
    evt_test.Reset();
    is_run = true;
    pthread_mutex_init(&mutex_test, NULL);

    pthread_create(&pthread_receiver, NULL,thread_process, NULL);
    pthread_create(&pthread_sender, NULL,thread_emit, NULL);

    pthread_join(pthread_receiver, 0);
    pthread_join(pthread_sender, 0);
    pthread_mutex_destroy(&mutex_test);

    return 0;
}


void * thread_emit(void * arg){
    for(int i=0; i<10; i++){
        usleep(500000);
        evt_test.Set();
        printf_with_mutex(&mutex_test," -- send: %d.\n", i);
    }
    is_run = false;
}

void * thread_process(void * arg)
{
    while(is_run)
    {
        evt_test.Wait();
        printf_with_mutex(&mutex_test,"   --Received \n", NULL);
    }
}


void printf_with_mutex(pthread_mutex_t * p_mutex ,const char * format, ... )
{
    pthread_mutex_lock(p_mutex);
	va_list args;
    char sbuf[SBUF_SIZE] = "";
	va_start (args, format);
	vsnprintf (sbuf,SBUF_SIZE,format, args);
	va_end (args);
	printf("%s",sbuf);		
    pthread_mutex_unlock(p_mutex);
}