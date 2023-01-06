#if 1

/**
 * @file get_threadID_from_processID.cpp
 * @author tangyp
 * @brief test demo: to monitor all threads in process
 * 1. read infomation to memory
 * 2. get line number 
 * @version 0.1
 * @date 2022-12-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "os_adapter.hpp"
#include <sys/types.h>
#include <algorithm>

using namespace std;

void *task_01(void *arg)
{
    while(1)
    {
        printf("task 01\n");
        usleep(1000*1000);
    }
    return NULL;
}

void *task_02(void *arg)
{
    while(1){
        printf("task 02\n");
        usleep(1000*500);
    }
    return NULL;
}

void *task_03(void *arg)
{
    while(1){
        printf("task 03\n");
        usleep(1000*2000);
    }
    return NULL;
}


int main()
{
    pthread_t pth_task01;
    pthread_t pth_task02;
    pthread_t pth_task03;


    if ( pthread_create( &pth_task01, NULL, task_01, NULL) ) {
        printf("error creating thread.");
        abort();
    }

    if ( pthread_create( &pth_task02, NULL, task_02, NULL) ) {
        printf("error creating thread.");
        abort();
    }  

    if ( pthread_create( &pth_task03, NULL, task_03, NULL) ) {
        printf("error creating thread.");
        abort();
    }  





    char tmp_strID[20];
    sprintf(tmp_strID, "%d", (int32_t)gettid());
    printf("\n%s\n\n", tmp_strID);
    string str_ps_cmd;


    str_ps_cmd.append("ps -T -p ");
    str_ps_cmd.append(tmp_strID);

    cout<<"\nCurrent command is :"<<str_ps_cmd<<endl;
    
    char ret[1024] = {0};
	FILE *fp;

	fp = popen(str_ps_cmd.c_str(),"r");

	//size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);
	int nread = fread(ret,1,1024,fp);
    pclose(fp);
	printf("read ret %d byte,\n%s\n",nread,ret);


    /**
     * @brief =====start to deal with string
     * 
     * UID          PID    PPID     LWP  C NLWP STIME TTY      STAT   TIME CMD
        tang      934750  343455  934750  0    4 10:26 pts/3    Sl+    0:00 ./get_threadID_from_processID
        tang      934750  343455  934751  0    4 10:26 pts/3    Sl+    0:00 ./get_threadID_from_processID

     */
    string str_rslt(ret);
    int line_count = count(str_rslt.begin(),str_rslt.end(), '\n');

    cout<<"\n the number of threads is :"<<line_count-1<<endl;

  //线程自动退出
    if ( pthread_join ( pth_task01, NULL ) ) {
        printf("error joining thread.");
        abort();
    }

    if ( pthread_join ( pth_task02, NULL ) ) {
        printf("error joining thread.");
        abort();
    }

    if ( pthread_join ( pth_task03, NULL ) ) {
        printf("error joining thread.");
        abort();
    }
    return 0;
}

#endif
























#if 0

#include <stdio.h>
#include <unistd.h>

int main(int argc ,char **argv){
	
	char ret[1024] = {0};
	FILE *fp;
    if(0 != chdir("/home/tang/tmp")){
        printf("change direction error");
        return -1;
    }
	//FILE *popen(const char *command, const char *type);
	fp = popen("ls -l","r");

	//size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);
	int nread = fread(ret,1,1024,fp);
	printf("read ret %d byte, %s\n",nread,ret);
	
	return 0;
}


#endif