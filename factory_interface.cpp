#if 0

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
 
 
#define SBUF_SIZE 128
char sbuf[SBUF_SIZE];
 
void MyPrintF( const char * format, ... )
{
	va_list args;
	va_start (args, format);
	vsnprintf (sbuf,SBUF_SIZE,format, args);
	va_end (args);
  
	printf("%s",sbuf);		
}
 
int main()
{	
	MyPrintF("my name is %s,my age is %d\n","bob",18);
    return 0;
}

#endif

#if 0

#include <stdio.h>
#include <stdarg.h>

#define MAXLEN 100

int test_log(char* format, ...)
{
    char str_tmp[MAXLEN];
    int i=0,j=0;
    va_list arg;                           
    va_start (arg, format);                 
    i=vsnprintf(str_tmp, MAXLEN, format, arg);  //format为 格式化字符串，核心就是各种%x符号，后续的参数列表要与之对应
    va_end(arg);                            

    printf("%s", str_tmp); 
    return i;
}

int main()
{   
    int i=test_log("This is vsprintf test:%s%d\n","string",1024);    

    return 0;
}
#endif 

//#############################################################
#if 1

#include <stdio.h>
#include <stdarg.h>
#include "./src/gtest_stdout_log.hpp"

#define GTEST_INFO testing::gtest_log::instance()->log
int main()
{   
    //testing::gtest_log::instance()->log("%d",123);
    GTEST_INFO("%s","today is a nice day");
    return 0;
}
#endif 

