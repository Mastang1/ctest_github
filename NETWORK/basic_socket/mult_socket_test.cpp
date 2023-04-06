#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>


#define MAXLINE 80							//最大数据长度
#define SERV_PORT 6666						//服务器端口号


int main(void)
{
	struct sockaddr_in servaddr, cliaddr; 	//定义服务器与客户端地址结构体
	socklen_t cliaddr_len; 					//客户端地址长度
	int listenfd = 0;
    int ret = 0;

    while(listenfd >= 0){
        listenfd = socket(AF_INET, SOCK_STREAM, 0);
        printf("current socket FD is %d\n", listenfd);
        int socket_code = 0, code = 0;
        socklen_t socket_code_size = sizeof(socket_code);

        ret = getsockopt(listenfd, SOL_SOCKET, SO_ERROR, &socket_code, &socket_code_size);
        printf(" -- getsockopt return val is %d, and error code is %d", ret,socket_code);
        

        //初始化服务器端口地址
        bzero(&servaddr, sizeof(servaddr));	//将服务器端口地址清零
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(SERV_PORT);
        //将套接字文件与服务器端口地址绑定
        bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));//tang在这里强制转换sockaddr_in 类型 为sockaddr类型，两个类型所表示空间大小一致
        //监听，并设置最大连接数为20
        listen(listenfd, 20);

    }

	return 0;
}


