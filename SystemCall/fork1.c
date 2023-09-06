#include<stdio.h>
#include<unistd.h>

int main(){

	pid_t pid;

	pid = fork();

	if(pid <0){
		fprintf(stderr,"Fork Failed\n");
		return 1;
	}else if(pid==0){
		//child Process
		printf("Child process: PID=%d\n",getpid());
		printf("Hello\n");
	}else{
                //Parent Process
                printf("Parent process: PID=%d\n",getpid());
                printf("Hi\n");
        }    
	return 0;
}
