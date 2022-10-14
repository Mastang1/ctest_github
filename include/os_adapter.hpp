#ifndef __UAI_CORE_OS_ADAPTER_HPP__
#define __UAI_CORE_OS_ADAPTER_HPP__

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <stdint.h>
#endif

#include <string>
using std::string;
#include <cstdint>

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

    enum E_THREAD_FLAG
    {
        E_THREAD_FLAG_UNKNOWN = -1,
        E_JOIN_THREAD,
        E_DETACH_THREAD,
        E_THREAD_FLAG_COUNT
    };

class Event
{
    public:
        Event();
        virtual ~Event();

        void Wait();
        // bool WaitSuccess(int nMillisecs = WT_INFINITE);
        void Set();
        void Set_broadcast();
        void Reset();

    private:
        EventHandle *m_pvHandle;
};


#endif