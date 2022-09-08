#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
    int i_cmp_rslt;
    string sz_first("hello,niki");
    string sz_second = "niki";
    string sz_temp(sz_first);

    sz_first.swap(sz_second);

    cout << sz_second << endl;


    return 0;
}
