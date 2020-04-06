#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd;
    if (argc != 3)
    {
        printf("Usage: ./client int1 int2\n");
        exit(1);
    }
    fd = open("/tmp/requests", O_WRONLY);
    if (fd == -1)
    {
        printf("Oops !!! Server is closed !!!\n");
        exit(1);
    }
    printf("FIFO 'requests' openned in WRITEONLY mode\n");
    char line[500];
    sprintf(line, "%d %d\n", atoi(argv[1]), atoi(argv[2]));
    write(fd, line, strlen(line)+1);
    close(fd);
    int fd2 = open("/tmp/requests", O_RDONLY);
    char str[500];
    read(fd2, str, 500);
    int res;
    sscanf(str, "%d", &res);
    printf("result: %d", res);
    close(fd2);
    return 0;
}