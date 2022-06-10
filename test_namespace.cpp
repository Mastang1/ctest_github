/***********************************************************
 * 
 *  For test function pointer
 * 
 * *********************************************************
 * */

#include <iostream>
#include <stdio.h>

#include <string>

using namespace std;

int fun_test();

typedef int(*pt_foo)();

int main()
{
    pt_foo pt = fun_test;

    (*pt)();
    
 
    return 0;
}


int fun_test()
{
    cout<<"\ncall fun_test successfully!\n"<<endl;

    return 0;

}
