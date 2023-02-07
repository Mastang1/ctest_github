// this_thread::sleep_for example
/**
 * @file test_sleep_for.cpp
 * @author your name (you@domain.com)
 * @brief ------------- c++标准时间库 chrono<计时的> 可暂不理会
 * @version 0.1
 * @date 2023-02-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#if 0
#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
 
int main() 
{
  std::cout << "countdown:\n";
  for (int i=10; i>0; --i) {
    std::cout << i << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(1));
  }
  std::cout << "Lift off!\n";

  return 0;
}

#endif

#if 1
// example for thread::operator=
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
 
void pause_thread(int n) 
{
  std::this_thread::sleep_for (std::chrono::seconds(n));
  std::cout << "pause of " << n << " seconds ended\n";
}

int main() 
{
  std::thread threads[5];                         // default-constructed threads

  std::cout << "Spawning 5 threads...\n";
  for (int i=0; i<5; ++i)

    /* -------- 该部分的核心测试项目在于此 --------- */
    threads[i] = std::thread(pause_thread,i+1);   // move-assign threads

  std::cout << "Done spawning threads. Now waiting for them to join:\n";
  for (int i=0; i<5; ++i)
    threads[i].join();

  std::cout << "All threads joined!\n";

  return 0;
}

#endif