#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){

	// make two process which run same
	// // program after this instruction
	fork();
	printf("hello \n");
	return 0;
}
