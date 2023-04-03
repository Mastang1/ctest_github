#include <string.h>  
#include <sys/socket.h>  
#include <sys/ioctl.h>  
#include <net/if.h>  
#include <stdio.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
int main()  
{  
        int inet_sock;  
        struct ifreq ifr;  
        inet_sock = socket(AF_INET, SOCK_DGRAM, 0);  

        strcpy(ifr.ifr_name, "enp0s31f6");  
        //SIOCGIFADDR标志代表获取接口地址  
        if (ioctl(inet_sock, SIOCGIFADDR, &ifr) <  0)  
                perror("ioctl");  
        printf("%s\n", inet_ntoa(((struct sockaddr_in*)&(ifr.ifr_addr))->sin_addr)); //两个同顺序的结构体之间的转换 sockaddr_in and  
        return 0;  
}  

/*
struct ifreq
  {
# define IFHWADDRLEN	6
# define IFNAMSIZ	IF_NAMESIZE
    union
      {
	char ifrn_name[IFNAMSIZ];	
      } ifr_ifrn;

    union
      {
	struct sockaddr ifru_addr;
	struct sockaddr ifru_dstaddr;
	struct sockaddr ifru_broadaddr;
	struct sockaddr ifru_netmask;
	struct sockaddr ifru_hwaddr;
	short int ifru_flags;
	int ifru_ivalue;
	int ifru_mtu;
	struct ifmap ifru_map;
	char ifru_slave[IFNAMSIZ];	
	char ifru_newname[IFNAMSIZ];
	__caddr_t ifru_data;
      } ifr_ifru;
  };
*/