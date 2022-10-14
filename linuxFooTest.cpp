#if 0
#include <sys/time.h>
#include <iostream>
#include <string>


using namespace std;

int  main()
{
  
#ifdef BUILD_TEST
    printf("define BUILD_TEST\n\n\n");
#endif
    return 0;
}

#endif

//#######################################################
//采用宏定义替换函数

#if 0
#include <sys/time.h>
#include <iostream>
#include <string>

#define FOO(x,y) add(x,y)
#define DEBUG printf

using namespace std;

int add(int a ,int b)
{
    DEBUG("result is :%d", a+b);
    return (a+b);
}

int  main()
{
  
    FOO(3,4);
    return 0;
}
#endif


//#####################################################################
#if 0
#include <stdio.h>

#define GTEST_STRINGIFY_HELPER_(name) #name


int  main(void)
{
    char * tmp_str = GTEST_STRINGIFY_HELPER_(nice day!);
    printf("%s", tmp_str);

    return 0;
}


#endif

    
//#####################################################################还需要增加gtest中的一个大宏，解析一下
#if 1
#include <stdio.h>


//简单说明：#name用于实现name转换为“name”
//(...)表示以一系列的参数，后边可以用args来引用
//
#define GTEST_STRINGIFY_HELPER_(name, ...) #name
#define GTEST_STRINGIFY_(...) GTEST_STRINGIFY_HELPER_(__VA_ARGS__, )
//定义类名称标识符
#define GTEST_TEST_CLASS_NAME_(test_suite_name, test_name) \
    test_suite_name##_##test_name
//定义对象标识符
#define ENTITY_TEST_CLASS_NAME(test_suite_name, test_name) \
    entity##test_suite_name##_##test_name


//自己测试用宏定义,该宏定义可以根据输入参数列表，拼接成一个字符串
//也就说明_VA_ARGS_就是所有参数列表组成标识符
#define CONN_STRING(...) #__VA_ARGS__
//**********************************************************************
// Helper macro for defining tests.
#define GTEST_TEST_(test_suite_name, test_name, parent_class)       \
  static_assert(sizeof(GTEST_STRINGIFY_(test_suite_name)) > 1,                 \
                "test_suite_name must not be empty");                          \
  static_assert(sizeof(GTEST_STRINGIFY_(test_name)) > 1,                       \
                "test_name must not be empty");                                \
  class GTEST_TEST_CLASS_NAME_(test_suite_name, test_name)                     \
      : public parent_class {                                                  \
   public:                                                                     \
    GTEST_TEST_CLASS_NAME_(test_suite_name, test_name)() = default;            \
    ~GTEST_TEST_CLASS_NAME_(test_suite_name, test_name)() = default;            \
  };   

class tangtest
{
public:
    tangtest() = default;
    ~tangtest() = default;
    int TestPrint(){
        printf("\ntang test!\n");
    }
};


//******************************************************************
int  main(void)
{
    GTEST_TEST_(xiao, tang, tangtest)

    GTEST_TEST_CLASS_NAME_(xiao, tang) ENTITY_TEST_CLASS_NAME(xiao, tang);
    ENTITY_TEST_CLASS_NAME(xiao, tang).TestPrint();

    //对#name进行测试
    printf("\n\n\n%s", CONN_STRING(tang ,ya, peng));
}
#endif
//###########################################################################

    
