#include <iostream>
#include <string>
#include <condition_variable>
#include <mutex>
#include <thread> 
//#include <pthread.h>

using namespace std;

void IncreaseWithLockGuard(int *value,std::mutex *m3x){
    for (int i = 0; i < 10000; ++i) {
        std::lock_guard<std::mutex> lock(*m3x);
        *value+=1;
    }
}

void IncreaseWIthLockUnlock(int *value,std::mutex *m3x){
    for (int i = 0; i < 10000; ++i) {
        m3x->lock();
        *value+=1;
        m3x->unlock();
    }
}

int main(int argc, char *argv[]) {
    mutex m3x;
    int value = 0;
    thread th0(IncreaseWithLockGuard,&value,&m3x);
    thread th1(IncreaseWithLockGuard,&value,&m3x);
    th0.join();
    th1.join();
    cout << "value:" << value << endl;
    return 0;
}