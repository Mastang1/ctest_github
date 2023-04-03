#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 *最基础的fork例子
 **/
int main(int argc, char const *argv[])
{
    pid_t pid;
    //判断1
    if ((pid=fork()) < 0)
    {
        perror("fork error");
    }
    //判断2
    else if (pid == 0)//子进程
    {
         printf("child getpid()=%d\n", getpid());
    }
    //判断3
    else if(pid > 0)//父进程
    {
        printf("parent getpid()=%d\n", getpid());
    }
    printf("\nthis fun will be execute twice!\n");
    return 0;
}