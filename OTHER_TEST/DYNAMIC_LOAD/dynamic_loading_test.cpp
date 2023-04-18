/**
 * 简单总结： 
 * 1. C++ 不允许隐式转换类型，所以需要先构造类型，显式转换;
 * 2. C++ 环境下， 会改变函数签名，所以需要用extern “C”
 *
*/
#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char *argv)
{
        typedef int (*FUN_PTR)(int);

        int index = -1;
        void *handle;
        FUN_PTR tangyapeng_cout;
        int ret = -1;

		// 获取handle
        handle = dlopen("../lib/librenegade.so", RTLD_NOW);
        if (handle == NULL) {
                printf("dlopen error!:%s\n", dlerror());
                return -1;
        }

		//获取函数，get_card_index为so中的实现函数，get_index指向该函数；
        tangyapeng_cout = (FUN_PTR)dlsym(handle, "myprintf");
        if (tangyapeng_cout == NULL) {
                printf("dlsym error!\n");
                dlclose(handle);
                return -1;
        }

        tangyapeng_cout(999);
		
        // 关闭该handle
		dlclose(handle);
        return 0;
}
