
#include "QRingBuffer.hpp"
#include <string.h>
#include <stdio.h>

using namespace std;

namespace typ{
namespace common{

// ThreadMutex QRingBuffer::_mutex;
/**
 * @brief QRingBuffer::QRingBuffer
 * @param buffersize Byte
 */
QRingBuffer::QRingBuffer(int size) {
	rbBuf = new unsigned char[size];
	bufferSize = size;
	rbCapacity = size;
	rbBuff = rbBuf;
	ptr_w = ptr_r = rbBuff;
	pthread_mutex_init(&_mutex, NULL);
}

QRingBuffer::~QRingBuffer() {
	rbBuff = NULL;
	ptr_w = NULL;
	ptr_r = NULL;
	rbCapacity = 0;
	delete[] rbBuf; //释放缓冲区
	pthread_mutex_destroy(&_mutex);
}
/**
 * @brief QRingBuffer::rbCanRead
 * @return 缓冲区可读字节数
 */
int QRingBuffer::canRead() {
	int ret = 0;
	if ((NULL == rbBuff) || (NULL == ptr_r) || (NULL == ptr_w)) {
		printf("can read:%d\n", 0);
		return 0;
	}

	if (ptr_r <= ptr_w) {
		ret = ptr_w - ptr_r;
	} else {
		ret = rbCapacity - (ptr_r - ptr_w);
	}
	return ret;
}

/**
 * @brief QRingBuffer::rbCanWrite  缓冲区剩余可写字节数
 * @return  可写字节数
 */
int QRingBuffer::canWrite() {
	if ((NULL == rbBuff) || (NULL == ptr_r) || (NULL == ptr_w)) {
		return 0;
	}

	return rbCapacity - canRead();
}

/**
 * @brief QRingBuffer::read 从缓冲区读数据
 * @param 目标数组地址
 * @param 读的字节数
 * @return
 */
int QRingBuffer::read(char *data, int count) {
	if ((NULL == rbBuff) || (NULL == ptr_r) || (NULL == ptr_w)) {
		return 0;
	}
	if (NULL == data) {
		printf("lional data == null\n");
		return 0;
	}
	pthread_mutex_lock(&_mutex);
	int r = canRead();
	if (r < count) {
		pthread_mutex_unlock(&_mutex);
		return 0;
	}
	if (ptr_r < ptr_w) {
		memcpy(data, ptr_r, count);
		ptr_r += count;
		pthread_mutex_unlock(&_mutex);
		return count;
	} else {
		int tail = rbCapacity - (ptr_r - rbBuff);
		if (count < tail) {
			memcpy(data, ptr_r, count);
			ptr_r += count;
			pthread_mutex_unlock(&_mutex);
			return count;
		} else {
			memcpy(data, ptr_r, tail);
			ptr_r = rbBuff;
			memcpy(data + tail, ptr_r, count - tail);
			ptr_r += (count - tail);
			pthread_mutex_unlock(&_mutex);
			return count;
		}
	}
}

/**
 * @brief QRingBuffer::write
 * @param 数据地址
 * @param 要写的字节数
 * @return 写入的字节数
 */
int QRingBuffer::write(const char *data, int count) {
	
	//int tailAvailSz = 0;

	if ((NULL == rbBuff) || (NULL == ptr_w) || (NULL == ptr_r)) {
		return 0;
	}

	if (NULL == data) {
		return 0;
	}
	pthread_mutex_lock(&_mutex);
	if (count > canWrite()) {
		pthread_mutex_unlock(&_mutex);
		return 0;
	}

	if (ptr_r <= ptr_w) {
		int tail = rbCapacity - (ptr_w - rbBuff);
		if (count < tail) {
			memcpy(ptr_w, data, count);
			ptr_w += count;
			pthread_mutex_unlock(&_mutex);
			return count;
		} else {
			memcpy(ptr_w, data, tail);
			ptr_w = rbBuff;
			memcpy(ptr_w, data + tail, count - tail);
			ptr_w += (count - tail);
			pthread_mutex_unlock(&_mutex);
			return count;
		}
	} else {
		memcpy(ptr_w, data, count);
		ptr_w += count;
		pthread_mutex_unlock(&_mutex);
		return count;
	}
}
void QRingBuffer::clear() {
	pthread_mutex_lock(&_mutex);
	ptr_w = ptr_r = rbBuff;
	pthread_mutex_unlock(&_mutex);
}
void QRingBuffer::clearTo(int bytes) {
	pthread_mutex_lock(&_mutex);
	int r = canRead();
	if (r <= bytes) {
		pthread_mutex_unlock(&_mutex);
		return;
	}
	int count=r-bytes;
	if (ptr_r < ptr_w) {
		ptr_r += count;
		pthread_mutex_unlock(&_mutex);
		return;
	} else {
		int tail = rbCapacity - (ptr_r - rbBuff);
		if (count < tail) {
			ptr_r += count;
			pthread_mutex_unlock(&_mutex);
			return;
		} else {
			ptr_r = rbBuff;
			ptr_r += (count - tail);
			pthread_mutex_unlock(&_mutex);
			return;
		}
	}
}
/**
 * @brief QRingBuffer::size
 * @return 缓冲区大小
 */
int QRingBuffer::size() {
	return bufferSize;
}

}}
