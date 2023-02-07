#### build nopoll ###
set(THIRD_PARTY_TARGET_NAME "NOPOLL_BUILD")
set(THIRD_LIBRARY_NAME "nopoll")
# set(THIRD_PARTY_GIT_REPOSITORY "git@10.180.97.83:thirdparty/nopoll.git")
# set(THIRD_PARTY_TAG_OR_BRANCH "nopoll-0.4.7-for-uaisdk")

set(THIRD_PARTY_GIT_REPOSITORY "git@10.180.97.83:renegade/nopoll.git")
# set(THIRD_PARTY_TAG_OR_BRANCH "nopoll_adapt_ping-pong")
set(THIRD_PARTY_TAG_OR_BRANCH "master")

set(THIRD_PARTY_CONFIGURE_GENERATE_COMMAND "autogen.sh")
set(THIRD_PARTY_PROJECT_NAME "${THIRD_LIBRARY_NAME}_repository")
set(THIRD_PARTY_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${THIRD_PARTY_PROJECT_NAME}")
set(THIRD_PARTY_INSTALL_DIR "${3RD_PREBUILD_PATH}/${THIRD_LIBRARY_NAME}")
set(THIRD_PARTY_CONFIGURE_OPTIONS "--prefix=${THIRD_PARTY_INSTALL_DIR} --host=${COMPILE_PLATFORM_HOST} LDFLAGS=-Wl,-rpath=${OPENSSL_INSTALL_DIR}/lib --with-ssl=${OPENSSL_INSTALL_DIR} --with-pic --disable-extra-programs")
set(THIRD_PARTY_AUTOMAKE_OPTIONS "--host=${COMPILE_PLATFORM_HOST}")

if (REBUILD_ALL_THIRD_LIBRARY)
        execute_process(
            COMMAND rm -rf ${THIRD_PARTY_INSTALL_DIR}
            RESULT_VARIABLE COMMAND_RESULT
        )
endif (REBUILD_ALL_THIRD_LIBRARY)

##### find library #####
find_library(NOPOLL_LIB
        NAMES ${THIRD_LIBRARY_NAME}
        PATHS ${THIRD_PARTY_INSTALL_DIR}/lib
        PATH_SUFFIXES "/lib"
        NO_DEFAULT_PATH
        )
message(STATUS "nopoll lib find path = ${THIRD_PARTY_INSTALL_DIR}")

message(STATUS "find nopoll library result is ${NOPOLL_LIB}")

if (NOPOLL_LIB STREQUAL "NOPOLL_LIB-NOTFOUND")
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

install (
        DIRECTORY ${THIRD_PARTY_INSTALL_DIR}
        DESTINATION ${CMAKE_BINARY_DIR}/thirdparty/
)


set(NOPOLL_INSTALL_DIR "${3RD_PREBUILD_PATH}/${THIRD_LIBRARY_NAME}/${COMPILE_PLATFORM_HOST}/${THIRD_LIBRARY_NAME}"  CACHE STRING "nopoll install dir" FORCE)
message(STATUS "nopoll install path = ${NOPOLL_INSTALL_DIR}")

set(NOPOLL_INCLUDE_DIRS "${NOPOLL_INSTALL_DIR}/include" CACHE STRING "libnopoll include" FORCE)
set(NOPOLL_LIB_PATH "${NOPOLL_INSTALL_DIR}/lib" CACHE STRING "libnopoll lib path" FORCE)
if (BUILD_STATICLIB)
        set(NOPOLL_LIBRARIES "${NOPOLL_LIB_PATH}/libnopoll.a" CACHE STRING "libnopoll lib" FORCE)
else ()
        set(NOPOLL_LIBRARIES "${NOPOLL_LIB_PATH}/libnopoll.so" CACHE STRING "libnopoll lib" FORCE)
endif()

message(STATUS "nopoll librares = ${NOPOLL_LIBRARIES}")

install (
        DIRECTORY ${NOPOLL_INSTALL_DIR}
        DESTINATION ${CMAKE_BINARY_DIR}/thirdparty/
)
