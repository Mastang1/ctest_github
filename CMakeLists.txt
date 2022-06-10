project (test)
cmake_minimum_required (VERSION 3.0)

# version info
#2.1.10 add app switch >=2.1.10 app switch is work
set(${PROJECT_NAME}_VERSION_MAJOR 2)
set(${PROJECT_NAME}_VERSION_MINOR 5)
set(${PROJECT_NAME}_VERSION_PATCH 7)
set (CMAKE_CXX_STANDARD 11)
set (CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


add_executable(test_TCPserver test_TCPserver.cpp )
add_executable(test_TCPclient test_TCPclient.cpp )

add_executable(test_UDPserver test_UDPserver.cpp )
add_executable(test_UDPclient test_UDPclient.cpp )


add_executable(test_namespace test_namespace.cpp)
