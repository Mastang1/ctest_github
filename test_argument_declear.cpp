/***********************************************************
 * 
 *  For test function pointer
 *  C++中，可以在声明函数的时候，在参数中声明缺省值 
 * *********************************************************
 * */

#include <iostream>
#include <stdio.h>

#include <string>

using namespace std;

int fun_test(int num = 8);



int main()
{
    fun_test();


    
 
    return 0;
}


int fun_test(int num)
{
    num++;
    cout<<"\n num = "<<num<<endl;
    return 0;
}
