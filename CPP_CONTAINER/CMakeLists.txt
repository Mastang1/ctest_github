


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/NO_STL/ring_buffer)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/NO_STL/blocking_queue)

add_executable(container_queue container_queue.cpp)
add_executable(container_vector container_vector.cpp)
add_executable(container_string container_string.cpp)
