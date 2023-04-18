
add_library(renegade SHARED  my_library.cpp my_library.h)
# set_target_properties( renegade
#     PROPERTIES
#     ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
#     LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
#     # RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
# )

add_executable(dynamic_loading_test dynamic_loading_test.cpp)
target_link_libraries(dynamic_loading_test -ldl)
# add_dependencies(dynamic_loading_test renegade)