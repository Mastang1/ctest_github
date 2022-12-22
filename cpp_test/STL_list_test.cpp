#if 0
#include <list>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;
int main()
{
    std::list<uint64_t> list_entity;
    for(int i=0;i<10;i++){
        list_entity.push_back(i);
    }

    list<uint64_t>::iterator it = list_entity.begin();

    for(;it != list_entity.end();it++){             //it  为指针
        printf("\n> %X", *it);
    }

    return 1;
}

#endif

#if 1
#include <stdio.h>

int main()
{
    int opt = 0;
    switch (opt) {
    case 0:
                      //do############
    case 1:
        printf("\n###########1\n");
    case 2:
        printf("\n###########2\n");
        break;
    case 3:
        printf("\n###########3\n");
        break;     
    default:

        break;
    }
    return 0;
    
}

#endif
