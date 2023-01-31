#if 0
// 测试一下，可以获取在文件流中的光标位置


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


#if 0

// stoi example  测试采用标准c++11，执行string类到数值变换  整形
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi

int main ()
{
  std::string str_dec = "2001, A Space Odyssey";
  std::string str_hex = "40c3";
  std::string str_bin = "-10010110001";
  std::string str_auto = "0x7f";

  std::string::size_type sz;   // alias of size_t

  int i_dec = std::stoi (str_dec,&sz);
  int i_hex = std::stoi (str_hex,nullptr,16);
  int i_bin = std::stoi (str_bin,nullptr,2);
  int i_auto = std::stoi (str_auto,nullptr,0);

  std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
  std::cout << str_hex << ": " << i_hex << '\n';
  std::cout << str_bin << ": " << i_bin << '\n';
  std::cout << str_auto << ": " << i_auto << '\n';

  return 0;
}

#endif


#if 0
//   C++的处理还是比较方便的
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi

int main ()
{
  std::string str_dec = "2001, A Space Odyssey";
  std::string str_hex = "40c3";
  std::string str_bin = "-10010110001";
  std::string str_auto = "0x7f";

  std::string::size_type sz;   // alias of size_t

  int i_dec = std::stoi (str_dec,nullptr,10);
  int i_hex = std::stoi (str_hex,nullptr,16);
  int i_bin = std::stoi (str_bin,nullptr,2);
  int i_auto = std::stoi (str_auto,nullptr,0);

  std::cout << str_dec << ": " << i_dec <<std::endl;
  std::cout << str_hex << ": " << i_hex << '\n';
  std::cout << str_bin << ": " << i_bin << '\n';
  std::cout << str_auto << ": " << i_auto << '\n';

  return 0;
}

#endif


#if 0
// read a file into memory
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


/*
  C stdio FILE test
  C++ stream ，refer to SDK gtest code
*/
#if 0
/* fread example: read an entire file */
#include <stdio.h>
#include <stdlib.h>

int main () {
  FILE * pFile;
  long lSize;
  char * buffer;
  size_t result;

  pFile = fopen ( "myfile.bin" , "rb" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  // obtain file size:
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);

  // allocate memory to contain the whole file:
  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  result = fread (buffer,1,lSize,pFile);
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

  /* the whole file is now loaded in the memory buffer. */

  // terminate
  fclose (pFile);
  free (buffer);
  return 0;
}


#endif


#if 1
/* fsetpos example */
#include <stdio.h>

int main ()
{
  FILE * pFile;
  fpos_t position;

  pFile = fopen ("myfile.txt","w");
  fgetpos (pFile, &position);
  fputs ("That is a sample",pFile);
  fsetpos (pFile, &position);
  fputs ("This",pFile);
  fclose (pFile);
  return 0;
}

#endif