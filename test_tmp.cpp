#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

#define FOO__ 1
int main()
{
    #ifdef __linux__
        std::cout<< " -- platform is:" << __linux__ << std::endl;
    #endif

    std::cout << " -- FOO__ is:" << FOO__;
    return 0;
}