#include "gtest_stdout_log.hpp"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

namespace testing{
gtest_log * gtest_log::m_gtest_log = 0;

gtest_log* gtest_log::instance()
{
    if(m_gtest_log == nullptr){
        m_gtest_log = new gtest_log;
    }
    return m_gtest_log;
}


int gtest_log::log(const char *pchFmt, ...)
{
    char str_tmp[MAX_LENGTH_OF_LOG];
    int i=0,j=0;

    va_list arg;                           
    va_start (arg, pchFmt);                 
    i=vsnprintf(str_tmp, MAX_LENGTH_OF_LOG, pchFmt, arg);  //success count ，failed -
    va_end(arg);                            

    printf("%s", str_tmp); 
    return i;
}

gtest_log::~gtest_log()
{
    // if(m_gtest_log != nullptr){
    //     delete m_gtest_log;
    // }
}


gtest_log::gtest_log()
{
    //m_gtest_log = nullptr;
}

}