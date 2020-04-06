#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

int main(int argc, char *argv[])
{
    int fd[2], fd2[2];;
    pid_t pid;
    if (argc != 3)
    {
        printf("usage: %s dir arg\n", argv[0]);
        exit(1);
    }

    pipe(fd);
    pipe(fd2);
    
    pid = fork();
    if(pid > 0) {
        close(fd[READ]);
        dup2(fd[WRITE], STDOUT_FILENO);
        execlp("ls", "ls", argv[1], "-laR", NULL);
    }
    else if(pid == 0)
    {
        pid_t pid2;
        pid2 = fork();

        close(fd[WRITE]);
        
        if(pid2 > 0) {
            
            close(fd2[READ]);
            dup2(fd[READ], STDIN_FILENO);
            dup2(fd2[WRITE], STDOUT_FILENO);
            execlp("grep", "grep", argv[2], NULL);
        }
        else {
            close(fd2[WRITE]);
            dup2(fd2[READ], STDIN_FILENO);
            execlp("sort", "sort", NULL);
            close(fd2[READ]);
        }
    }
    exit(0);
}