#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<ctype.h>

#define SERV_PORT 6666

int main()
{
  int i,j,n,maxi;
  int maxfd,listenfd,connfd,sockfd;
  int nready,client[FD_SETSIZE-1];  //FD_SETSIZE=1024,定义数组client来储存已连接描述符，最多1023个
  char buf[BUFSIZ], str;

  struct sockaddr_in clie_addr,serv_addr;
  socklen_t clie_addr_len;
  fd_set allset,readset;  //定义监听描述符集合allset和发生事件描述符集合readset
 
  bzero(&serv_addr,sizeof(serv_addr));
  serv_addr.sin_family=AF_INET;
  serv_addr.sin_port=htons(SERV_PORT);//端口号，将无符号短整型转换为网络字节顺序
  serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);  //一个主机可能有多个网卡，所以是本机的任意IP地址
 
  listenfd=socket(AF_INET,SOCK_STREAM,0); //AF_INET表示使用32位IP地址，SOCK_STREAM表示使用TCP连接
  bind(listenfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));  //将服务器套接字地址与套接字描述符联系起来
  listen(listenfd,1024); //设置可监听的连接数量为1024

  maxfd=listenfd; //初始化最大文件描述符为监听描述符listenfd
 
  //初始化client数组，将数组所有元素置为-1
  maxi=-1;  //数组client储存的文件描述符的个数，初始化为-1
  for (i=0;i<FD_SETSIZE;i++){
      client[i]=-1;
  }


  //初始化select监听文件描述符的集合
  FD_ZERO(&allset);     //初始化监听集合
  FD_SET(listenfd,&allset);  //将监听描述符listenfd添加到集合中
 
  while(1)
  {
    readset=allset;
    nready=select(maxfd+1,&readset,NULL,NULL,NULL); //select只监听可读事件，且为永久阻塞直到有事件发生---arguments：maxfd+1；readfd，writefd，errorfd，timeout= NULL，zero，timeval
    if (nready<0){
        printf("select error");
        exit(-1);
    }
    //判断listenfd是否发生事件，若发生，则处理新客户端连接请求
    if (FD_ISSET(listenfd,&readset))
    {
       clie_addr_len=sizeof(clie_addr);
       connfd=accept(listenfd,(struct sockaddr *)&clie_addr,&clie_addr_len);//与请求客户端建立连接
       printf("received from %s at port %d\n",
             inet_ntop(AF_INET,&clie_addr.sin_addr.s_addr,&str,sizeof(str)),
             ntohs(clie_addr.sin_port));  //打印该客户端的IP地址和端口号
           
      //将connfd赋值给client数组中第一个为-1的元素位置
      for (i=0;i<FD_SETSIZE;i++)
      {
         if (client[i]<0)
         {
            client[i]=connfd;
            break;
         }
      }
 
      //判断select监听的文件描述符的个数是否超过上限
      if (i == FD_SETSIZE-1)   //减1的原因是要考虑监听描述符listenfd也属于select监控
      {
         fputs("too many clients\n",stderr);
         exit(1);
      }

      FD_SET(connfd,&allset);  //向监控的文件描述符集合allset中添加新的描述符connfd
      if (connfd>maxfd)
         maxfd=connfd;   //更新最大文件描述符值
  
      //保证maxi永远是client数组中最后一个非-1的元素的位置
      if(i>maxi)
         maxi=i;
       
      //如果nready=1，即只有一个发生事件的描述符，在此条件下必为listenfd，则返回循环位置，继续调用select监控；否则继续向下执行
      --nready;
      if(nready==0)
          continue;
    }

    //找到client数组中发生事件的已连接描述符，并读取、处理数据
    for (i=0;i<=maxi;i++)
    {
        sockfd=client[i];
       if (sockfd<0)  //已连接描述符失效，重新开始循环
          continue;  
        
       if (FD_ISSET(sockfd,&readset))
       {
          n=read(sockfd,buf,sizeof(buf));
          if (n==0) //当客户端关闭连接，服务端也关闭连接
          {
             close(sockfd);
             FD_CLR(sockfd,&allset);  //解除select对该已连接文件描述符的监控
             client[i]=-1;
          }
          else if (n>0)
          {
            for (j=0;j<n;j++)
                buf[j]=toupper(buf[j]);
            sleep(2);
            write(sockfd,buf,n);
          }

          --nready;
          if (nready==0)
              break;  //跳出for循环，还在while中
       }
    }
  }
  close(listenfd);
  return 0;
} 
