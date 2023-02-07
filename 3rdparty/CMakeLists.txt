cmake_minimum_required(VERSION 3.12)
set (3RD_PREBUILD_PATH "${CMAKE_CURRENT_SOURCE_DIR}/3rdprebuild")
set (COMPILE_PLATFORM_HOST "x86_64-pc-linux-gnu")
set (OPENSSL_INSTALL_DIR "/home/tang/myproject/tang_test/cTest/3rdparty/3rdprebuild/openssl/linux_x64/openssl")

include (3rdconfig/ExternalProjectBuild.cmake)
include (3rdconfig/NopollBuild.cmake)
