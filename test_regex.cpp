/**
 * @file regex_match
 * @author your name (you@domain.com)
 * @brief 
                    bool std::regex_match(...)
                    bool std::regex_search(...)
                    string std::regex_replace(...)//实际上返回类型是根据你输入的数据类型对应的basic_string类。
 * @version 0.1
 * @date 2023-01-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#if 0
/**
 *  bool std::regex_match(...)
 */
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::regex pattern("\\d{4}");
    std::string content("hello_2018");
    std::smatch result;

    if (std::regex_match(content, result, pattern)) {
        std::cout << result[0];
    }
    return 0;
}


#endif



#if 0
/**
 *  bool std::regex_search(...)
 */
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::regex pattern("\\d{4}");
    std::string content("hello_2018 by_2017");
    std::smatch result;

    if (std::regex_search(content, result, pattern)) {
        std::cout << result[0] << result.size();
    }
    return 0;
}

#endif


#if 1
/**
 *  bool std::regex_search(...)  search substring
 */
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::regex pattern("\\d{4}");
    std::string content("hello_2018 by_2017");
    std::smatch result;

    auto begin = content.cbegin();
    auto end = content.cend();

    while (std::regex_search(begin, end, result, pattern)) {
        std::cout << result[0] << result.size()<<std::endl;
        begin = result[0].second;
    }

    return 0;
}

#endif

#if 0
/**
 *  bool std::regex_replace(...)  
 */
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::regex pattern("\\d{4}");
    std::string content("hello_2018 by_2017");

    std::string result = std::regex_replace(content, pattern, "everyone");
    std::cout << result;

    return 0;
}
#endif

/**
 * @brief 正则表达式常用模式
 * 
 语法规则：

    \ 表示将下一字符标记为特殊字符、转义字符；          # 主要与下边/w等配合
        \w 表示任意字母、数字、下划线 ；

        \s 表示任意空白符(tab也包含在内)；

        \d 表示匹配单个数字字符，\D 表示非数字字符匹配；


    ^表示字符串的开始，匹配输入字符串开始的位置；

    $表示字符串的结尾，匹配输入字符串结尾的位置；

    . 表示匹配除换行符" \n "以外的任意字符；

    *****************************************************************************
    *********** *   []内部放的是    字符范围表达式          * ***************
        [] 表示一个字符集合，匹配指定范围内的任何字符，例如[a-z]表示字母a~z所组成的集合；

        []中使用^来表示集合的补集，匹配不在指定的范围内的任何字符，例如[^1-3]表示除1 2 3以外数字；

        [[:alpha:]] 表示任何字母；

        [[:alnum:]] 表示任何字母和数字；
    *****************************************************************************

    regex::icase 表示匹配时忽略大小写；

    *****************************************************************************
        {n} 表示正好匹配 n 次  [前面的字符或表达式]，例如"hello{6}",匹配字符串中符合第二个l后边有6个o的子字符串；

        {n, } 表示至少匹配 n 次  前面的字符或表达式；

        {n,m} 表示匹配至少 n 次，至多 m 次  前面的字符或表达式；
    ----------------------------------------------------------------------------
        *表示零次或多次匹配前面的字符或子表达式，等效于{0, }；

        +表示一次或多次匹配前面的字符或子表达式；

        ? 表示零次或一次匹配前面的字符或子表达式；
    *****************************************************************************  

    \t \n \r这些平时非常常见，分别表示制表符匹配、换行符匹配、回车符匹配。

 */