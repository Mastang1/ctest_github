#include "../include/IFoo.hpp"

class CFOO_entity :public IFOO
{
    virtual void Fun_start();
    virtual void Fun_then();
    virtual void Fun_final();
private:
    int m_arg01;
    int m_arg02;
};
