#include "stdio.h"
#include <iostream>

using namespace std;


class base
{
public:
    void display()
    {
        printf("\n***** this base class *****\n");
    }
};

class child : public base
{
public:
    void test()
    {
        base::display();
    }
    //nothing
};

int main()
{
    child son;
    son.test();

    return 1;
}
