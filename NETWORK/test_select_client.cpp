#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define SERV_IP "127.0.0.1"  //客户端、服务端都在一台主机上，所以直接用本机IP地址
#define SERV_PORT 6666

int main()
{
   int cfd;
   struct sockaddr_in serv_addr;
   char buf[BUFSIZ];
   int n;

   cfd=socket(AF_INET,SOCK_STREAM,0);
   
   memset(&serv_addr,0,sizeof(serv_addr));
   serv_addr.sin_family=AF_INET;
   serv_addr.sin_port=htons(SERV_PORT);
   inet_pton(AF_INET,SERV_IP,&serv_addr.sin_addr.s_addr);  //将点十进制字节串转换为网络字节序

   connect(cfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

    while(1)
    {
        printf("Please input a string ...\n");
        fgets(buf,sizeof(buf),stdin);
        write(cfd,buf,strlen(buf));
        n=read(cfd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,n);
    }
   close(cfd);

   return 0;
}
