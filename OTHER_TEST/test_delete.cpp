
/**
 * @file test_delete.cpp
 * @author your name (you@domain.com)
 * @brief 当变量数据类型为自定义类型时候，delete空间采用delete []p形式；
 * @version 0.1
 * @date 2023-04-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
 
using namespace std;
 
class A
{
private:
    int m_data;
public:
    A() { }
    ~A() { cout << "delete object." << endl; }
};
 
int main()
{
    A *a = new A[10];
    delete []a;
    // delete a;
 
    return 0;
}


#if 0
#include <iostream>
#include <string.h>

int main()
{
    char *p = new char[100];
    memcpy(p, "Today is a nice day!", sizeof("Today is a nice day!"));
    std::cout << p << std::endl;
    delete p;

    return 0;
}

#endif