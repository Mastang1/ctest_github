#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc ,char **argv){
	
	
	if(system("date") == -1){
		printf("execl filed!\n");
		
		perror("becasue");
	}
	printf("system successful\n");
	return 0;
}

