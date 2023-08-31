#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
int pid;
pid = fork(); /* fork a child process */
if (pid< 0) /* error occurred */
{
fprintf(stderr, "Fork Failed");
return 1;
}
else if (pid == 0) 
execlp("/bin/wc","wc",NULL);
else
{
/* parent will wait for the child to complete */
printf("Child Complete");
}
return 0;
}
