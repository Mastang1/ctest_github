#[[
    test multiple thread function
]]#
add_executable (cpp11_lock_guard cpp11_lock_guard.cpp)
target_link_libraries(cpp11_lock_guard ${CMAKE_THREAD_LIBS_INIT})