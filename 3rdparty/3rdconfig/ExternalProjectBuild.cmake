include(ExternalProject)
function(ExternalLibBuild TargetName GitRepository GitTag SourceDir ReadyCommand CfgArgs AutomakeArgs)
    message(STATUS "ReadyCommand:${ReadyCommand} targetname:${TargetName}")
    if(${TargetName} STREQUAL "NOPOLL_BUILD")
        message(STATUS "NOPOLL module build")
        ExternalProject_Add(${TargetName}
                PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/3rdconfig/.ExternalProject/${TargetName}
                TMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdconfig/.ExternalProject/tmp
                LIST_SEPARATOR " "

                GIT_REPOSITORY ${GitRepository}
                GIT_TAG ${GitTag}

                SOURCE_DIR ${SourceDir}
                CONFIGURE_COMMAND ${SourceDir}/${ReadyCommand} ${AutomakeArgs} COMMAND ${SourceDir}/configure ${CfgArgs}

                BUILD_IN_SOURCE 1
                BUILD_COMMAND make
                BUILD_ALWAYS FALSE

                INSTALL_COMMAND make install #COMMAND make clean

                LOG_CONFIGURE 1
                LOG_BUILD 1
                LOG_INSTALL 1
                )
    elseif(${TargetName} STREQUAL "MBEDTLS_BUILD")
        message(STATUS "MBEDTLS module BUILD")
        message(STATUS "repository:${GitRepository} gittag:${GitTag} sourcedir:${SourceDir}")
        ExternalProject_Add(${TargetName}
            PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/3rdconfig/.ExternalProject/${TargetName}
            TMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdconfig/.ExternalProject/tmp
            LIST_SEPARATOR " "
            GIT_REPOSITORY ${GitRepository}
            GIT_TAG ${GitTag}
            
            SOURCE_DIR ${SourceDir}
            CONFIGURE_COMMAND "" 
            BUILD_IN_SOURCE 1
            BUILD_COMMAND make
            BUILD_ALWAYS FALSE

            # INSTALL_COMMAND make install COMMAND make clean
            INSTALL_COMMAND ""
            # INSTALL_COMMAND cd ${InstallDir} && sudo make install

            LOG_CONFIGURE TRUE
            LOG_BUILD TRUE
            LOG_INSTALL TRUE
            LOG_DOWNLOAD TRUE
            LOG_UPDATE TRUE
            LOG_PATCH TRUE
            LOG_TEST TRUE
            LOG_MERGED_STDOUTERR TRUE
            LOG_OUTPUT_ON_FAILURE TRUE
            )
    elseif(${TargetName} STREQUAL "OPENSSL_BUILD")
        message(STATUS "OPENSSL module BUILD")
        ExternalProject_Add(${TargetName}
                PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/3rdconfig/.ExternalProject/${TargetName}
                TMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdconfig/.ExternalProject/tmp
                LIST_SEPARATOR " "

                GIT_REPOSITORY ${GitRepository}
                GIT_TAG ${GitTag}

                SOURCE_DIR ${SourceDir}
                CONFIGURE_COMMAND ${SourceDir}/${ReadyCommand} ${CfgArgs} COMMAND sed -i "s/-m64//" ${SourceDir}/Makefile

                BUILD_IN_SOURCE 1
                BUILD_COMMAND make
                BUILD_ALWAYS FALSE

                INSTALL_COMMAND make install COMMAND make clean

                LOG_CONFIGURE 1
                LOG_BUILD 1
                LOG_INSTALL 1
                )
    else()
        ExternalProject_Add(${TargetName}
                PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/3rdconfig/.ExternalProject/${TargetName}
                TMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdconfig/.ExternalProject/tmp
                LIST_SEPARATOR " "

                GIT_REPOSITORY ${GitRepository}
                GIT_TAG ${GitTag}

                SOURCE_DIR ${SourceDir}
                CONFIGURE_COMMAND ${SourceDir}/${ReadyCommand} COMMAND ${SourceDir}/configure ${CfgArgs}

                BUILD_IN_SOURCE 1
                BUILD_COMMAND make
                BUILD_ALWAYS FALSE

                INSTALL_COMMAND make install COMMAND make clean

                LOG_CONFIGURE 1
                LOG_BUILD 1
                LOG_INSTALL 1
                )
    endif()
endfunction(ExternalLibBuild)