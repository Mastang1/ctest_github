#### build openssl ###
#set(THIRD_PARTY_TARGET_NAME "OPENSSL_BUILD")
set(THIRD_LIBRARY_NAME "openssl")
#set(THIRD_PARTY_GIT_REPOSITORY "http://10.180.97.83:thirdparty/openssl.git")
#set(THIRD_PARTY_TAG_OR_BRANCH "v1.0.2t")
#set(THIRD_PARTY_CONFIGURE_GENERATE_COMMAND "buildconf")
#set(THIRD_PARTY_PROJECT_NAME "${THIRD_LIBRARY_NAME}_repository")
#set(THIRD_PARTY_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY_PROJECT_NAME}")
#set(THIRD_PARTY_INSTALL_DIR "${3RD_PREBUILD_PATH}/${THIRD_LIBRARY_NAME}/${COMPILE_PLATFORM_DIR_NAME}/${THIRD_LIBRARY_NAME}")
#set(THIRD_PARTY_CONFIGURE_OPTIONS "--prefix=${THIRD_PARTY_INSTALL_DIR} --with-pic --host=${COMPILE_PLATFORM_HOST} --disable-extra-programs")
#
##if (REBUILD_ALL_THIRD_LIBRARY)
#        execute_process(
#            COMMAND rm -rf ${THIRD_PARTY_INSTALL_DIR}
#            RESULT_VARIABLE COMMAND_RESULT
#        )
##endif (REBUILD_ALL_THIRD_LIBRARY)
#
###### find library #####
#find_library(SSL_LIB
#        NAMES ${THIRD_LIBRARY_NAME}
#        PATH ${THIRD_PARTY_INSTALL_DIR}
#        PATH_SUFFIXES "/lib"
#        NO_DEFAULT_PATH
#        )
#message(STATUS "ssl lib find path = ${THIRD_PARTY_INSTALL_DIR}")
#message(STATUS "find ssl library result is ${SSL_LIB}")
#
#if (SSL_LIB STREQUAL "SSL_LIB-NOTFOUND")
#        ExternalLibBuild(
#            ${THIRD_PARTY_TARGET_NAME}
#            ${THIRD_PARTY_GIT_REPOSITORY}
#            ${THIRD_PARTY_TAG_OR_BRANCH}
#            ${THIRD_PARTY_SOURCE_DIR}
#            ${THIRD_PARTY_CONFIGURE_GENERATE_COMMAND}
#            ${THIRD_PARTY_CONFIGURE_OPTIONS}
#        )
#endif ()
#set(OPENSSL_INCLUDE_DIRS "${THIRD_PARTY_INSTALL_DIR}/include" CACHE STRING "libssl include" FORCE)
#if (BUILD_STATICLIB)  #TODO
#        set(SSL_LIBRARIES "${OPENSSL_LIB_PATH}/libssl.a" CACHE STRING "libssl lib" FORCE)
#        set(CRYPTO_LIBARIES "${OPENSSL_LIB_PATH}/libcrypto.a" CACHE STRING "libcrypto lib" FORCE)
#else()
#        set(SSL_LIBRARIES "${OPENSSL_LIB_PATH}/libssl.so" CACHE STRING "libssl lib" FORCE)
#        set(CRYPTO_LIBARIES "${OPENSSL_LIB_PATH}/libcrypto.so" CACHE STRING "libcrypto lib" FORCE)
#endif()
#
#message(STATUS "ssl librares = ${SSL_LIBRARIES}")
#message(STATUS "crypto libraries = ${CRYPTO_LIBARIES}")
#
#install (
#        DIRECTORY ${THIRD_PARTY_INSTALL_DIR}
#        DESTINATION ${CMAKE_BINARY_DIR}/thirdparty/
#)




set(OPENSSL_INSTALL_DIR "${3RD_PREBUILD_PATH}/${THIRD_LIBRARY_NAME}/${COMPILE_PLATFORM_DIR_NAME}/${THIRD_LIBRARY_NAME}"  CACHE STRING "openssl install dir" FORCE)
message(STATUS "openssl install path = ${OPENSSL_INSTALL_DIR}")

set(OPENSSL_INCLUDE_DIRS "${OPENSSL_INSTALL_DIR}/include" CACHE STRING "libopenssl include" FORCE)
set(OPENSSL_LIB_PATH "${OPENSSL_INSTALL_DIR}/lib" CACHE STRING "libopenssl lib path" FORCE)
if (BUILD_STATICLIB)
set(SSL_LIBRARIES "${OPENSSL_LIB_PATH}/libssl.a" CACHE STRING "libssl lib" FORCE)
set(CRYPTO_LIBARIES "${OPENSSL_LIB_PATH}/libcrypto.a" CACHE STRING "libcrypto lib" FORCE)
else ()
set(SSL_LIBRARIES "${OPENSSL_LIB_PATH}/libssl.so" CACHE STRING "libssl lib" FORCE)
set(CRYPTO_LIBARIES "${OPENSSL_LIB_PATH}/libcrypto.so" CACHE STRING "libcrypto lib" FORCE)
endif()

message(STATUS "ssl librares = ${SSL_LIBRARIES}")
message(STATUS "crypto libraries = ${CRYPTO_LIBARIES}")

install (
        DIRECTORY ${OPENSSL_INSTALL_DIR}
        DESTINATION ${CMAKE_BINARY_DIR}/thirdparty/
)