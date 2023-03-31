/**
 * @file test_for_each.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-30
 * 
 * @copyright Copyright (c) 2023
 * 
 template<class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function fn)
{
  while (first!=last) {
    fn (*first);
    ++first;
  }
  return fn;      // or, since C++11: return move(fn);
}
 */
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> vec;
    size_t count = 10;
    for (size_t i = 0; i < count; i++)
    {
        vec.push_back(i + 1);
    }

    std::for_each(vec.begin(), vec.end(), [&](int value)        
                  { std::cout << value << std::endl; });        //遍历每个元素，并将其作为fun的参数，执行函数  fun
    system("pause");
    return 0;
}
