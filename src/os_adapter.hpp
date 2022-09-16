#ifndef __UAI_CORE_OS_ADAPTER_HPP__
#define __UAI_CORE_OS_ADAPTER_HPP__

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <stdint.h>
#endif

#include "ubicai/core/uaidev.hpp"

#include <string>
using std::string;

namespace uai { namespace core {

#if defined(_MSC_VER) && _MSC_VER < 1600 /* MSVS 2010 */
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef signed __int64 int64_t;
typedef unsigned __int64 uint64_t;
#elif defined(_MSC_VER) || __cplusplus >= 201103L
#include <cstdint>
using std::int8_t;
using std::uint8_t;
using std::int16_t;
using std::uint16_t;
using std::int32_t;
using std::uint32_t;
using std::int64_t;
using std::uint64_t;
#else
typedef ::int8_t int8_t;
typedef ::uint8_t uint8_t;
typedef ::int16_t int16_t;
typedef ::uint16_t uint16_t;
typedef ::int32_t int32_t;
typedef ::uint32_t uint32_t;
typedef ::int64_t int64_t;
typedef ::uint64_t uint64_t;
#endif

#ifdef WIN32
    typedef HMODULE DLL_MODULE;
#else
    typedef void* DLL_MODULE;
#endif

#ifdef WIN32
    typedef unsigned int THREAD_ID;
#define THREAD_ID_NULL -1
#else
    typedef pthread_t THREAD_ID;
#define THREAD_ID_NULL 0
#endif

#if defined(WIN32) || defined(WIN64)
# if !defined(_UAI_WIN_)
#   define _UAI_WIN_
# endif
#endif

#define MAX_APPNAEM_LEN 256
#define MAX_DATETIME_LEN 128
#define MAX_CPUID_LEN 256
#define MAX_MOUDULE_PATH_LEN (256)

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

    typedef void* (*THREAD_PROC)(void *pvParam);


    int64_t OS_GetTimeStamp();

    DLL_MODULE OS_LoadLibrary(const char * dllPathName);
    void * OS_GetProcAddress(DLL_MODULE handle,const char * funName);
    void OS_FreeLibrary(DLL_MODULE handle);

    bool OS_IsValidThreadID(THREAD_ID id);
    THREAD_ID OS_CreateThread(THREAD_PROC pvFunc, void *pArg,E_THREAD_FLAG eFlag,unsigned int nStackSize);
    void OS_JoinThread(THREAD_ID unThrdID);

    unsigned long OS_GetPID();
    unsigned long OS_GetTID();
    bool OS_GetAppName(string &app_name);
    bool OS_GetCurrentDateTime(string & date_time);
    bool OS_GetCurrentDateTimeWithMilliSec(string & date_time);
    bool OS_GetCurrentDateToNumberStringMilliSec(string &date_ms);
    bool OS_GetCurrentDataToNumberString(string &date);
    bool OS_GetCurrentDate(string & date);
    void OS_GetCpuId(string & strCPUID);

    bool OS_NormalizationPath( string& strPath );
    void OS_GetModuleFilePath(string &modulePath);

    void OS_SleepMS(long milli_second);

    int OS_MakeDir(const char* path);

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

    class UAI_EXPORTS ThreadMutex
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

#ifndef WIN32
    class UAI_EXPORTS CondVar
    { 
    public:
        CondVar() { pthread_cond_init(&m_cond, NULL); }
        virtual ~CondVar() { pthread_cond_destroy(&m_cond); }
 
        int wait(ThreadMutex &mutex) { return  pthread_cond_wait(&m_cond, mutex.getMutex()); }
        int signal() { return pthread_cond_signal(&m_cond); } 
        int broadcast() { return pthread_cond_broadcast(&m_cond); } 
 
    private:
        pthread_cond_t  m_cond;
    };
#endif

    class UAI_EXPORTS ThreadGuard
    {
        public:
            ThreadGuard(ThreadMutex * pMutex);
            ~ThreadGuard();
            /*
               void Lock();
               void Unlock();
               */
        private:
            ThreadMutex * m_pThreadMutex;
    };

    class CriticalSection
    {
        public:
            CriticalSection();
            ~CriticalSection();

            void Entry();
            void Leave();

        private:
            void *m_pvHandle;
    };

    class Timestamp
    {
        public:
            Timestamp();
            explicit Timestamp(int64_t milliseconds);
            ~Timestamp();

        public:
            static Timestamp now();
            int64_t operator -(const Timestamp &low_time);
            Timestamp &operator =(const Timestamp &left_time);
            int ToSeconds();
            int64_t ToMilliseconds()
            {
                return milliseconds_1970;
            }

        private:
            int64_t milliseconds_1970;
            static const int kMillisecondsPerSecond = 1000;
    };

}}

#endif // __UAI_CORE_OS_ADAPTER_HPP__
