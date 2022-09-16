#include "core_precomp.hpp"
#include "os_adapter.hpp"
#include "ubicai/core/encoding_convert.hpp"
#include "ubicai/core/strext.hpp"
#include "ubicai/core/strutil.hpp"

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

#ifndef WIN32
const int THRD_STACK_SIZE = 1024 * 1024;
#endif

namespace uai { namespace core {

int OS_GetTimeOfDay(struct timeval *tp, void *tzp)
{
#if defined(_UAI_WIN_)
	time_t clock;
	struct tm tm_tm;
	SYSTEMTIME wtm;

	GetLocalTime(&wtm);
	tm_tm.tm_year = wtm.wYear - 1900;
	tm_tm.tm_mon = wtm.wMonth - 1;
	tm_tm.tm_mday = wtm.wDay;
	tm_tm.tm_hour = wtm.wHour;
	tm_tm.tm_min = wtm.wMinute;
	tm_tm.tm_sec = wtm.wSecond;
	tm_tm.tm_isdst = -1;
	clock = mktime(&tm_tm);
	tp->tv_sec = static_cast<long>(clock);
	tp->tv_usec = wtm.wMilliseconds * 1000;
#else
#ifdef __IOS__
	gettimeofday(tp, tzp);
#else
	//gettimeofday(tp,tzp);
	gettimeofday(tp, 0);
#endif
#endif
	return (0);
}

int64_t OS_GetTimeStamp()
{
	timeval t;
	OS_GetTimeOfDay(&t, 0);
    int64_t time = t.tv_sec;
    time *= 1000;
    time += t.tv_usec / 1000;
	return time;
}

DLL_MODULE OS_LoadLibrary(const char * dllPathName)
{
	DLL_MODULE handle = 0;
#ifdef _WIN32_WCE
	handle = LoadLibraryW(ANSIToUnicode(dllPathName).c_str());
#elif defined(_UAI_WIN_)
	handle = LoadLibrary(dllPathName);
	if (handle == 0)
	{
		LOG_ERR("LoadLibrary failed:%d", GetLastError());
	}
#else
	handle = dlopen(dllPathName, RTLD_NOW);
	if (handle == 0)
	{
		LOG_ERR("dlopen failed:%s", dlerror());
	}
#endif
	return handle;
}

void * OS_GetProcAddress(DLL_MODULE handle, const char * funName)
{
#ifdef _WIN32_WCE
	return GetProcAddress((HMODULE)handle, ANSIToUnicode(funName).c_str());
#elif defined(_UAI_WIN_)
	return GetProcAddress((HMODULE)handle, funName);
#else
	return dlsym((void*)handle, funName);
#endif
}

void OS_FreeLibrary(DLL_MODULE handle)
{
#ifdef _UAI_WIN_
	FreeLibrary((HMODULE)handle);
	return;
#else
	dlclose((void*)handle);
	return;
#endif
}

unsigned long OS_GetPID()
{
#ifdef _UAI_WIN_
	return GetCurrentProcessId();
#else
	return getpid();
#endif
}

unsigned long OS_GetTID()
{
#ifdef _UAI_WIN_
	return GetCurrentThreadId();
#else
	return (unsigned long)pthread_self();
#endif
}


bool JLocalTime(struct tm *ptm, time_t & timeValue)
{
	ASSERT(ptm && timeValue);
	if (ptm == 0 || timeValue == 0)
	{
		return false;
	}
	struct tm *pLocaltm;
	static ThreadMutex local_time_lock;
	local_time_lock.Lock();
	pLocaltm = localtime(&timeValue);
	ASSERT(pLocaltm);
	memcpy(ptm, pLocaltm, sizeof(tm));
	local_time_lock.Unlock();
	return true;
}

int OS_MakeDir(const char* path)
{
#ifdef _WIN32_WCE
	wstring wPath = ANSIToUnicode(path);
	return CreateDirectory(wPath.c_str(), 0);
#elif defined (WIN32)
	return _mkdir(path);
#else
	return mkdir(path, 0777);
#endif
}

//��GBKװutf8 ��ȡΪ���ߺ���
bool OS_IsValidThreadID(THREAD_ID id)
{
	if (id == THREAD_ID_NULL)
	{
		return false;
	}
	return true;
}

THREAD_ID OS_CreateThread(THREAD_PROC pvFunc, void *pArg, E_THREAD_FLAG eFlag, unsigned int /*nStackSize*/)
{
#ifdef _WIN32_WCE
	DWORD dwID;
	HANDLE hHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)pvFunc, pArg, 0, &dwID);
	if (hHandle != 0)
	{
		if (E_DETACH_THREAD == eFlag)
		{
			CloseHandle(hHandle);
		}
	}

