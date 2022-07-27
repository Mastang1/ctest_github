/*
 * ******************************************************************
 * 
 *---------指针变量的直接赋值操作，不涉及pop后的问题
 * 
 * ******************************************************************
 */

#include <sys/time.h>
#include <iostream>
#include <string>
#include <queue>

using namespace std;


struct utrace_info
{
    string traceId;
    string bName;
    string subSys;
    string spanId;
    string sessionId;
};
std::queue<struct utrace_info *> m_dataQueue;


int  main()
{
    utrace_info *ptr_info = new utrace_info;
    ptr_info->traceId   = "traceId";
    ptr_info->bName     = "bName";
    ptr_info->spanId    = "spanID";
    ptr_info->subSys    = "subSys";
    ptr_info->sessionId = "seesionID";
    m_dataQueue.push(ptr_info);


    utrace_info *p1 = m_dataQueue.front();
    
    utrace_info * p2;
    p2 = m_dataQueue.front();

    m_dataQueue.pop(); 

    cout<<p1->traceId<<endl;
    cout<<p2->traceId<<endl;


    return 0;
}

    


    



