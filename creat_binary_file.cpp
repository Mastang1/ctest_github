
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    FILE * pFile;
    long lSize;
    char buffer[320] = {0x00};
    size_t result;
    memset(buffer,0x00, 320);
    pFile = fopen ( "audio_mute.pcm" , "wrb+" );
    if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

    for(int i=0; i< 3000; i++){
        fwrite(buffer, 1, 320, pFile);
    }


    fclose (pFile);

    return 0;
}