	return (THREAD_ID)hHandle;

#elif defined(_UAI_WIN_)
	unsigned int nThread = _beginthreadex(0, 0, (unsigned int(__stdcall*)(void*))pvFunc, pArg, 0, 0);
	if (0 != nThread)
	{
		if (E_DETACH_THREAD == eFlag)
		{
			CloseHandle((HANDLE)nThread);
			nThread = 0;
		}
		return nThread;
	}
	else
	{
		return (unsigned int)-1;
	}

#else
	pthread_t id = 0;
	pthread_attr_t thrdAttr;
	const int nInit = pthread_attr_init(&thrdAttr);
	if (0 != nInit)
	{
		return id;
	}
	pthread_attr_setstacksize(&thrdAttr, THRD_STACK_SIZE);

	int nRet = pthread_create(&id, &thrdAttr, (void*(*)(void*))pvFunc, pArg);
	if (0 == nRet)
	{
		if (E_DETACH_THREAD == eFlag)
		{
			pthread_detach(id);
		}
		return id;
	}
	else
	{
		return 0;
	}

#endif
}

void OS_JoinThread(THREAD_ID unThrdID)
{
#ifdef WIN32
	//WaitForSingleObject((HANDLE)unThrdID, INFINITE);
	while (1)
	{
		unsigned long dwExitCode;
		if (GetExitCodeThread((HANDLE)unThrdID, &dwExitCode) == 0 ||
			dwExitCode != STILL_ACTIVE)
		{
			break;
		}
		OS_SleepMS(10);
	}
#else
	pthread_join(unThrdID, 0);
#endif
}

bool OS_GetAppName(string &app_name)
{

#ifdef _WIN32_WCE
	wchar_t this_path[256] = { 0 };
	int ret_len = GetModuleFileNameW((HMODULE)GetCurrentProcess(), this_path, 255);
	if (ret_len == 0)
		return false;

	string str = UnicodeToANSI(this_path);

	size_t n = str.rfind("\\");
	if (n == string::npos)
		app_name = str;
	else
		app_name = str.substr(n + 1, ret_len - n - 1);

#elif defined(_WIN32)
	char chAppName[MAX_APPNAEM_LEN] = { 0 };
	if (GetModuleBaseName(GetCurrentProcess(), 0, chAppName, MAX_APPNAEM_LEN) == 0)
		return false;
	app_name = chAppName;
	return true;
#elif defined __IOS__
	//	@autoreleasepool{
	//		NSString *pNSStrAppName;
	//		NSProcessInfo *processInfo;
	//		processInfo = [NSProcessInfo processInfo];
	//		pNSStrAppName = [processInfo processName];
	//		strcpy(pszName, [pNSStrAppName UTF8String]);
	//	}
	app_name = "Uplus";
	return true;
#else

	int iRet;
	char acSysFile[] = "/proc/self/exe";
	char chAppName[MAX_APPNAEM_LEN] = { 0 };

	if (-1 == readlink(acSysFile, chAppName, sizeof(chAppName)))
		return false;
	for (iRet = strlen(chAppName) - 1; iRet > 0; iRet--) {
		if (chAppName[iRet] == '/')
			break;
	}
	app_name = chAppName + iRet;
	return true;
#endif
}

bool OS_GetCurrentDateTime(string & date_time)
{
	time_t t;
	struct tm *local;

	char chDataBufferLength[MAX_DATETIME_LEN] = { 0 };
	t = time(0);
	local = localtime(&t);
	sprintf(chDataBufferLength, "%d-%d-%d %d:%d:%d", (local->tm_year + 1900),
		local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);

	date_time = chDataBufferLength;
	return true;
}
    
