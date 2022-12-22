#include <iostream>
#include <string>
#include <functional>

using namespace std;



int main(int argc, char **argv)
{
    char* arr[2] = {"nice", "day"};
    char **p = arr;
    printf("%s", p[0]);

    return 0; 
}
