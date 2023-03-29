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

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/aisdk/include)
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../include/lib_curl/lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/lib_curl/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(${PROJECT_NAME}_VERSION_MAJOR 1)
set(${PROJECT_NAME}_VERSION_MINOR 0)
set(${PROJECT_NAME}_VERSION_PATCH 0)

#set compiler
set (CMAKE_CXX_STANDARD 11)
set (CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

#set output path
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)
find_package(Threads)

add_executable(test_rand_foo test_rand_foo.cpp)
add_executable(test_linux_timeFun test_linux_timeFun.cpp)
add_executable(test_fork test_fork.cpp)
add_executable(test_cpp_io_string test_cpp_io_string.cpp)
add_executable(test_container test_container.cpp)
add_executable(test_printf_multi_char test_printf_multi_char.cpp)
add_executable(test_regex test_regex.cpp)

add_executable(test_linux_path_function test_linux_path_function.cpp)

add_executable(two_pointers two_pointers.cpp)
add_executable(test_TCPserver test_TCPserver.cpp )
add_executable(test_TCPclient test_TCPclient.cpp )

add_executable(test_UDPserver test_UDPserver.cpp )
add_executable(test_UDPclient test_UDPclient.cpp )
add_executable(test_String test_String.cc)

add_executable(test_namespace test_namespace.cpp)
add_executable(linuxFooTest linuxFooTest.cpp)
add_executable(creat_binary_file creat_binary_file.cpp)
add_executable(queuetest queuetest.cpp)
add_executable(test_ioctl_fun test_ioctl_fun.cpp)
add_executable(ifconfig_fun ifconfig_fun.cpp)
add_executable(string_proc string_proc.cpp )
add_executable(test_macro test_macro.cpp)
add_executable(linux_sys_fun_test linux_sys_fun_test.cpp)
add_executable(variable_length_paraments variable_length_paraments.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/gtest_stdout_log.cpp)
add_executable(test_tmp test_tmp.cpp)
add_executable(condition_test condition_test.cc)
target_link_libraries(condition_test ${CMAKE_THREAD_LIBS_INIT})

add_executable(mulit_thread_test mulit_thread_test.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/os_adapter.cpp)
target_link_libraries(mulit_thread_test ${CMAKE_THREAD_LIBS_INIT})

add_executable(get_threadID_from_processID get_threadID_from_processID.cpp)
target_link_libraries(get_threadID_from_processID ${CMAKE_THREAD_LIBS_INIT})



#=================================================================


add_executable(test_curl test_curl.cpp)
target_link_libraries(test_curl ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(test_curl curl)

#add some target att,此处单独设置路径
set_target_properties(test_curl
PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/tang"
LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/tang"
ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/tang"
PDB_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/tang")
#- -- - ----------------------------------------------------------
add_subdirectory(network_test)
add_subdirectory(test_inherit_class)

# ###############################################################
#[[tang  test; string compare used STREQUAL
set(father_str "today is a nice day")
string(FIND ${father_str} "nn" rslt)
if( ${rslt} EQUAL -1)
    message(STATUS "no")
else()
    message(STATUS "yes")

endif()
]]#

#[[------------------------------------  sbmod get
    if (WITH_DNN_VAD)
        if(GIT_SUBMODULE)
            execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init 3rdparty/dnn_vad/dnnvad
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                            RESULT_VARIABLE GIT_DNNVAD_SUBMOD_RESULT)
            if(NOT GIT_DNNVAD_SUBMOD_RESULT EQUAL "0")
                message(FATAL_ERROR "git submodule update --init dnnvad failed with ${GIT_DNNVAD_SUBMOD_RESULT}, please checkout submodules")
            endif()
        endif(GIT_SUBMODULE)
        set (HAVE_DNN_VAD ON)
    endif (WITH_DNN_VAD)

]]#

















