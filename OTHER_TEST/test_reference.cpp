/**
 *  test stream and reference
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * functions
*/
// 因为字符串常量为常量，临时变量也为常量
//而在C++中，这些临时对象都是const类型的
void test_1(const string &r_a)
{
    string tmp_str(r_a);
    cout << tmp_str << endl;
}


class DataStream
{
private:
    /* data */
    vector <int> m_data;
public:
    DataStream(/* args */);
    ~DataStream();
    DataStream& operator<<(int input_)
    {
        m_data.push_back(input_);
        return *this;
    }
    void Display(){
        vector<int>::iterator it = m_data.begin();

        cout <<" -- display:" <<endl;
        for(; it != m_data.end();it++){
            cout << *it << endl;
        }
    }
};

DataStream::DataStream(/* args */)
{
}

DataStream::~DataStream()
{
}



int main()
{
    /* 引用变量作为参数 */
    test_1("today is a nice day.");


    /*运算符重载*/
    DataStream my_stream;
    for(int i=0;i<100;i++){
        my_stream<<i;
    }
    my_stream.Display();


    /* 引用作为返回值 */

    return 0;
}

