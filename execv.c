#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
       printf("Child process: My PID is %d\n", getpid());
        execl("/bin/ls", "ls", "-l", NULL);
    } 
    else if (pid > 0) 
    {
     printf("Parent process: My PID is %d\n", getpid());
        wait(NULL);
        printf("Parent process: Child process has terminated\n");
    } 
    else
     {
      perror("fork");
    }

    return 0;
}

