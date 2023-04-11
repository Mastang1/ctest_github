# add_subdirectory(EVENT_WRAPPER)

set(module_name "EVENT")
string(APPEND module_EVENT_path ${module_name} "_path")
set(module_EVENT_path ${CMAKE_CURRENT_SOURCE_DIR}/EVENT_WRAPPER)
include_directories(${module_EVENT_path})

message(STATUS " -- the path is : ${module_EVENT_path}")
message(STATUS " -- ${CMAKE_THREAD_LIBS_INIT}")

add_library(${module_name} SHARED ${module_EVENT_path}/event_wrapper.cpp ${module_EVENT_path}/event_wrapper.hpp)
target_link_libraries(${module_name} ${CMAKE_THREAD_LIBS_INIT})
# CMAKE_THREAD_LIBS_INIT mean: -lpthread
# add_library(${module_name} STATIC ${module_EVENT_path}/event_wrapper.cpp ${module_EVENT_path}/event_wrapper.hpp)


add_executable(test_com_threads test_com_threads.cpp)
target_link_libraries(test_com_threads EVENT)
