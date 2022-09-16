#include "probe_test.hpp"

template <typename T>
CProbe<T>::CProbe(T& t, string sz_probe_name)
:   m_acquist_rslt(t),
    m_diff_rslt(nullptr),
    m_sz_probe_name(sz_probe_name),
    m_fp(fp)
{
   file.open(FILE_NAME, ios::in);//回头加错误判断
}


template <typename T>
CProbe<T>::~CProbe()
{

}

template <typename T>
T& CProbe<T>::dataAcquist(T& t)
{
   m_acquist_rslt = t; 
   return m_acquist_rslt; 
}


