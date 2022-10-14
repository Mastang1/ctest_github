

#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <semaphore.h>
#include <dlfcn.h>
#include <errno.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "os_adapter.hpp"

Event::Event()
{
	m_pvHandle = new EventHandle;

	pthread_mutex_init(&m_pvHandle->mutex, 0);
	pthread_cond_init(&m_pvHandle->cond, 0);
	m_pvHandle->nSignal = 0;
}

Event::~Event()
{
	if (0 != m_pvHandle)
	{
#ifdef WIN32
		CloseHandle(m_pvHandle->hEvt);
		m_pvHandle->hEvt = 0;
#else
		pthread_mutex_destroy(&m_pvHandle->mutex);
		pthread_cond_destroy(&m_pvHandle->cond);
#endif

		delete m_pvHandle;
		m_pvHandle = 0;
	}
}

void Event::Wait()
{
	if (0 != m_pvHandle)
	{

		while (m_pvHandle->nSignal == 0)
		{
			pthread_cond_wait(&m_pvHandle->cond, &m_pvHandle->mutex);
		}
		m_pvHandle->nSignal--;
		pthread_mutex_unlock(&m_pvHandle->mutex);

	}
}

void Event::Set()
{
	if (0 != m_pvHandle)
	{
#ifdef WIN32
		SetEvent(m_pvHandle->hEvt);
#else
		pthread_mutex_lock(&m_pvHandle->mutex);
		m_pvHandle->nSignal++;
		pthread_mutex_unlock(&m_pvHandle->mutex);
		pthread_cond_signal(&m_pvHandle->cond);
#endif
	}
}


void Event::Set_broadcast()
{
	if (0 != m_pvHandle)
	{

	pthread_mutex_lock(&m_pvHandle->mutex);
	m_pvHandle->nSignal++;
	pthread_mutex_unlock(&m_pvHandle->mutex);
	pthread_cond_broadcast(&m_pvHandle->cond);

	}
}

void Event::Reset()
{
	if (0 != m_pvHandle)
	{
#ifdef WIN32
		ResetEvent(m_pvHandle->hEvt);
#else
		pthread_mutex_lock(&m_pvHandle->mutex);
		m_pvHandle->nSignal = 0;
		pthread_mutex_unlock(&m_pvHandle->mutex);
#endif
	}
}

