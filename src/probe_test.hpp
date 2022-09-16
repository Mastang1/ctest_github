#ifndef _CODE_MSG_ACQ_HPP_
#define _CODE_MSG_ACQ_HPP_

#include <iostream>
#include <string>
#include <set>
#include <unistd.h>
#include <fcntl.h>
#include "stdio.h"
#include <map>

#define BUFFER_LEN (100)
#define FILE_NAME "./probe_test_rslt.txt"

using namespace std;

template <typename T>
class CProbe
{

public:
    CProbe(T& t, string sz_probe_name);
    ~CProbe(); 
    T& dataAcquist(T& t); 

private:
T *m_acquist_rslt;
T *m_diff_rslt;

ofstream file;
char data_buffer[BUFFER_LEN];//数据直接拷贝到该处，因为是泛型数据，可通过指针调用
string m_sz_probe_name; 

};


#endif