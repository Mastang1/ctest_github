

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