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
