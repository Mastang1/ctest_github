#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

template <class T>
class MyArray
{
public:

    /*从键盘读数据到数组*/
    void readData(int n)
    {
        cout<<"请输入数组:"<<endl;
        for(int i = 0;i<n; i++)
        {
            cin>>arr[i];
        }
        cout<<"输入完毕!"<<endl;
    };

    /*将数组数据保存到文件中*/
    void saveFile(int n)
    {
        ofstream file;
        file.open("xie.txt", ios::in);//打开文件,可以指定位置,在双引号里加 D:\\C++语言测试\\xie.txt
        if(!file)
        {
            cout<<"xyz.txt cannot open"<<endl;
            abort();//用于中止当前进程。 对于异常的程序终止–我们可以使用abort()函数 。
        }

        for (int i = 0; i < n; i++)
            file << i << "  " << fixed << setprecision(8) << arr[i] << endl;//fixed << setprecision(8)是为了保留小数点后8位进行写入

        file.close();//关闭文件，保存文件。
        cout<<"已保存到文件中"<<endl;
    };
    
    /*求数组中的最大元素*/
    void maxArray(int n)
    {
        T maxNum = arr[0];
        for(int i = 1;i<n;i++)
            if(arr[i] > maxNum)
                maxNum = arr[i];
        cout<<"max: "<<maxNum<<endl;
    }
private:
    T arr[20];//定义一个通用数组,也就是说可以存储整数数组,也可以存储浮点数数组等等
};


int main()
{
    cout<<"------------------------传入整数数据---------------------------"<<endl;
    MyArray<int> myarray1;
    myarray1.readData(5);
    myarray1.saveFile(5);
    myarray1.maxArray(5);
    cout<<"------------------------传入小数数据---------------------------"<<endl;
    MyArray<double> myarray2;
    myarray2.readData(5);
    myarray2.saveFile(5);
    myarray2.maxArray(5);

    return 0;
}

