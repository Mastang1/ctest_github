
#if 0
/*gettime5.c*/
#include <time.h>
#include <stdio.h>
int main()
{
    time_t timep;
    struct tm *p;

    time(&timep); /*当前time_t类型UTC时间*/

    printf("time():%d\n",timep);

    p = localtime(&timep); /*转换为本地的tm结构的时间按*/
    timep = mktime(p); /*重新转换为time_t类型的UTC时间，这里有一个时区的转换*/ //by lizp 错误，没有时区转换， 将struct tm 结构的时间转换为从1970年至p的秒数
    printf("time()->localtime()->mktime(): %d\n", timep);
    return 0;
}

#endif



#if 0

#include "time.h"
#include "stdio.h"
#include <sys/time.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
    struct tm *ptr;
    stringstream ss_stream;
    timeval tv;
    time_t lt;

    string str_ret;
    string str_ms;
    char str[128];

    gettimeofday(&tv, 0);

    lt=tv.tv_sec;
    ptr=localtime(&lt);
    strftime(str,100," --%Z: %F %T",ptr);    //--CST: 2023-01-05 10:39:15
    str_ret.append(str);
    ss_stream << "." << tv.tv_usec/1000;  //ms
    ss_stream >> str_ms;
    str_ret.append(str_ms);
    cout<< str_ret<<endl;
    return 0;
}

// struct tm
// {
//   int tm_sec;			/* Seconds.	[0-60] (1 leap second) */
//   int tm_min;			/* Minutes.	[0-59] */
//   int tm_hour;			/* Hours.	[0-23] */
//   int tm_mday;			/* Day.		[1-31] */
//   int tm_mon;			/* Month.	[0-11] */
//   int tm_year;			/* Year	- 1900.  */
//   int tm_wday;			/* Day of week.	[0-6] */
//   int tm_yday;			/* Days in year.[0-365]	*/
//   int tm_isdst;			/* DST.		[-1/0/1]*/

// # ifdef	__USE_MISC
//   long int tm_gmtoff;		/* Seconds east of UTC.  */
//   const char *tm_zone;		/* Timezone abbreviation.  */
// # else
//   long int __tm_gmtoff;		/* Seconds east of UTC.  */
//   const char *__tm_zone;	/* Timezone abbreviation.  */
// # endif
// };




/*
*****************************
*  格式化符号，用于实现格式化字符串
*****************************
%a 星期几的简写
%A 星期几的全称
%b 月分的简写
%B 月份的全称
%c 标准的日期的时间串
%C 年份的后两位数字
%d 十进制表示的每月的第几天
%D 月/天/年
%e 在两字符域中，十进制表示的每月的第几天
%F 年-月-日
%g 年份的后两位数字，使用基于周的年
%G 年分，使用基于周的年
%h 简写的月份名
%H 24小时制的小时
%I 12小时制的小时
%j 十进制表示的每年的第几天
%m 十进制表示的月份
%M 十时制表示的分钟数
%n 新行符
%p 本地的AM或PM的等价显示
%r 12小时的时间
%R 显示小时和分钟：hh:mm
%S 十进制的秒数
%t 水平制表符
%T 显示时分秒：hh:mm:ss
%u 每周的第几天，星期一为第一天 （值从0到6，星期一为0）
%U 第年的第几周，把星期日做为第一天（值从0到53）
%V 每年的第几周，使用基于周的年
%w 十进制表示的星期几（值从0到6，星期天为0）
%W 每年的第几周，把星期一做为第一天（值从0到53）
%x 标准的日期串
%X 标准的时间串
%y 不带世纪的十进制年份（值从0到99）
%Y 带世纪部分的十制年份
%z，%Z 时区名称，如果不能得到时区名称则返回空字符。
%% 百分号

*/

#endif

#if 0
/**
 * @file test_linux_timeFun.cpp
 * @author your name (you@domain.com)
 * @brief 测试自定义时间，或者根据字符串转换来的时间结构，再次通过库函数转换成日历时间
 * @version 0.1
 * @date 2023-01-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "time.h"
#include "stdio.h"
#include <sys/time.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
    struct tm *ptr;
    stringstream ss_stream;
    timeval tv;
    time_t c_time_01, c_time_02;
    struct tm   test_tm;

    string str_ret;
    string str_ms;
    char str[128];

    test_tm.tm_year = 2023-1900;
    test_tm.tm_mon  = 0;
    test_tm.tm_mday = 1;

    test_tm.tm_hour = 15;
    test_tm.tm_min  = 02;
    test_tm.tm_sec  = 0;

    strftime(str,100," --%Z: %F %T",&test_tm); 
    cout << str << endl;

    c_time_01 = mktime(&test_tm);

    cout <<c_time_01 <<endl;


    // test_tm.tm_sec = 43;
    // test_tm.tm_min = 33;

    // c_time_02 = mktime(&test_tm);

    // cout << c_time_02-c_time_01 <<endl;
    // strftime(str,100," --%Z: %F %T",ptr);    //--CST: 2023-01-05 10:39:15

    return 0;
}



#endif




#if 1
/**
 * @file test_linux_timeFun.cpp
 * @author your name (you@domain.com)
 * @brief 注意获取日历时间结构后，可以通过gmtime函数获取格林威治时间或者通过 localtime获取本地时区时间
 * @version 0.1
 * @date 2023-01-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "time.h"
#include "stdio.h"
#include <sys/time.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
    struct tm *ptr;
    stringstream ss_stream;
    timeval tv;
    time_t lt;
    struct tm   test_tm;

    string str_ret;
    string str_ms;
    char str[128];


    gettimeofday(&tv, 0);
    lt = tv.tv_sec;

    printf("time_t is : %d\n", lt);

    //  lt = mktime(&test_tm);
    ptr = gmtime(&lt);

    printf("time_t is : %d", mktime(ptr));

    strftime(str,100," --%Z: %F %T",ptr); 

    cout << str << endl;


    // strftime(str,100," --%Z: %F %T",ptr);    //--CST: 2023-01-05 10:39:15

    return 0;
}



#endif




#if 0

// 关于应用stringstream 实现格式化字符串
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
 
using namespace std;
 
int main()
{
    stringstream sstream;
    string strResult;
    int nValue = 1000;
 
    // 将int类型的值放入输入流中
    sstream << nValue;
    // 从sstream中抽取前面插入的int类型的值，赋给string类型
    sstream >> strResult;
 
    cout << "[cout]strResult is: " << strResult << endl;
    printf("[printf]strResult is: %s\n", strResult.c_str());
 
    return 0;
}

#endif