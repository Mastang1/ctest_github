#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdbool.h>


typedef struct circular_buf_t {
	char * buffer;
	size_t head;
	size_t tail;
	size_t max; //of the buffer
	bool full;
}circular_buf_t;




/// Handle type, the way users interact with the API
typedef circular_buf_t* cbuf_handle_t;

/// Pass in a storage buffer and size, returns a circular buffer handle
/// Requires: buffer is not NULL, size > 0
/// Ensures: cbuf has been created and is returned in an empty state
cbuf_handle_t circular_buf_init(size_t size);

/// Free a circular buffer structure
/// Requires: cbuf is valid and created by circular_buf_init
/// Does not free data buffer; owner is responsible for that
void circular_buf_free(cbuf_handle_t cbuf);


int circular_buf_put_range(cbuf_handle_t cbuf, char* data, size_t len);


int circular_buf_copy_range(cbuf_handle_t cbuf, char *data, size_t  len);


#endif //CIRCULAR_BUFFER_H_
