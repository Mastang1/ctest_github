/**
 * @file test_linux_path_function.cpp
 * @author your name (you@domain.com)
 * @brief 本质为字符串处理，将路径 和  当前目录分开
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <libgen.h>
#include <string.h>

int main()
{
    char *dirc, *basec, *bname, *dname;
    // char *path = "/etc/passwd";
    char *path = "/home/tang/myproject/aisdk/3rdparty";


    dirc = strdup(path);
    basec = strdup(path);

    dname = dirname(dirc);
    bname = basename(basec);
    printf("dirname=%s, basename=%s\n", dname, bname);

    return 0;
}


