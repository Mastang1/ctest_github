
#if 0
#include<stdio.h>
#include<vector>
#include <iostream>
#include <stdio.h>


using namespace std;

int  main()

{
    int i = 0;
    vector<uint8_t> test_vector;
    for( i = 0; i < 10; i++ ){
        test_vector.push_back( i );                           //把元素一个一个存入到vector中
    }
    //*******************************************************
    vector<uint8_t>::iterator p = test_vector.begin();
	
	//++p;
	
	for (; p!=test_vector.end(); ++p)
	{
        printf("\n %u \n", p);
	}

    return 1;
}

#endif

#if 1

#include <stdio.h>

int main()
{

    int a = 1;
    switch (a)
    {
        case 0:
        printf("\n case 0 \n");

        case 1:
        printf("\n case 1 \n");

        case 2:
        printf("\n case 2\n");

        default:
        break;
    }

    return 1;
}
#endif