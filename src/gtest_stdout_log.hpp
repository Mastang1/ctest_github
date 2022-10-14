#ifndef __GTEST_STDOUT_LOG_H__
#define __GTEST_STDOUT_LOG_H__

namespace testing{

#define MAX_LENGTH_OF_LOG (100)

class gtest_log
{
public:
    gtest_log();
    ~gtest_log();
    static gtest_log * instance();
    int log(const char *pchFmt, ...);
private:
    static gtest_log* m_gtest_log;
    static int count;
};


}


#endif