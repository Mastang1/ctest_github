cmake_minimum_required(VERSION 3.12)
set (3RD_PREBUILD_PATH "${CMAKE_CURRENT_SOURCE_DIR}/3rdprebuild")
set (COMPILE_PLATFORM_HOST "aarch64-poky-linux")
set (OPENSSL_INSTALL_DIR "/home/tang/myproject/tang_test/cTest/3rdparty/3rdprebuild/openssl/mt8516/openssl")

include (3rdconfig/ExternalProjectBuild.cmake)
include (3rdconfig/NopollBuild.cmake)
