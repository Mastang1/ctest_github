//别的线程在dk，此时试图加锁的线只能等待……
#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>

void *fun1(void *arg);
void *fun2(void *arg);

int buffer = 0;
pthread_mutex_t mutex;
int running = 1;

int main(void )
{
    pthread_t pt1;
    pthread_t pt2;

    pthread_mutex_init(&mutex,NULL);

    pthread_create(&pt1,NULL,fun1,(void*)&running);
    pthread_create(&pt2,NULL,fun2,(void*)&running);

    usleep(1000);
    running=0;
    pthread_join(pt1,NULL);
    pthread_join(pt2,NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}

void *fun1(void *arg)
{
    while(*(int *)arg)
    {
				pthread_mutex_lock(&mutex);
        printf("in fun1 before add , buffer is : %d\n",buffer);
        usleep(2);
        buffer++;
        printf("in fun1 after sleep and add one ,now buffer is %d \n",buffer);
				pthread_mutex_unlock(&mutex);
        usleep(2);
    }
}

void *fun2(void *arg)
{
    while(*(int *)arg)
    {
				pthread_mutex_lock(&mutex);
        printf("in fun2 before add , buffer is : %d\n",buffer);
        usleep(2);
        buffer++;
        printf("in fun2 after sleep and add one ,now buffer is %d \n",buffer);
				pthread_mutex_unlock(&mutex);
        usleep(2);
    }

}
