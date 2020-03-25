#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define READ 0
#define WRITE 1

struct xy {
    char x[1];
    char y[1];
};

int main(void)
{
    int fd[2];
    pid_t pid;
    pipe(fd);
    pid = fork();
    if (pid > 0)
    {
        //struct xy box;
        char a[2][5];
        printf("PARENT:\n");
        printf("x y ? ");
        scanf("%s %s", a[0], a[1]);
        close(fd[READ]);
        write(fd[WRITE], a, 10);
        close(fd[WRITE]);
    }
    else
    {
        //struct xy box2;
        char b[2][5];
        close(fd[WRITE]);
        read(fd[READ], b, 10);
        printf("SON:\n");
        printf("x + y = %d\n", atoi(b[0]) + atoi(b[1]));
        close(fd[READ]);
    }
    return 0;
}