include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src DIR_SRCS)
add_executable(test_inherit_class test_inherit_class.cpp )