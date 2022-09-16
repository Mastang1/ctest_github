#ifndef __SRC_CINTERVALTEST_HPP__
#define __SRC_CINTERVALTEST_HPP__

#include <iostream>
#include <string>
#include <set>
#include "stdio.h"
#include <unistd.h>
#include <fcntl.h>
#include <map>

using namespace std;

//int64_t OS_GetTimeStamp()
namespace utest_interval{

struct time_msg_t
{
    //string      test_name;
    int64_t     mst_test_begin;
    int64_t     mst_test_end;
    string      mst_test_reserve;
};



class CIntervalTest
{
public:
    //need what member
    CIntervalTest();//在构造函数中，创建File、创建并初始化set<time_interval>,
    int get_start_time(string test_name);//做什么：获取时间，把时间和名字存在队列之中，set自动查重，执行insert操作，将当前构造的结构体变量插入到set中，名字直接用结构体名字替代了
    int get_end_time();//获取时间戳，find结构体变量，赋值test_end变量，append当前内容到File中，delete当前变量；
private:
    void saveToFile();
    
    map<string,time_msg_t> time_msg_map;
    FILE *p;//或者xml----------需要最后集中写入到文件
    //定义一个mutex用于数据保护

};

//CInterbalTest 构造函数中，实现File 创建 fopen操作；

}

#endif //__DISTRIBUTED_WAKEUP_TOOLS_SINGLETON_H__
