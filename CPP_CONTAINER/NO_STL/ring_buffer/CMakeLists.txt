add_executable( ringbuffer_test ringbuffer_test.cpp QRingBuffer.cpp)
target_link_libraries(ringbuffer_test ${CMAKE_THREAD_LIBS_INIT})