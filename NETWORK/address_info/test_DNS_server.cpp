/**
 * @file test_DNS_server.cpp
 * @author your name (you@domain.com)
 * @brief 采用gethostbyname(const char * name)函数获取对应名称的ip地址等信息
 *          gethostbyname()函数应用测试
 *         其 底层的实现过程为调用socket，采用udp协议，端口号为53
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
 
extern int h_errno;
 
int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Use example: %s www.google.com\n", *argv);
        return -1;
    }
 
    char *name = argv[1];
    struct hostent *hptr;
 
    hptr = gethostbyname(name);
    if (hptr == NULL) {
        printf("gethostbyname error for host: %s: %s\n", name, hstrerror(h_errno));
        return -1;
    }
    //输出主机的规范名
    printf("\tofficial: %s\n", hptr->h_name);
 
    //输出主机的别名
    char **pptr;
    char str[INET_ADDRSTRLEN];
    for (pptr=hptr->h_aliases; *pptr!=NULL; pptr++) {
        printf("\ttalias: %s\n", *pptr);
    }
 
    //输出ip地址
    switch (hptr->h_addrtype) {
        case AF_INET:
            pptr = hptr->h_addr_list;
            for (; *pptr!=NULL; pptr++) {
                printf("\taddress: %s\n",
                        inet_ntop(hptr->h_addrtype, hptr->h_addr, str, sizeof(str)));
            }
            break;
        default:
            printf("unknown address type\n");
            break;
    }
 
    return 0;
}

// /* Description of data base entry for a single host.  */
// struct hostent
// {
//   char *h_name;			/* Official name of host.  */
//   char **h_aliases;		/* Alias list.  */
//   int h_addrtype;		/* Host address type.  */
//   int h_length;			/* Length of address.  */
//   char **h_addr_list;		/* List of addresses from name server.  */
// #ifdef __USE_MISC
// # define	h_addr	h_addr_list[0] /* Address, for backward compatibility.*/
// #endif
// };