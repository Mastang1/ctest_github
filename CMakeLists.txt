project (test)
cmake_minimum_required (VERSION 3.0)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/aisdk/include)
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../include/lib_curl/lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/lib_curl/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# version info
#2.1.10 add app switch >=2.1.10 app switch is work
set(${PROJECT_NAME}_VERSION_MAJOR 2)
set(${PROJECT_NAME}_VERSION_MINOR 5)
set(${PROJECT_NAME}_VERSION_PATCH 7)

 
macro(arg_test para1 para2)
        MESSAGE(STATUS ARGC=${ARGC})
        MESSAGE(STATUS ARGV=${ARGV})
        MESSAGE(STATUS ARGN=${ARGN})
        MESSAGE(STATUS ARGV0=${ARGV0})
        MESSAGE(STATUS ARGV1=${ARGV1})
        MESSAGE(STATUS ARGV2=${ARGV2})
endmacro()
 
arg_test(para_1, para_2,para_3,para_4,retr,eeee)
#set compiler
set (CMAKE_CXX_STANDARD 11)
#推荐在终端中，执行cmake前，执行该操作

# export CC=/usr/bin/gcc
# export CXX=/opt/rh/gcc-toolset-11/root/usr/bin/g++


if (BUILD_TEST)
    message (STATUS "--------------------build tests--------------------")
    add_definitions(-DBUILD_TEST)                        # tangadd then delete this line
endif()


set (CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

# SET(CMAKE_BUILD_TYPE "Debug")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O2 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O0 -Wall")
#set output path
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)




find_package(Threads)


add_executable(test_fork test_fork.cpp)

add_executable(dp_test dp_test.cpp)
add_executable(test_TCPserver test_TCPserver.cpp )
add_executable(test_TCPclient test_TCPclient.cpp )

add_executable(test_UDPserver test_UDPserver.cpp )
add_executable(test_UDPclient test_UDPclient.cpp )
add_executable(test_String test_String.cc)

add_executable(test_namespace test_namespace.cpp)
add_executable(linuxFooTest linuxFooTest.cpp)

add_executable(queuetest queuetest.cpp)
add_executable(test_ioctl_fun test_ioctl_fun.cpp)
add_executable(ifconfig_fun ifconfig_fun.cpp)
add_executable(test_tmp test_tmp.cpp )

add_executable(condition_test condition_test.cc)
target_link_libraries(condition_test ${CMAKE_THREAD_LIBS_INIT})

add_executable(mulit_thread_test mulit_thread_test.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/os_adapter.cpp)
target_link_libraries(mulit_thread_test ${CMAKE_THREAD_LIBS_INIT})

#=================================================================
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib_curl/lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/lib_curl/include)

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

add_executable(factory_interface factory_interface.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/gtest_stdout_log.cpp)
# add_executable(Semaphore_test Semaphore_test.cpp)
# target_link_libraries(Semaphore_test ${CMAKE_THREAD_LIBS_INIT})

# -------------------------------------------------
















