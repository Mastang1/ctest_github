#ifndef _ALLOC_SPACE_H_
#define _ALLOC_SPACE_H_

//#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include <math.h>

namespace haier{


char ** Alloc2d(int dim1, int dim2, int size);
int Free2d(char **mat);
char ***Alloc3d(int dim1, int dim2, int dim3, int size);
int Free3d(char ***mat);

}

#endif
