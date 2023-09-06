
#include<stdio.h>
#include<unistd.h>

void forkexample(){
	//child process because return value zero
	(fork() ==0) ?printf("Hello from child!\n"):printf("hello from parent!\n");
}
int main(){

	forkexample();
	return 0;
}