bool OS_GetCurrentDateTimeWithMilliSec(string & date_time) {
#ifdef WIN32
	return OS_GetCurrentDate(date_time);
#else
    char s_time[36] = {0};
    long millisec;
    struct tm* tm_info;
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    
    millisec = lrint(tv.tv_usec/1000.0); // Round to nearest millisec
    if (millisec>=1000) { // Allow for rounding up to nearest second
        millisec -=1000;
        tv.tv_sec++;
    }
    
    tm_info = localtime(&tv.tv_sec);
    if(tm_info == NULL)
    {
		date_time = "empty";
		printf("localtime() get null.\n");
		return true;
    }
    snprintf(s_time,sizeof(s_time)-1,"%4d-%2d-%02d %02d:%02d:%02d.%03ld",(1900+tm_info->tm_year),(1+tm_info->tm_mon),tm_info->tm_mday,tm_info->tm_hour, tm_info->tm_min,tm_info->tm_sec,millisec);
    date_time = s_time;
    return true;
#endif
}

bool OS_GetCurrentDateToNumberStringMilliSec(string &date_ms)
{
#ifdef WIN32
	return OS_GetCurrentDate(date_time);
#else
	char s_time[36] = {0};
	long millisec;
	struct tm *tm_info;
	struct timeval tv;

	gettimeofday(&tv, NULL);

	millisec = lrint(tv.tv_usec / 1000.0); // Round to nearest millisec
	if (millisec >= 1000)
	{ // Allow for rounding up to nearest second
		millisec -= 1000;
		tv.tv_sec++;
	}

	tm_info = localtime(&tv.tv_sec);
	if (tm_info == NULL)
	{
		date_ms = "empty";
		printf("localtime() get null.\n");
		return true;
	}
	snprintf(s_time, sizeof(s_time) - 1, "%4d%02d%02d%02d%02d%02d%03ld", (1900 + tm_info->tm_year), (1 + tm_info->tm_mon), tm_info->tm_mday, tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec, millisec);
	date_ms = s_time;
	return true;
#endif
}

bool OS_GetCurrentDataToNumberString(string &date) {
#ifdef WIN32
    return OS_GetCurrentDate(date);
#else
    char buffer[32];
    struct tm* tm_info;
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    tm_info = localtime(&tv.tv_sec);
    strftime(buffer, 32, "%Y%m%d%H%M%S", tm_info);
    date = buffer;
    return true;
#endif
}

bool OS_GetCurrentDate(string & date)
{
	time_t t;
	struct tm *local;

	char chDataBufferLength[MAX_DATETIME_LEN] = { 0 };
	t = time(0);
	local = localtime(&t);
	sprintf(chDataBufferLength, "%04d-%02d-%02d", (local->tm_year + 1900),
		local->tm_mon + 1, local->tm_mday);

	date = chDataBufferLength;
	return true;
}

static void GetCPUID(char *pszCPUID)
{
	unsigned long s1, s2, s3, s4;
	char p1[128], p2[128];
#if defined _WIN32_WCE || defined WIN64
	unsigned char vendor_id[] = "------------";
	s1 = s2 = s3 = s4 = 0;
#elif defined(_UAI_WIN_)
	unsigned char vendor_id[] = "------------";

	__asm {
		xor eax, eax
		cpuid
		mov dword ptr vendor_id, ebx
		mov dword ptr vendor_id[+4], edx
		mov dword ptr vendor_id[+8], ecx
	}
	__asm {
		mov eax, 01h
		xor edx, edx
		cpuid
		mov s1, edx
		mov s2, eax
	}

	__asm {
		mov eax, 03h
		xor ecx, ecx
		xor edx, edx
		cpuid
		mov s3, edx
		mov s4, ecx
	}
#else

	s1 = s2 = s3 = s4 = 0;
#endif

	sprintf((char *)p1, "%08lX%08lX", s1, s2);
	snprintf(pszCPUID, 16, "%s", (char *)p1);
	if (s3 == 0 && s4 == 0)
	{
		return;
	}
	sprintf((char *)p2, "%08lX%08lX", s3, s4);
	snprintf(pszCPUID + 16, 16, "%s\n", (char*)p2);
	return;
}

void OS_GetCpuId(string & strCPUID)
{
	char s_szCpuId[MAX_CPUID_LEN] = { 0 };
	if (strCPUID.empty())
	{
		GetCPUID(s_szCpuId);
	}
	strCPUID = s_szCpuId;
}

bool NormalizationPath(string& strPath)
{
	if (strPath.empty() == true)//��·��������
		return true;

	strPath = trim(strPath);

	int nLen = strPath.length();
	if (strPath.at(nLen - 1) != '/'
		&& strPath.at(nLen - 1) != '\\')
	{
#ifdef _UAI_WIN_
		strPath += '\\';
#else
		strPath += '/';
#endif
	}

	return true;
}

