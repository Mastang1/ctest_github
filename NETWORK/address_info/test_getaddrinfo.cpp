/* Extension from POSIX.1:2001.  */

// struct addrinfo
// {
//   int                   ai_flags;			/* Input flags.  */
//   int                   ai_family;		    /* Protocol family for socket.  */
//   int                   ai_socktype;		/* Socket type.  */
//   int                   ai_protocol;		/* Protocol for socket.  */
//   socklen_t             ai_addrlen;		    /* Length of socket address.  */
//   struct sockaddr       *ai_addr;	        /* Socket address for socket.  */
//   char                  *ai_canonname;		/* Canonical name for service location.  */
  
//   struct addrinfo       *ai_next;	        /* Pointer to next in list.  */
// }

/*
关于hosts protocol等的一些定义, 服务 和 端口一般是绑定的，采用的协议也是一定的。
    #define	_PATH_HEQUIV		"/etc/hosts.equiv"
    #define	_PATH_HOSTS		"/etc/hosts"
    #define	_PATH_NETWORKS		"/etc/networks"
    #define	_PATH_NSSWITCH_CONF	"/etc/nsswitch.conf"
    #define	_PATH_PROTOCOLS		"/etc/protocols"
    #define	_PATH_SERVICES		"/etc/services"
*/

#if 0
/* new copy*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <sys/timeb.h>
#include <sys/time.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
 
#define BUF_SIZE 500
 
int main(int argc, char **argv)
{
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int sfd, s;
    struct sockaddr_storage peer_addr;
    socklen_t peer_addr_len;
    ssize_t nread;
    char buf[BUF_SIZE];
 
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(EXIT_FAILURE);
    }
 
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
    hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
    hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
    hints.ai_protocol = 0;          /* Any protocol */
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;
    /*
 extern int getaddrinfo (const char *__restrict __name,
			const char *__restrict __service,
			const struct addrinfo *__restrict __req,
			struct addrinfo **__restrict __pai);
    */
    s = getaddrinfo(NULL, argv[1], &hints, &result);    /*返回的是链表头结点*/
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }
 



    /*
    链表查询
    getaddrinfo() returns a list of address structures.
    Try each address until we successfully bind(2).
    If socket(2) (or bind(2)) fails, we (close the socket
    and) try the next address. 
    */
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        printf("lookup result... Print:\n");
        printf("Current ai_protocol:%d",rp->ai_protocol);

        sfd = socket(rp->ai_family, rp->ai_socktype,
                rp->ai_protocol);
        if (sfd == -1)
            continue;
 
        if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
            break;                  /* Success ,quit*/
 
        close(sfd);
        
    }
 
    freeaddrinfo(result);           /* No longer needed */
 
    if (rp == NULL) {               /* No address succeeded */
        fprintf(stderr, "Could not bind\n");
        exit(EXIT_FAILURE);
    }
 
    /* Read datagrams and echo them back to sender. */
 
    for (;;) {
        peer_addr_len = sizeof(peer_addr);
        nread = recvfrom(sfd, buf, BUF_SIZE, 0,
                (struct sockaddr *) &peer_addr, &peer_addr_len);
        if (nread == -1)
            continue;               /* Ignore failed request */
 
        char host[NI_MAXHOST], service[NI_MAXSERV];
 
        s = getnameinfo((struct sockaddr *) &peer_addr,
                        peer_addr_len, host, NI_MAXHOST,
                        service, NI_MAXSERV, NI_NUMERICSERV);
        if (s == 0)
            printf("Received %zd bytes from %s:%s\n",
                    nread, host, service);
        else
            fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));
 
        if (sendto(sfd, buf, nread, 0,
                    (struct sockaddr *) &peer_addr,
                    peer_addr_len) != nread)
            fprintf(stderr, "Error sending response\n");
    }
 
    return 0;
}

#endif

/**
 * @file test_getaddrinfo.cpp
 * @author your name (you@domain.com)
 * @brief   包含域名解析等功能，可以输出套接字的结构体信息
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <sys/timeb.h>
#include <sys/time.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
 
#define BUF_SIZE 500
 
int main(int argc, char **argv)
{
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int sfd, s;
    struct sockaddr_storage peer_addr;
    socklen_t peer_addr_len;
    ssize_t nread;
    char buf[BUF_SIZE];
 
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(EXIT_FAILURE);
    }
 
    memset(&hints, 0, sizeof(hints));
    // hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
    // hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
    // hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
    // hints.ai_protocol = 0;          /* Any protocol */
    // hints.ai_canonname = NULL;
    // hints.ai_addr = NULL;
    // hints.ai_next = NULL;
    /*
 extern int getaddrinfo (const char *__restrict __name,
			const char *__restrict __service,
			const struct addrinfo *__restrict __req,
			struct addrinfo **__restrict __pai);
    */
    s = getaddrinfo("www.baidu.com", NULL, &hints, &result);    /*返回的是链表头结点*/
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }
 



    /*
    链表查询
    getaddrinfo() returns a list of address structures.
    Try each address until we successfully bind(2).
    If socket(2) (or bind(2)) fails, we (close the socket
    and) try the next address. 
    */
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        printf("lookup result... Print:\n");
        printf("Current ai_protocol:%d\n",rp->ai_protocol);//6 is tcp
        struct sockaddr_in *s_addr_in = (struct sockaddr_in *)rp->ai_addr;
        printf("Current host address is %s\n\n",inet_ntoa(s_addr_in->sin_addr));//

        sfd = socket(rp->ai_family, rp->ai_socktype,rp->ai_protocol);
        if (sfd == -1)
            continue;
 
        if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
            break;                  /* Success ,quit*/
 
        close(sfd);
        
    }
 
    freeaddrinfo(result);           /* No longer needed */
 
    if (rp == NULL) {               /* No address succeeded */
        fprintf(stderr, "Could not bind\n");
        exit(EXIT_FAILURE);
    }
 
    /* Read datagrams and echo them back to sender. */
 
    for (;;) {
        peer_addr_len = sizeof(peer_addr);
        nread = recvfrom(sfd, buf, BUF_SIZE, 0,
                (struct sockaddr *) &peer_addr, &peer_addr_len);
        if (nread == -1)
            continue;               /* Ignore failed request */
 
        char host[NI_MAXHOST], service[NI_MAXSERV];
 
        s = getnameinfo((struct sockaddr *) &peer_addr,
                        peer_addr_len, host, NI_MAXHOST,
                        service, NI_MAXSERV, NI_NUMERICSERV);
        if (s == 0)
            printf("Received %zd bytes from %s:%s\n",
                    nread, host, service);
        else
            fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));
 
        if (sendto(sfd, buf, nread, 0,
                    (struct sockaddr *) &peer_addr,
                    peer_addr_len) != nread)
            fprintf(stderr, "Error sending response\n");
    }
 
    return 0;
}


// int getaddrinfo(const char *host, /* host 或者IP地址 */
//     const char *service, /* 十进制端口号 或者常用服务名称如"ftp"、"http"等 */
//     const struct addrinfo *hints, /* 获取信息要求设置 */
//     struct addrinfo **res); /* 获取信息结果 */
