#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>


#define MAXLINE 10240							//最大数据长度
#define SERV_PORT 6666						//服务器端口号


int main(void)
{
	struct sockaddr_in servaddr, cliaddr; 	//定义服务器与客户端地址结构体
	socklen_t cliaddr_len; 					//客户端地址长度
	int listenfd, connfd;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	int i, n;
	//创建服务器端套接字文件
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("current socket FD is %d", listenfd);
	//初始化服务器端口地址
	bzero(&servaddr, sizeof(servaddr));	//将服务器端口地址清零
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	//将套接字文件与服务器端口地址绑定
	bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));//tang在这里强制转换sockaddr_in 类型 为sockaddr类型，两个类型所表示空间大小一致
	//监听，并设置最大连接数为20
	listen(listenfd, 20);
	printf("Accepting connections ...\n");
	//接收客户端数据，并处理请求
	while (1) {
		printf("\n\n now, waiting client conneciting...");

		cliaddr_len = sizeof(cliaddr);
		connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
		n = recv(connfd, buf, MAXLINE, 0);

		printf("received from %s at PORT %d\n",
			inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
			ntohs(cliaddr.sin_port));

		for (i = 0; i < n; i++)
			buf[i] = toupper(buf[i]);
		send(connfd, buf, n, 0);
		//tang test
		printf("\n+++++ %s ++++\n", str);
		//关闭连接
		//close(connfd);
	}
	return 0;
}


