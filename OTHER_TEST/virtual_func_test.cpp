#include <stdio.h>
#include <iostream>
using namespace std;

class A
{
public:
    virtual void foo()
    {
        cout<<"A::foo() is called"<<endl;
    }

    A(){printf(" -- class A construct\n");}
    virtual ~A(){printf(" -- class A destruct\n");}
};

class B:public A
{
public:
    void foo()
    {
        cout<<"B::foo() is called"<<endl;
    }

    B(){printf(" -- class B construct\n");}
    ~B(){printf(" -- class B destruct\n");}
};

int main(void)
{
    A *a = new B();
    a->foo();   // 在这里，a虽然是指向A的指针，但是被调用的函数(foo)却是B的!
    if(a){
        delete a;
        a = nullptr;
    }
    return 0;
}