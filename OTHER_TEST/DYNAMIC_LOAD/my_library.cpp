#include "my_library.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef  __cplusplus
extern "C" {
#endif


int myprintf(int input_arg)
{
    printf(" -- input val is : %d.\n", input_arg); 
    return 1;
}



#ifdef  __cplusplus
}
#endif


