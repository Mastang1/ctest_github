#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

char gl_str[100] = "nice day!";

int main()
{
    char *p = NULL;
    {
        char char_test[100] = "\0";
        p = char_test;
        memcpy(char_test, gl_str, sizeof(gl_str));
    }
    std::cout << p <<std::endl;

    return 0;
}