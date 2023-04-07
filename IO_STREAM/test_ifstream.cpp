#if 1
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

using namespace std;
int main () {
    ifstream in_fs;
    string str_line;
    char cstr_buffer[1024] = "0";
    
    in_fs.open("/home/tang/tmp_workspace/test.txt", ios_base::in);

    if(!in_fs.is_open()){
    cout<< "File open failed!"<<endl;
    }
    
    in_fs.read(cstr_buffer, 1024);
    cout << " -- CBuffer context: " << cstr_buffer << endl;

    cout << " -- Current position : " << in_fs.tellg() <<endl;

    if(getline(in_fs, str_line)){
        cout << " -- Current line text :" << str_line <<endl;
    }

    cout << " -- Current position : " << in_fs.tellg() <<endl;



  return 0;
}

#endif