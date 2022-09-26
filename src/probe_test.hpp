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
    CProbe(T acquist_rslt, T diff_rslt);
    //~CProbe(); 
    CProbe<T>& operator-(CProbe<T> &arg);
    void display();
//private:
    T m_acquist_rslt;
    T m_diff_rslt;

    //ofstream file;
    char data_buffer[BUFFER_LEN];//数据直接拷贝到该处
    string m_sz_probe_name; 

};

template <typename T>
CProbe<T>::CProbe(T acquist_rslt, T diff_rslt)
:   m_acquist_rslt(acquist_rslt),
    m_diff_rslt(diff_rslt)
{
  cout<<m_acquist_rslt<<endl; 
}


// template <typename T>
// CProbe<T>::~CProbe()
// {

// }

template <typename T>
CProbe<T>& CProbe<T>::operator-(CProbe<T> &arg)
{
   this->m_diff_rslt= this->m_acquist_rslt - arg.m_acquist_rslt;
   return *this;
}

template <typename T>
void CProbe<T>::display()
{
   cout<<"acquist_rslt: "<<m_acquist_rslt<<"\ndiff_rslt: "<<m_diff_rslt<<endl;
}

#endif