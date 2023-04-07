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