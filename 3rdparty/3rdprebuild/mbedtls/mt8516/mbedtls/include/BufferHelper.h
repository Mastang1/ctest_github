#ifndef __BUFFER_HELPER_H__
#define __BUFFER_HELPER_H__
#include <string.h>

class ByteBuffer
{
public:
    ByteBuffer()
    {
        buffer_ = NULL;
        buffer_len_ = 0;
        need_free_ = true;
    }

	ByteBuffer(const ByteBuffer* bytebuffer)
	{
		if (bytebuffer == NULL || bytebuffer->buffer_ == NULL || bytebuffer->buffer_len_ == 0)
		{
			buffer_ = NULL;
			buffer_len_ = 0;
			need_free_ = true;
			return;
		}
		buffer_len_ = bytebuffer->buffer_len_;
		buffer_ = new unsigned char[buffer_len_];
		memcpy(buffer_,bytebuffer->buffer_,buffer_len_);
		need_free_ = true;
	}
    
    ~ByteBuffer()
    {
        if (need_free_ && buffer_ != NULL)
        {
            delete[] buffer_;
            buffer_ = NULL;
        }
        buffer_len_ = 0;
    }
    
    unsigned char *buffer_;
    int buffer_len_;
    bool need_free_;
};


class ShortBuffer
{
public:

	ShortBuffer()
	{
		buffer_ = NULL;
		buffer_short_len_ = 0;
		need_free_ = true;
	}

	ShortBuffer(short * shrtbuff,int len,bool free = false)
	{
		buffer_ = shrtbuff;
		buffer_short_len_ = len;
		need_free_ = free;
	}

	ShortBuffer(const ByteBuffer* byteBuffer,bool free = false)
	{
        if (byteBuffer == NULL) {
            buffer_ = NULL;
            buffer_short_len_ = 0;
            need_free_ = true;
            return;
        }
		buffer_ = (short*)byteBuffer->buffer_;
		buffer_short_len_ = byteBuffer->buffer_len_ / sizeof(short);
		need_free_ = free;
	}

	~ShortBuffer()
	{
		if (need_free_ && buffer_ != NULL)
		{
			delete[] buffer_;
			buffer_ = NULL;
		}
		buffer_short_len_ = 0;
	}

	int getByteLength()const{
		return buffer_short_len_ * sizeof(short);
	}

	short *buffer_;
	int buffer_short_len_;
	bool need_free_;
};


#define WavBuffer ShortBuffer

#endif