#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>



int main(){
	pid_t pid;
	int status;

	pid = fork();
if(pid<0){
	fprintf(stderr,"Fork failed\n");
	return 1;
}
else if(pid==0){
	printf("Child Process : pid : %d \n",getpid());
	execl("/bin/ls","ls",NULL);

	perror("execl");
	return 1;
}else{
	printf("Parent process : pid = %d \n",getpid());
	sleep(5);
	wait(&status);
	if(WIFEXITED(status)){
		printf("Child process exited with status %d\n",WEXITSTATUS(status));
	}
}
return 0;
}
