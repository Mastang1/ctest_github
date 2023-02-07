#ifndef _LOCKWRAPPER_H_
#define _LOCKWRAPPER_H_

#include "common.h"
//#ifndef PTHREAD_MUTEX_INITIALIZER
//# define PTHREAD_MUTEX_INITIALIZER   { { 0, 0, 0, 0, 0, 0, { 0, 0 } } }
//#endif



#ifdef WIN32
	#include <windows.h>
	//#include <Winbase.h>

namespace haier{
	typedef int cs_lock_t;

	inline void init_lock(cs_lock_t* lock)
	{
		//InitializeCriticalSection(lock);
	}

	inline void cs_lock(cs_lock_t* lock)
	{
		 //EnterCriticalSection(lock);
	}

	inline void cs_unlock(cs_lock_t* lock)
	{
		 //LeaveCriticalSection(lock);
	}

	inline void destroy_lock(cs_lock_t* lock)
	{
		//DeleteCriticalSection(lock);
	}
}
#else
	#include <pthread.h>

namespace haier{
	typedef pthread_mutex_t cs_lock_t;

	inline void init_lock(cs_lock_t* lock)
	{
//		*lock = PTHREAD_MUTEX_INITIALIZER;
		pthread_mutex_init ( lock, NULL);
	}

	inline void cs_lock(cs_lock_t* lock)
	{
		 pthread_mutex_lock(lock);
	}

	inline void cs_unlock(cs_lock_t* lock)
	{
		 pthread_mutex_unlock(lock);
	}

	inline void destroy_lock(cs_lock_t* lock)
	{

	}
}
#endif


#endif

