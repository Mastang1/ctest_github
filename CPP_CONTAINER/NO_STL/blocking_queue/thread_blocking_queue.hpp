#ifndef __UAIBOT_COMMON_THREAD_BLOCKING_QUEUE_HPP__
#define __UAIBOT_COMMON_THREAD_BLOCKING_QUEUE_HPP__

#include "ubicai/core/os_adapter.hpp"
#include <queue>

namespace uaibot { namespace common {

template <typename T>
class ThreadBlockingQueue
{
public:
	ThreadBlockingQueue();

	void enqueue(T elem);
	T	dequeue();
	bool empty();

private:
	std::queue<T> m_queue;
	uai::core::Event m_addDone;
	uai::core::ThreadMutex m_mutex;

};

template<typename T>
ThreadBlockingQueue<T>::ThreadBlockingQueue()
{
	m_addDone.Reset();
}

template<typename T>
void ThreadBlockingQueue<T>::enqueue(T elem) {
	m_mutex.Lock();
	m_queue.push(elem);
	m_mutex.Unlock();
	m_addDone.Set();
}

template<typename T>
T ThreadBlockingQueue<T>::dequeue() {
	m_mutex.Lock();
	while (m_queue.empty()) {
		m_mutex.Unlock();
		m_addDone.Wait();
		m_mutex.Lock();
	}
	T t = m_queue.front();
	m_queue.pop();
	m_mutex.Unlock();
	return t;
}

template<typename T>
bool ThreadBlockingQueue<T>::empty()
{
	bool empty;
	m_mutex.Lock();
	empty = m_queue.empty();
	m_mutex.Unlock();
	return empty;
}

}
}


#endif // __UAIBOT_COMMON_THREAD_BLOCKING_QUEUE_HPP__
