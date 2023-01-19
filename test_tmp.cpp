
#if 0
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	string StrToTest("Tesla");
	string StrAfterCopy;//拷贝构造
	cout<<"StrAfterCopy : "<<StrAfterCopy<<endl;

	cout<<"StrToTest : "<<StrToTest<<endl;

	/*    string insert test      front insert*/
	StrToTest.insert(0, "Nikola ");
	cout<<"字符串插入操作：  "<<StrToTest<<endl;

	/* * *     通过迭代器遍历       * * */
	for(string::iterator it = StrToTest.begin(); it != StrToTest.end(); it++){
		StrAfterCopy.push_back(*it);
	}
	cout<<"StrAfterCopy: "<<StrAfterCopy<<endl;

	/************** 字符查找 no return -1******************/
	cout<<"found result is : "<<StrToTest.find('a')<<endl;
	cout<<"found from position 7: "<<StrToTest.find('a',7)<<endl;

	/************  末尾开始查找   *********************/
	cout<<"found from tail 2: "<<StrToTest.rfind('a')<<endl;
	// cout<<"found from tail 0: "<<StrToTest.rfind('a', 3)<<endl;  //不可用

	/*********** 查找另一个串中包含 或者 不包含的字符  ********/
	string str_tmp("Typ");
	cout<<"find_first_of: "<<StrToTest.find_first_of(str_tmp)<<endl;
	
	cout<<"find_first_not_of: "<<StrToTest.find_first_not_of("Nikolp")<<endl;  //5 which is 'p'

	/********* 排序  need include algorithm *********************/
	string StrToSort("49286157tndlas");
	sort(StrToSort.begin(),StrToSort.end());
	cout<<"after sort : "<<StrToSort<<endl;

	/*******  分割子串**************/
	string str_base("name: Nikola Tesla");
	int position_name = str_base.find(':');
	string str_name = str_base.substr(position_name+1);//截取位置会包含当前position; 2个参数， position and the length of string

	cout<<"splid name is :"<< str_name << endl;
	return 0;
}

#endif

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	if (2 && strncmp("bd", "nice", 1)) {
// 		printf("\n -- result is true. \n");
// 	}else{
// 		printf("\n -- result is false. \n");	
// 	}
// 	return 0;
// }


#if 0
/**
 * @file test_tmp.cpp
 * @author your name (you@domain.com)
 * @brief C not zero ,mean true
 * @version 0.1
 * @date 2023-01-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <string.h>

int main()
{
	if (2 && -4) {
		printf("\n -- result is true. \n");
	}else{
		printf("\n -- result is false. \n");	
	}
	return 0;
}

#endif