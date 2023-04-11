/*
 * @Author: tangyapeng tangyapeng@haier.com
 * @Date: 2023-04-11 17:23:55
 * @LastEditors: tangyapeng tangyapeng@haier.com
 * @LastEditTime: 2023-04-11 17:40:45
 * @FilePath: /ctest_gitnub/COMMUNICATION/EVENT_WRAPPER/event_wrapper.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "event_wrapper.hpp"
#ifdef WIN32
#include <Psapi.h>		//support GetModuleBaseName()
#include <io.h>
#include <direct.h>
#include <process.h>
#else
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <semaphore.h>
#include <dlfcn.h>
#include <errno.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <assert.h>
#include <math.h>

/**
 * @description:  class enent function defined
 * @return {*}
 */
Event::Event()
{
	m_pvHandle = new EventHandle;

#ifdef _WIN32_WCE
	m_pvHandle->hEvt = CreateEventW(0, FALSE, FALSE, 0);
	if (0 == m_pvHandle->hEvt)
	{
		delete m_pvHandle;
		m_pvHandle = 0;
	}
#elif defined(WIN32)
	m_pvHandle->hEvt = CreateEvent(0, FALSE, FALSE, 0);
	if (0 == m_pvHandle->hEvt)
	{
		delete m_pvHandle;
		m_pvHandle = 0;
	}
#else
	pthread_mutex_init(&m_pvHandle->mutex, 0);
	pthread_cond_init(&m_pvHandle->cond, 0);
	m_pvHandle->nSignal = 0;
#endif
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

void Event::Wait(int nMillisecs)
{
	if (0 != m_pvHandle)
	{
#ifdef WIN32
		WaitForSingleObject(m_pvHandle->hEvt, nMillisecs);
#else
		pthread_mutex_lock(&m_pvHandle->mutex);
		if (m_pvHandle->nSignal > 0)
		{
			m_pvHandle->nSignal--;
		}
		else
		{
			if (WT_INFINITE != nMillisecs && nMillisecs >= 0)
			{
				timeval now;
				gettimeofday(&now, 0);
				timespec timeout;
				timeout.tv_sec = now.tv_sec + nMillisecs / 1000;
				timeout.tv_nsec = (now.tv_usec + (nMillisecs % 1000) * 1000) * 1000;
				timeout.tv_sec += timeout.tv_nsec / 1000000000;
				timeout.tv_nsec %= 1000000000;

                int nRet;
                do {
                     nRet = pthread_cond_timedwait(&m_pvHandle->cond, &m_pvHandle->mutex, &timeout);
                } while (nRet != ETIMEDOUT && m_pvHandle->nSignal == 0);
                
                if (ETIMEDOUT != nRet)
                {
                    m_pvHandle->nSignal--;
                }
			}
			else
			{
				while (m_pvHandle->nSignal == 0)
                {
                    pthread_cond_wait(&m_pvHandle->cond, &m_pvHandle->mutex);
                }
                m_pvHandle->nSignal--;
			}
		}
		pthread_mutex_unlock(&m_pvHandle->mutex);
#endif
	}
}

bool Event::WaitSuccess(int nMillisecs)
{
	if (0 != m_pvHandle)
	{
#ifdef WIN32
		return WAIT_OBJECT_0 == WaitForSingleObject(m_pvHandle->hEvt, nMillisecs);
#else
		bool bRet = true;
		pthread_mutex_lock(&m_pvHandle->mutex);
		if (m_pvHandle->nSignal > 0)
		{
			m_pvHandle->nSignal--;
			bRet = true;
		}
		else
		{
			if (WT_INFINITE != nMillisecs && nMillisecs >= 0)
			{
				timeval now;
				gettimeofday(&now, 0);
				timespec timeout;
				timeout.tv_sec = now.tv_sec + nMillisecs / 1000;
				timeout.tv_nsec = (now.tv_usec + (nMillisecs % 1000) * 1000) * 1000;
				timeout.tv_sec += timeout.tv_nsec / 1000000000;
				timeout.tv_nsec %= 1000000000;
                
                int nRet;
                do {
                    nRet = pthread_cond_timedwait(&m_pvHandle->cond, &m_pvHandle->mutex, &timeout);
                } while (nRet != ETIMEDOUT && m_pvHandle->nSignal == 0);
                
                if (ETIMEDOUT != nRet)
                {
                    m_pvHandle->nSignal--;
                } else {
                    bRet = false;
                }
			}
			else
			{
                while (m_pvHandle->nSignal == 0)
                {
                    pthread_cond_wait(&m_pvHandle->cond, &m_pvHandle->mutex);
                }
                m_pvHandle->nSignal--;
			}
		}
		pthread_mutex_unlock(&m_pvHandle->mutex);
		return bRet;
#endif
	}
	return true;
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

