#include <iostream>
#include <string>
#include <functional>

using namespace std;

class test
{
public:
    test() {}

    void print(const std::string &str)
    {
        std::cout << __func__ << "() " << str << std::endl;
    }

    ~test() {}
};

int main(int argc, char **argv)
{
    test t;

    auto func = &test::print;
    (t.*func)("ffff");
    return 0;
}



//====================================================
// #include <iostream>
// #include <string>
// #include <condition_variable>
// #include <mutex>
// #include <thread> 
// //#include <pthread.h>

// using namespace std;

// unsigned char my_Hex[] = {0};

// void ToolsByte2Hex(unsigned char bData,unsigned char hex[])
// {
//     int high=bData/16,low =bData %16;
//     hex[0] = (high <10)?('0'+high):('A'+high-10);
//     hex[1] = (low <10)?('0'+low):('A'+low-10);
// }

// int main(int argc, char *argv[]) {

//     ToolsByte2Hex('!',my_Hex);
//     cout<<my_Hex[0]<<my_Hex[1]<<endl;

//     return 0;
// }