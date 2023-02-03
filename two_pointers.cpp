#if 0
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
#endif

#if 1
#include <iostream>
#include <stdio.h>
#include <string>
#include <functional>

using namespace std;



int main()
{
    unsigned int a, b, c;
    scanf("%d %d", &a, &b);
    c = a/b;
    printf("%d", c);

    return 0; 
}

#endif