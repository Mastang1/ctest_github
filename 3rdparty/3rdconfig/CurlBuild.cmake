### curl ###
set(THIRD_PARTY_TARGET_NAME "CURL_BUILD")
set(THIRD_LIBRARY_NAME "curl")
set(THIRD_PARTY_GIT_REPOSITORY "http://10.180.97.83/thirdparty/curl_mirror.git")
set(THIRD_PARTY_TAG_OR_BRANCH "curl-7_65_3")
set(THIRD_PARTY_CONFIGURE_GENERATE_COMMAND "buildconf")
set(THIRD_PARTY_PROJECT_NAME "${THIRD_LIBRARY_NAME}_repository")
set(THIRD_PARTY_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY_PROJECT_NAME}")
if(WITH_SSL)
        set(THIRD_PARTY_INSTALL_DIR "${3RD_PREBUILD_PATH}/${THIRD_LIBRARY_NAME}/${COMPILE_PLATFORM_DIR_NAME}/with_ssl/curl")
        set(THIRD_PARTY_CONFIGURE_OPTIONS "--prefix=${THIRD_PARTY_INSTALL_DIR} --host=${COMPILE_PLATFORM_HOST} LDFLAGS=-Wl,-rpath=${OPENSSL_INSTALL_DIR}/lib --with-ssl=${OPENSSL_INSTALL_DIR} --with-pic --disable-libtool-lock --disable-ftp --disable-file --disable-ldap  --disable-ldaps --disable-rtsp --disable-proxy --disable-dict --disable-telnet --disable-tftp --disable-pop3 --disable-imap  --disable-smtp  --disable-gopher --disable-manual --disable-nonblocking --disable-threaded-resolver --disable-verbose --disable-sspi  --disable-crypto-auth  --disable-ntlm-wb  --disable-tls-srp --disable-cookies --disable-hidden-symbols --disable-soname-bump --without-zlib   --without-gnutls  --without-polarssl --without-cyassl --without-nss --without-axtls  --without-ca-bundle  --without-ca-path  --without-librtmp --without-libidn2 --without-nghttp2")
else()
        set(THIRD_PARTY_INSTALL_DIR "${3RD_PREBUILD_PATH}/${THIRD_LIBRARY_NAME}/${COMPILE_PLATFORM_DIR_NAME}/without_ssl/curl")
        set(THIRD_PARTY_CONFIGURE_OPTIONS "--prefix=${THIRD_PARTY_INSTALL_DIR} --host=${COMPILE_PLATFORM_HOST} --without-ssl --with-pic --disable-libtool-lock --disable-ftp --disable-file --disable-ldap  --disable-ldaps --disable-rtsp --disable-proxy --disable-dict --disable-telnet --disable-tftp --disable-pop3 --disable-imap  --disable-smtp  --disable-gopher --disable-manual --disable-nonblocking --disable-threaded-resolver --disable-verbose --disable-sspi  --disable-crypto-auth  --disable-ntlm-wb  --disable-tls-srp --disable-cookies --disable-hidden-symbols --disable-soname-bump --without-zlib   --without-gnutls  --without-polarssl --without-cyassl --without-nss --without-axtls  --without-ca-bundle  --without-ca-path  --without-librtmp --without-libidn2 --without-nghttp2")
endif()
if(WITH_MBEDTLS)
    set(THIRD_PARTY_CONFIGURE_OPTIONS "--prefix=${THIRD_PARTY_INSTALL_DIR} --host=${COMPILE_PLATFORM_HOST} --with-mbedtls --with-pic --disable-libtool-lock --disable-ftp --disable-file --disable-ldap  --disable-ldaps --disable-rtsp --disable-proxy --disable-dict --disable-telnet --disable-tftp --disable-pop3 --disable-imap  --disable-smtp  --disable-gopher --disable-manual --disable-nonblocking --disable-threaded-resolver --disable-verbose --disable-sspi  --disable-crypto-auth  --disable-ntlm-wb  --disable-tls-srp --disable-cookies --disable-hidden-symbols --disable-soname-bump --without-zlib   --without-gnutls  --without-polarssl --without-cyassl --without-nss --without-axtls  --without-ca-bundle  --without-ca-path  --without-librtmp --without-libidn2 --without-nghttp2")
endif()
set(THIRD_PARTY_AUTOMAKE_OPTIONS " ")
if (REBUILD_ALL_THIRD_LIBRARY)
    execute_process(
            COMMAND rm -rf ${THIRD_PARTY_INSTALL_DIR}
            RESULT_VARIABLE COMMAND_RESULT
    )
endif (REBUILD_ALL_THIRD_LIBRARY)

##### find library #####
find_library(CURL_LIB
        NAMES ${THIRD_LIBRARY_NAME}
        PATHS ${THIRD_PARTY_INSTALL_DIR}
        PATH_SUFFIXES "/lib"
        NO_DEFAULT_PATH
        )

message(STATUS "curl lib find path = ${THIRD_PARTY_INSTALL_DIR}")
message(STATUS "find curl library result is ${CURL_LIB}")
if (CURL_LIB STREQUAL "CURL_LIB-NOTFOUND")
    ExternalLibBuild(
            ${THIRD_PARTY_TARGET_NAME}
            ${THIRD_PARTY_GIT_REPOSITORY}
            ${THIRD_PARTY_TAG_OR_BRANCH}
            ${THIRD_PARTY_SOURCE_DIR}
            ${THIRD_PARTY_CONFIGURE_GENERATE_COMMAND}
            ${THIRD_PARTY_CONFIGURE_OPTIONS}
            ${THIRD_PARTY_AUTOMAKE_OPTIONS}
    )
endif ()
set(CURL_INCLUDE_DIRS "${THIRD_PARTY_INSTALL_DIR}/include" CACHE STRING "libcurl include" FORCE)
set(CURL_LIB_PATH "${THIRD_PARTY_INSTALL_DIR}/lib" CACHE STRING "libcurl lib path" FORCE)

if(BUILD_FOR_MT8516 OR BUILD_FOR_MT8512)
        set(CURL_LIBRARIES "${CURL_LIB_PATH}/libcurl.so" CACHE STRING "libcurl lib" FORCE)
else()
        if (BUILD_STATICLIB)
        set(CURL_LIBRARIES "${CURL_LIB_PATH}/libcurl.a" CACHE STRING "libcurl lib" FORCE)
        else()
        set(CURL_LIBRARIES "${CURL_LIB_PATH}/libcurl.so" CACHE STRING "libcurl lib" FORCE)
        endif()
endif(BUILD_FOR_MT8516 OR BUILD_FOR_MT8512)

install (
        DIRECTORY ${THIRD_PARTY_INSTALL_DIR}
        DESTINATION ${CMAKE_BINARY_DIR}/thirdparty/
)