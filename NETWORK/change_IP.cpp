#if 1

#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <arpa/inet.h>//IP change is here
#include <ctype.h>

int main()
{
    char buf[1024] = {0};
    uint32_t *ptr = NULL;
    int ret = 0;
    socklen_t len = 0;
	  
    struct sockaddr_in addr;
    ret = inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
    if(ret == 0)
    {
            perror("enter IP error！\n");
            return 0;
    }
    else if(ret == -1)
    {
            perror("inet_pton error!\n");
            return -1;
    }
    
    ptr = (uint32_t *)(&addr.sin_addr);		
    len = sizeof(struct sockaddr_in);
    printf("ptr:%x\n", ptr);
    printf("addr:%s\n", inet_ntop(AF_INET, &addr.sin_addr, buf, len));//因为调用的是指针，由于结构体中只有一个成员，可以直接用int32_t 类型的指针作为参数
    return 0;

}

#endif