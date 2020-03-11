#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h>

int main(int argc, char *argv[], char *envp[])
{
    pid_t pid;
    int status;
    char *arg[]={"ls","-laR", argv[1], NULL}; 
    if (argc != 2)
    {
        printf("usage: %s dirname\n", argv[0]);
        exit(1);
    }
    pid = fork();
    if (pid > 0){    
        wait(&status);     
        printf("I'm the parent (PID=%d)\n\n",getpid());   
        if(WIFEXITED(status))   
            printf("My son exited with EXIT CODE = %d\n",WEXITSTATUS(status));
        else if(WIFSIGNALED(status))
            printf("oopsies %d\n", WTERMSIG(status));
    }
    else if (pid == 0)
    {
        execv("/bin/ls",arg);
        printf("Command not executed !\n");
        exit(1);
    }
    exit(0);
}