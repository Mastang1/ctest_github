#ifndef _CODE_MSG_ACQ_HPP_
#define _CODE_MSG_ACQ_HPP_

#include <iostream>
#include <string>
#include <set>
#include "stdio.h"
#include <unistd.h>
#include <fcntl.h>
#include <map>

using namespace std;

template <typename T>
class CProbe
{

public:
    CProbe(T& t, string sz_probe_name);
    ~CProbe(); 
    


private:
T *m_acquist_rslt;
T *m_diff_rslt;

string m_sz_probe_name; 

};


#endif