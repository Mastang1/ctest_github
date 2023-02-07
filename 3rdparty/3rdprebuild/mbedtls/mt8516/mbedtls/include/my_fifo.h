#ifndef _MY_FIFO_H_
#define _MY_FIFO_H_

#ifdef __cplusplus 
extern "C"
{ 
#endif

//#define Debug_mx 

#include <pthread.h>  

struct my_fifo{
	char * buffer;
	unsigned int size;
	unsigned int in_ptr;
	unsigned int out_ptr;
	unsigned int count;
	pthread_mutex_t lock;
	pthread_cond_t cond;
};

struct  my_fifo * my_fifo_alloc(unsigned int size_bytes);
int my_fifo_free(struct  my_fifo *myfifo);//成功返回1
int my_fifo_clear(struct  my_fifo *myfifo);//成功返回1
int my_fifo_get(struct  my_fifo *myfifo, void * buffer, unsigned int len_bytes);
int my_fifo_put(struct  my_fifo *myfifo, void * buffer, unsigned int len_bytes);
int get_fifo_size(struct  my_fifo *myfifo);
int get_fifo_count(struct  my_fifo *myfifo);

int putfifotofifo(struct my_fifo * fifodest, struct my_fifo * fifosrc);
int my_fifo_get_end(struct  my_fifo *myfifo, void * buffer, unsigned int len);
#ifdef __cplusplus 
}
#endif

#endif
