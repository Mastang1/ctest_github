#if 1
/**
 * @file test_seek_tell.cpp
 * @author your name (you@domain.com)
 * @brief ifstream class test
 * @version 0.1
 * @date 2023-04-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

int main () {
  std::ifstream is ("/home/tang/tmp/data/uai_log.txt", std::ifstream::in);
  if (is) {
    // get length of file:
    uint32_t tmp_int = 10;
    is.seekg (tmp_int, is.beg);
    int length = is.tellg();
    is.seekg (0, is.beg);

    std::cout << length <<std::endl;

  }

  return 0;
}

#endif