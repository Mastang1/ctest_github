project (test_everyday)
cmake_minimum_required (VERSION 3.0)
#[[**********************************************************************

    编译调试信息，包含 
     Typical values include Debug, Release, RelWithDebInfo and MinSizeRel, 
     but custom build types can also be defined.

    1. 可以通过 CMAKE_BUILD_TYPE 来控制使用哪个catch entry；

    2. 也可以：通过CMAKE_CXX_FLAGS 来设置环境变量直接配置
    如： set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c++11 -Wall 
    -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")
    3. 通过add_compile_options实现全局配置，无论何种语言编译器
    如： add_compile_options(-Wall -Wextra -pedantic -Werror)
*************************************************************************]]#

#[[**********************************************************************

    关于调试：
    -g 和 -ggdb 都是令 gcc 生成调试信息，但是它们也是有区别的
        -g
        该选项可以利用操作系统的“原生格式（native format）”生成调试
        信息。GDB 可以直接利用这个信息，其它调试器也可以使用这个调试信息
        -ggdb
        使 GCC 为 GDB 生成专用的更为丰富的调试信息，但是，此时就不能用其
        他的调试器来进行调试了 (如 ddx)
        -g 和 -ggdb 也是分级别的
        -g2
         ****  这是默认的级别 **** ，此时产生的调试信息包括扩展的符号表、行号、局部
        或外部变量信息。
        -g3
        包含级别2中的所有调试信息，以及源代码中定义的宏
        -g1
        级别1（-g1）不包含局部变量和与行号有关的调试信息，因此只能够用于回溯
        跟踪和堆栈转储之用。回溯跟踪指的是监视程序在运行过程中的函数调用历
        史，堆栈转储则是一种以原始的十六进制格式保存程序执行环境的方法，两者
        都是经常用到的调试手段。
*************************************************************************]]#
SET(CMAKE_BUILD_TYPE "Debug")
#C++编译器设置
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

#C编译器设置
SET(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -O3 -Wall")

#设置默认构建类型
IF (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING
        "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
ENDIF()

#set gloable path
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
#set compiler
set (CMAKE_CXX_STANDARD 11)
set (CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

#set output path
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)
find_package(Threads)

add_executable(test_macro test_macro.cpp)
add_executable(test_regex test_regex.cpp)
add_executable(test_tmp test_tmp.cpp)
add_executable(two_pointers two_pointers.cpp)
add_executable(variable_length_paraments variable_length_paraments.cpp)

# target_link_libraries(condition_test ${CMAKE_THREAD_LIBS_INIT})

add_subdirectory (CPP_CONTAINER)
add_subdirectory (IO_STREAM)
add_subdirectory (OTHER_TEST)
add_subdirectory (SYS_FUN)
add_subdirectory (THREADS)
add_subdirectory (NETWORK)
add_subdirectory (C_CPP_MIX)
add_subdirectory (COMMUNICATION)




















