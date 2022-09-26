#ifndef _CODE_EXE_TIME_TEST_HPP_
#define _CODE_EXE_TIME_TEST_HPP_

#include <iostream>
#include <string>
#include <set>
#include <unistd.h>
#include <fcntl.h>
#include "stdio.h"
#include <map>
#include <vector>
#include <sys/time.h>

//#include <iterator>

using namespace std;

double getCurrentTime();



/*
*******************************************************************
template <typename T>
class CAcqDataProc
*******************************************************************
*/
template <typename T>
class CAcqDataProc
{
public:
    CAcqDataProc(){}
    ~CAcqDataProc(){}

    void saveRslt(T test_rslt)
    {
        m_monitor_diff.push_back(test_rslt);
    }

    void testFoo()
    {
        for(int c:m_monitor_diff){
            cout<<c<<' ';
        }
	} 
    
    double averageRslt();
    T max_val();
    T min_val();
    double RMS_val();

private:
    vector<T> m_monitor_diff;

    //save to files
};



/*
*******************************************************************
template <typename T>
class CDataAcquist
*******************************************************************
*/
template <typename T>
class CDataAcquist
{
public:
    CDataAcquist(CAcqDataProc<T> & acqdataproc);
    ~CDataAcquist(){}

    void acqStartPoint(T i_acq_val)
    {
        m_point_A = i_acq_val;
        return ;
    }

    int acqStopPoint(T i_acq_val)
    {
        m_point_B = i_acq_val;
        m_interval = m_point_B - m_point_A;

        if(mp_acqDataProc)
        {
            mp_acqDataProc->saveRslt(m_interval);
            clear();
        }
        else{
            clear();
            return 0;
        }
        return 1;
    }

    double getCurrentTime()
    {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return (double)(tv.tv_sec * 1000) + (double)(tv.tv_usec) / 1000;
    }

private:
    T m_point_A;
    T m_point_B;
    T m_interval;
    CAcqDataProc<T> *mp_acqDataProc;//no memory here  

    void clear()
    {
        m_point_A   = 0;
        m_point_B   = 0;
        m_interval  = 0;
    }  
};


template <typename T>
CDataAcquist<T>::CDataAcquist(CAcqDataProc<T> & acqdataproc)
{
    mp_acqDataProc = &acqdataproc;

    m_point_A   = 0;
    m_point_B   = 0;
    m_interval  = 0;
}














#endif