void OS_GetModuleFilePath(string &modulePath)
{
	char szBuff[MAX_MOUDULE_PATH_LEN];
	memset(szBuff, 0x00, sizeof(szBuff));
#ifdef _WIN32_WCE
	wchar_t path[256] = { 0 };
	GetModuleFileNameW(0, path, MAX_MOUDULE_PATH_LEN);
	string str = UnicodeToANSI(path);
	modulePath = str;
	modulePath.erase(modulePath.rfind("\\"));
#elif defined(_UAI_WIN_)
	GetModuleFileName(0, szBuff, MAX_MOUDULE_PATH_LEN);
	modulePath = szBuff;
	modulePath.erase(modulePath.rfind("\\"));
#else
	readlink("/proc/self/exe", szBuff, MAX_MOUDULE_PATH_LEN);
	modulePath = szBuff;
	modulePath.erase(modulePath.rfind("/"));
#endif
	NormalizationPath(modulePath);
	return;
}

void OS_SleepMS(long milli_second)
{
#ifdef _UAI_WIN_
	Sleep(milli_second);
#else
	usleep(milli_second * 1000);
#endif
}



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


//////////////////////////////////////////////////////////////////////////
// ThreadMutex member function

ThreadMutex::ThreadMutex()
{
	m_pvHandle = 0;
#ifdef WIN32
	m_pvHandle = new CRITICAL_SECTION;
	InitializeCriticalSection((CRITICAL_SECTION *)m_pvHandle);
#else
	m_pvHandle = new pthread_mutex_t;
	pthread_mutex_init((pthread_mutex_t*)m_pvHandle, 0);
#endif
}
ThreadMutex::~ThreadMutex()
{
	if (0 != m_pvHandle)
	{
#ifdef WIN32
		DeleteCriticalSection((CRITICAL_SECTION *)m_pvHandle);
		delete (CRITICAL_SECTION *)m_pvHandle;
#else
		pthread_mutex_destroy((pthread_mutex_t*)m_pvHandle);
		delete (pthread_mutex_t*)m_pvHandle;
#endif
	}
}

void ThreadMutex::Lock()
{
#ifdef WIN32
	EnterCriticalSection((CRITICAL_SECTION *)m_pvHandle);
#else
	pthread_mutex_lock((pthread_mutex_t *)m_pvHandle);
#endif
}
void ThreadMutex::Unlock()
{
#ifdef WIN32
	LeaveCriticalSection((CRITICAL_SECTION *)m_pvHandle);
#else
	pthread_mutex_unlock((pthread_mutex_t *)m_pvHandle);
#endif
}

#ifndef WIN32
pthread_mutex_t *ThreadMutex::getMutex()
{
    return (pthread_mutex_t *)m_pvHandle;
}
#endif

//////////////////////////////////////////////////////////////////////////
// ThreadGuard member function
ThreadGuard::ThreadGuard(ThreadMutex * pMutex)
{
	ASSERT(pMutex);
	m_pThreadMutex = pMutex;
	m_pThreadMutex->Lock();
}

ThreadGuard::~ThreadGuard()
{
	if (0 != m_pThreadMutex)
	{
		m_pThreadMutex->Unlock();
	}
}

Timestamp::Timestamp() : milliseconds_1970(0)
{

}
Timestamp::Timestamp(int64_t milliseconds) : milliseconds_1970(milliseconds)
{

}

Timestamp::~Timestamp()
{

}

Timestamp Timestamp::now()
{
	struct timeval tv;
	OS_GetTimeOfDay(&tv, 0);
	int64_t seconds = tv.tv_sec;
	return Timestamp(seconds * kMillisecondsPerSecond + tv.tv_usec / 1000);
}

int64_t Timestamp::operator -(const Timestamp &low_time)
{
	int64_t diff = milliseconds_1970 - low_time.milliseconds_1970;
	return diff;
}

Timestamp &Timestamp::operator =(const Timestamp &left_time)
{
	milliseconds_1970 = left_time.milliseconds_1970;
	return *this;
}

int Timestamp::ToSeconds()
{
	return int(milliseconds_1970 / kMillisecondsPerSecond);
}

}}
