/**
 * @file test_net_address_fun.cpp
 * @author your name (you@domain.com)
 * @brief  To test sockaddr and sockaddr_in, and other functions
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>

int main(int argc,char **argv)
{
    int sockfd = 0;
    struct sockaddr_in addr_in;
    struct sockaddr * addr;
 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);  
    bzero(&addr_in,sizeof(addr_in)); 
    /*
     8008的主机字节序  小端字节序 0001 1111 0100 1000 = 8008
     8008的网络字节序  大端字节序 0100 1000 0001 1111 = 18463
    */
    addr_in.sin_port = htons(8008);
    addr_in.sin_family = AF_INET;  // 设置地址家族
    addr_in.sin_addr.s_addr = inet_addr("192.168.3.30");  //设置地址***wrap两层

    printf("sockaddr_in.sin_addr.s_addr = %d \n", addr_in.sin_addr.s_addr);
    printf("addr = %s \n", inet_ntoa(addr_in.sin_addr));
//    addr_in.sin_addr.s_addr = htonl(INADDR_ANY);  //设置地址
 
    printf("struct sockaddr size = %ld \n", sizeof (addr));
    printf("struct sockaddr_in size = %ld \n", sizeof (addr_in));
    addr = (struct sockaddr *)&addr_in;
//    bind(sockfd, (struct sockaddr *)&addr_in, sizeof(struct sockaddr));  /* bind的时候进行转化 */
    bind(sockfd, addr, sizeof(struct sockaddr));

    return 0;
}

/*
htons()作用是将端口号由主机字节序转换为网络字节序的整数值。(host to net)

inet_addr()作用是将一个IP字符串转化为一个网络字节序的整数值，用于sockaddr_in.sin_addr.s_addr。

inet_ntoa()作用是将一个sin_addr结构体输出成IP字符串(network to ascii)。比如：

printf("%s",inet_ntoa(mysock.sin_addr));

htonl()作用和htons()一样，不过它针对的是32位的（long），而htons()针对的是两个字节，16位的（short）。

与htonl()和htons()作用相反的两个函数是：ntohl()和ntohs()。



*/

// struct sockaddr_in
//   {
//     __SOCKADDR_COMMON (sin_);    /* 解析出来就是: sin_family */
//     in_port_t sin_port;			/* Port number.  */
//     struct in_addr sin_addr;		/* Internet address.  */

//     /* Pad to size of `struct sockaddr'.  */
//     unsigned char sin_zero[sizeof (struct sockaddr)
// 			   - __SOCKADDR_COMMON_SIZE
// 			   - sizeof (in_port_t)
// 			   - sizeof (struct in_addr)];
//   };