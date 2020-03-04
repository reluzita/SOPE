#include<stdio.h> 
#include<unistd.h> 
#include<sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid, pidSon;
    int status;
    pid = fork();
    if (pid > 0)
    {
        pidSon = wait(&status);
        printf(" world!");
    }
    else
    {
        printf("Hello");
        exit(getpid() % 10);
    }
    return 0;
}