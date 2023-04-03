/**
 * @file string_proc.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-30
 * 
 * @copyright Copyright (c) 2023
 * 总结：
 * 	-- 赋值、拼接： += .append() =(赋值) assign(赋值) .insert(int pos, 字符串或者再加一个字符串长度) 可用resize(sizeNow+n, 'char')实现字符串内存初始化 clear清空当前内存
 *  -- 字符访问： at [] front back
 *  -- capacity： erase(pos, length) 擦除几个字符
 *  -- function： find find_first_of  sub_str获取子串 
 *  -- npos 常用语在find的返回位置比较，若是=npos，则说明没有发现该子串
 *  -- 其他的有c语言中 <string.h> memcpy memncpy strcpy
 *  -- sscanf()字符串匹配，获取对应的数据到变量中 sprintf() snprintf()字符串拼接到变量中，添加字符串结束符 
 */

/* 字符串拷贝，便于获取子串？？？ */
/*
	需要注意，添加字符 '\0'
	std::size_t length = str.copy(buffer,6,5);
	buffer[length]='\0';
*/

#if 1
// string::copy
#include <iostream>
#include <string>

int main ()
{
  char buffer[20];
  std::string str ("Test string...");
  std::size_t length = str.copy(buffer,6,5);
  buffer[length]='\0';
  std::cout << "buffer contains: " << buffer << '\n';
  return 0;
}

#endif





/* erase 删除后，会自动重新填补空间 */
#if 0
// string::erase
#include <iostream>
#include <string>

int main ()
{
  std::string str ("This is an example sentence.");
  std::cout << str << '\n';
                                           // "This is an example sentence."
  str.erase (10,8);                        //            ^^^^^^^^
  std::cout << str << '\n';
                                           // "This is an sentence."
  str.erase (str.begin()+9);               //           ^
  std::cout << str << '\n';
                                           // "This is a sentence."
  str.erase (str.begin()+5, str.end()-9);  //       ^^^^^
  std::cout << str << '\n';
                                           // "This sentence."
  return 0;
}

#endif



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


#if 0
/**
 * @file test_tmp.cpp
 * @author your name (you@domain.com)
 * @brief test "%*s" %.s 在printf 或者 scanf中的用法
 * @version 0.1
 * @date 2023-01-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/* sscanf example */
#include <stdio.h>

typedef struct Time_TYPE{
	int year;
	int month;
	int day;

	int hour;
	int min;
	int second;
	int msecond;
}Time_TYPE;

int main ()
{
	Time_TYPE my_time_t;
	char sentence []="2021-12-29 16:46:17.727";
	char str [20];
	char tmp;
	int i;

	sscanf (sentence,"%d-%d-%d %d:%d:%d.%d",
							&my_time_t.year,
							&my_time_t.month,
							&my_time_t.day,
							&my_time_t.hour,
							&my_time_t.min,
							&my_time_t.second,
							&my_time_t.msecond);

	int *p_tmp = (int *)&my_time_t; 
	int *p_end = (int *)&my_time_t.msecond;

	for(;p_tmp <= p_end;p_tmp++){
		printf("%d\n", *p_tmp);
	}
	return 0;
}
#endif


//int line_count = count(str_rslt.begin(),str_rslt.end(), '\n');      //除了标题外的行数，包括line  process 

#if 0
/**
 * @file test_tmp.cpp
 * @author your name (you@domain.com)
 * @brief test "%*s" %.*s 在printf 或者 scanf中的用法
 * %*s 用在scanf的输入中，表示这个字符串会被舍弃
 * %.*s 用在printf中，用于动态设置左右对齐
 * @version 0.1
 * @date 2023-01-19
 *
 * @copyright Copyright (c) 2023
 *
 */
/* sscanf example */
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif



int main()
{
	char sentence[] = "Tom is 12 years old";
	char str[1024];
	memset(str, '*', sizeof(str));
int i;
for(i=1;i<100;i+=2)
printf("%.*s\n", i, str);

//循环三次
// 第一次不输出空格，直接输出########
// 第二次输出一个空格，再输出########
// 第三次输出两个空格，再输出########
//大家可以自行验证


	return 0;
}

#ifdef __cplusplus
}
#endif

#endif

#if 0
// resizing string
#include <iostream>
#include <string>

int main ()
{
  std::string str ("I like to code in C");
  std::cout << str << '\n';

  unsigned sz = str.size();

  str.resize (sz+40,'*');
  std::cout << str << '\n';

  return 0;
}

#endif