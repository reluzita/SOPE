#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define MAXLINE 500
#define PAGER "sort"
#define READ 0
#define WRITE 1

int main(int argc, char *argv[])
{
    char buffer[255];
    int fd[2], file_fd, nr, n_itens=0;
    pid_t pid;
    FILE *fpin, *fpout;
    if (argc != 2)
    {
        printf("usage: %s filename\n", argv[0]);
        exit(1);
    }
    char* line = NULL;

    if(pipe(fd) < 0) {
        exit(1);
    }
    pid = fork();
    if(pid > 0) {
        close(fd[READ]);
        dup2(fd[WRITE], STDOUT_FILENO);
        execlp("cat", "cat", argv[1], NULL);
    }
    else
    {
        close(fd[WRITE]);
        dup2(fd[READ], STDIN_FILENO);
        execlp(PAGER, PAGER, NULL);
    }
    
    exit(0);
}