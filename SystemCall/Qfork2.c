#include<stdio.h>
#include<unistd.h>

int main(){


	pid_t pid;


	printf("Before fork() \n");

	pid = fork();

	if( pid < 0 ){
		fprintf(stderr, "Fork failed\n");
		return 1;
	}
	else if(pid == 0 ){
		printf("Child process : pid = %d\n ",getpid());
		sleep(2);
		printf("Child process : woke up\n");
	}
	else{
		printf("Parent process : pid  %d \n",getpid());
		sleep(1);
		printf("Parent process: Woke up\n");
	}
	printf("after fork()\n");
	return 0;
}
