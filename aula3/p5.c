#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid, pid2;
    int status, status2;
    pid = fork();
    if (pid > 0)
    {
        wait(&status);
        printf(" friends!\n");
    }
    else
    {
        pid2 = fork();
        if (pid2 > 0)
        {
            wait(&status2);
            printf(" my");
        }
        else
        {
            printf("Hello");
            exit(getpid() % 10);
        }
    }
    return 0;
}