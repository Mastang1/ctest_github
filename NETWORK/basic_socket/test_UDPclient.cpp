#if 0
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <ctype.h>
#define MAXLINE 80
#define SERV_PORT 6666
int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	int sockfd, n;
	char buf[MAXLINE];
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);
	//发送数据到客户端
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr,
			sizeof(servaddr));
		if (n == -1)
			perror("sendto error");
		//接收客户端返回的数据
		n = recvfrom(sockfd, buf, MAXLINE, 0, NULL, 0);
		if (n == -1)
			perror("recvfrom error");
		//将接收到的数据打印到终端
		send(STDOUT_FILENO, buf, n, 0);
		printf("\n%s\n", buf);
	}
	close(sockfd);
	return 0;
}
#endif


#if 1
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <ctype.h>
#include <errno.h>

#define MAXLINE 80
#define SERV_PORT 6666
#define CLIENT_PORT 6667

int main(int argc, char *argv[])
{
	int sockfd, n;
	char buf[MAXLINE];
    int flag = 1;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(int)) < 0) {
        printf("Udp channel setsockop(%d)t with reuse failed:%s", sockfd, strerror(errno));
        return -1;
    }
	/* create server address info */
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);

	/*create client address info*/
	struct sockaddr_in client_addr;
	bzero(&client_addr, sizeof(client_addr));
	servaddr.sin_family = AF_INET;
	// if(0 == inet_pton(AF_INET, "127.0.0.1", &client_addr.sin_addr)){
	// 	printf(" -- current IP address error.\n");
	// 	return -1;
	// }
	servaddr.sin_port = htons(CLIENT_PORT);
	if(-1 == bind(sockfd, (struct sockaddr *)&client_addr,sizeof(struct sockaddr_in))){
		printf(" -- client bind to IP %#x   error.\n", client_addr.sin_addr);
		return -1;
	}

	//发送数据到server
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr,sizeof(servaddr));
		if (n == -1)
			perror("sendto error");

		// waiting 接收客户端返回的数据
		n = recvfrom(sockfd, buf, MAXLINE, 0, NULL, 0);
		if (n == -1)
			perror("recvfrom error");
		//printf recv data
		send(STDOUT_FILENO, buf, n, 0);
		printf("\n%s\n", buf);
	}
	close(sockfd);
	return 0;
}
#endif

