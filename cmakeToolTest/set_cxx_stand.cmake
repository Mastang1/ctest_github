#####################################################################
#
#       该文件用于了解学习comparision 选择，结构也不错
#
# set c++ norm value, these values will be used for comparision later
set(CXX_NORM_CXX98 1)   # C++98
set(CXX_NORM_CXX03 2)   # C++03
set(CXX_NORM_CXX11 3)   # C++11
 
# Set the wanted C++ norm
# Adds the good argument to the command line in function of the compiler
macro(set_cxx_norm NORM)
    # Extract c++ compiler --version output
    #change from cmake 3.0 execute_process()
    exec_program(
        ${CMAKE_CXX_COMPILER}
        ARGS --version
        OUTPUT_VARIABLE _compiler_output
    )
    # Keep only the first line
    string(REGEX REPLACE
        "(\n.*$)"
        ""
        cxx_compiler_version "${_compiler_output}"
    )
    # Extract the version number
    string(REGEX REPLACE
        "([^0-9.])|([0-9.][^0-9.])"
        ""
        cxx_compiler_version "${cxx_compiler_version}"
    )
 
    # Set the specific C++ norm According 'NORM'
    if(${NORM} EQUAL ${CXX_NORM_CXX98})
        add_definitions("-std=c++98")
    elseif(${NORM} EQUAL ${CXX_NORM_CXX03})
        add_definitions("-std=c++03")
    elseif(${NORM} EQUAL ${CXX_NORM_CXX11})
        if(${cxx_compiler_version} VERSION_LESS "4.7.0")
            add_definitions("-std=c++0x")
        else()
            add_definitions("-std=c++11")
        endif()
    endif()
 
endmacro()