#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

int main(void)
{
    int fd[2];
    int fd2[2];
    pid_t pid;
    pipe(fd);
    pipe(fd2);
    pid = fork();
    if (pid > 0)
    {
        int a[2];
        int res[2];
        printf("PARENT:\n");
        printf("x y ? ");
        scanf("%d %d", &a[0], &a[1]);
        close(fd[READ]);
        write(fd[WRITE], a, 2 * sizeof(int));
        close(fd[WRITE]);
        read(fd2[READ], res, 2*sizeof(int));
        printf("PARENT:\n");
        printf("x + y = %d\n", res[0]);
        printf("x - y = %d\n", res[1]);
    }
    else
    {
        int b[2];
        close(fd[WRITE]);
        read(fd[READ], b, 2 * sizeof(int));
        int res2[2];
        res2[0] = b[0] + b[1];
        res2[1] = b[0] - b[1];
        close(fd[READ]);
        write(fd2[WRITE], res2, sizeof(int));
        close(fd2[WRITE]);
    }
    return 0;
}