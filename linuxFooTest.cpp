/*
 * ******************************************************************
 * 
 *--------------
 * 
 * ******************************************************************
 */

#include <sys/time.h>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Cfoo_test{

public:
    Cfoo_test(){};
    ~Cfoo_test(){};

#ifdef BUILD_TEST
    void Fun_print(int16_t a, int16_t b)
    {
        printf("\n result: %d. \n",a+b);
    }
#endif

private:


public:

    int16_t m_arg1;
    int16_t m_arg2;
};



int  main()
{
    Cfoo_test test;
    
#ifdef BUILD_TEST
    test.Fun_print(3,3);
#endif
    return 0;
}

    


    



