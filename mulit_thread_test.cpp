#if 0
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

 void *thread_function(void *arg) {

  int i;

  for ( i=0; i<20; i++) {
    printf("Loop pth %d!\n",i*100);
    sleep(1);
  }

  return NULL;
}

//thread creat successful, return 0 ;
int main(void) {
  pthread_t mythread;
   
  if ( pthread_create( &mythread, NULL, thread_function, NULL) ) {
    printf("error creating thread.");
    abort();
  }
  if ( pthread_join ( mythread, NULL ) ) {
    printf("error joining thread.");
    abort();
  }
  exit(0);
}
/*
pthread_create(&pthread_t , NULL , &fun , NULL(argument) );
pthread_join(pthread_t x, NULL);    return 0; successful

*/

#endif

//##########################################################

#if 0

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int myglobal;
pthread_mutex_t mymutex=PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg) {
    int i,j;
	for ( i=0; i<20; i++) {
		pthread_mutex_lock(&mymutex);
		j=myglobal;
		j=j+1;
		printf(".");
		fflush(stdout);
		sleep(1);
		myglobal=j;
		pthread_mutex_unlock(&mymutex);
	}
	return NULL;
}



int main(void) {
	pthread_t mythread;
	int i;
	if ( pthread_create( &mythread, NULL, thread_function, NULL) ) {
		printf("error creating thread.");
		abort();
	}
  for ( i=0; i<20; i++) {
    pthread_mutex_lock(&mymutex);
    myglobal=myglobal+1;
    pthread_mutex_unlock(&mymutex);
    printf("o");
    fflush(stdout);
    sleep(1);
  }
  if ( pthread_join ( mythread, NULL ) ) {
		printf("error joining thread.");
		abort();
  }
  printf("\nmyglobal equals %d\n",myglobal);
  exit(0);
}

#endif
//============================================================

#if 1
/* *************************************************************
condition mutex queue
* **************************************************************
*/
#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "os_adapter.hpp"
#include <sys/types.h>
using namespace std;

Event event_1to2;
Event event_2to3;

 void *threadFunProducer(void *arg) 
{
  int i;
  for (i=0;i<4;i++) {
    printf("\n###### 01");
  usleep(500000);
  }
  event_1to2.Set();
  return NULL;
}


 void *threadFunConsumer(void *arg) 
{
  int i;

  event_1to2.Wait();
  for (i=0;i<10;i++) {
    printf("\n******** 02");
    sleep(1);
  }
  event_2to3.Set();
  return NULL;
}

 void *threadFunConsumer2(void *arg) 
{
  int i;

  event_2to3.Wait();
  for (i=0;i<10;i++) {
    printf("\n@@@@@@@@ 03");
    sleep(2);
  }
  return NULL;
}

//thread creat successful, return 0 ;
int main(void) {
  pthread_t pth_producer;
  pthread_t pth_consumer;
  pthread_t pth_consumer2;
  
  event_2to3.Reset();
  event_1to2.Reset();

  if ( pthread_create( &pth_producer, NULL, threadFunProducer, NULL) ) {
    printf("error creating thread.");
    abort();
  }
  if ( pthread_create( &pth_consumer, NULL, threadFunConsumer, NULL) ) {
    printf("error creating thread.");
    abort();
  }  
  if ( pthread_create( &pth_consumer2, NULL, threadFunConsumer2, NULL) ) {
    printf("error creating thread.");
    abort();
  } 

/**
 * @brief ************ test current thread ID 
 * 
 */
  
    char tmp_strID[20];
    sprintf(tmp_strID, "%d", (int32_t)gettid());
    printf("\n%s\n\n", tmp_strID);
sleep(6);
    string str_ps_cmd;
    str_ps_cmd.append("ps -ef |grep ");
    str_ps_cmd.append(tmp_strID);
    

    cout<<str_ps_cmd<<endl;
    

    int rslt = 0;
    rslt = system(str_ps_cmd.c_str());      //可以返回当前进行工作目录下的项目个数
    printf("return value is : %s", rslt);

  sleep(60);








  //线程自动退出
  if ( pthread_join ( pth_producer, NULL ) ) {
    printf("error joining thread.");
    abort();
  }

  if ( pthread_join ( pth_consumer, NULL ) ) {
  printf("error joining thread.");
  abort();
}
    if ( pthread_join ( pth_consumer2, NULL ) ) {
  printf("error joining thread.");
  abort();
}


  exit(0);
}
/*
pthread_create(&pthread_t , NULL , &fun , NULL(argument) );
pthread_join(pthread_t x, NULL);    return 0; successful

*/

#endif

