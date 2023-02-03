#if 0
#include <stdio.h>
#include <iostream>
#include <string.h>

#define ID_BASE     (0)
#define ID_CHILD    (1)

class CBase
{
public:
	virtual ~CBase() {}

    int id() { return m_id; }
	int type() { return m_type; }


	CBase(int id){
        m_id = id;
    }

private:    

    int m_id;
    int m_type;
};



class CChild : public CBase
{
public:
    virtual ~CChild(){};
    CChild();
};
//可以直接编译，也可以在对象中实现值改变
// CChild::CChild()
//     : CBase(ID_BASE)
// {

// }

CChild::CChild()
    : CBase(ID_BASE)
{
    CBase(1);
}

int main()
{

    return 0;
}


#endif



/**
 * @brief 派生类显式调用基类的构造函数
 * 
 */
#if 1
#include <iostream>
using namespace std;

class Father
{
public:
	Father()
	{
		cout << "基类默认构造函数!\n";
	}
    Father(int id){
        cout << "Basic Class id is"<< id <<endl;
    }
};

class Children : public Father
{
public:
    //显式调用基类的重载构造函数
	Children() : Father(2008)
	{
		cout << "派生类构造函数!\n" << endl;
	}

};

int main(int argc, char** argv)
{
	Children rec;

	return 0;
}

#endif






/**
 * @brief 派生类 自动 调用基类的构造函数
 * 
 */
#if 0
#include <iostream>
using namespace std;

class Father
{
public:
	Father()
	{
		cout << "基类默认构造函数!\n";
	}
    Father(int id){
        cout << "Basic Class id is"<< id <<endl;
    }
};

class Children : public Father
{
public:
	Children() 
	{
		cout << "派生类构造函数!\n" << endl;
	}
};

int main(int argc, char** argv)
{
	Children rec;

	return 0;
}
#endif