/*
 * @Author: tangyapeng tangyapeng@haier.com
 * @Date: 2023-04-11 17:23:42
 * @LastEditors: tangyapeng tangyapeng@haier.com
 * @LastEditTime: 2023-04-11 17:33:37
 * @FilePath: /ctest_gitnub/COMMUNICATION/EVENT_WRAPPER/event_wrapper.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#ifndef __EVENT_WRAPPER_HPP__
#define __EVENT_WRAPPER_HPP__

#include <pthread.h>

/* type define */
	typedef struct tagEventHandle
	{
#ifdef WIN32
		HANDLE hEvt;
#else
		pthread_mutex_t mutex;
		pthread_cond_t cond;
		int nSignal;
#endif
	} EventHandle;


    class Event
    {
        public:
            enum WT
            {
                WT_INFINITE = 0x7FFFFFFF,		// Wait infinite
            };

        public:
            Event();
            virtual ~Event();

            void Wait(int nMillisecs = WT_INFINITE);
            bool WaitSuccess(int nMillisecs = WT_INFINITE);
            void Set();
            void Reset();

        private:
			EventHandle *m_pvHandle;
    };


    class  ThreadMutex
    {
        public:
            ThreadMutex();
            virtual ~ThreadMutex();
            virtual void Lock();
            virtual void Unlock();
#ifndef WIN32
            virtual pthread_mutex_t *getMutex();
#endif
        private:
            void * m_pvHandle;
    };




#endif