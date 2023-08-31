#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) { 
        printf("Child process is executing...\n");
        execl("/bin/ls", "ls", "-l", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else { 
        printf("Parent process is going to sleep...\n");
        sleep(5); 
        printf("Parent process woke up!\n");
        wait(NULL); 
    }

    return 0;}
