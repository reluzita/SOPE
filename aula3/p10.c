#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *envp[])
{
    pid_t pid;
    int status, p;
    char *arg[]={"ls","-laR", argv[1], NULL}; 
    if (argc < 2)
    {
        printf("usage: %s dirname\n", argv[0]);
        exit(1);
    }
    pid = fork();
    if (pid > 0){    
        printf("I'm the parent (PID=%d)\n\n",getpid()); 
    }
    else if (pid == 0)
    {
        if (argc == 3) {
            p = open(argv[2], O_WRONLY | O_CREAT, 0644);
            dup2(p, STDOUT_FILENO);
        }
        execv("/bin/ls",arg);
        printf("Command not executed !\n");
        exit(1);
    }
    exit(0);
}