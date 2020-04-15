#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#define MAX_MSG_LEN 20

int main(void)
{
    int fd, fd_dummy, n, int1, int2;
    char str[MAX_MSG_LEN];
    if (mkfifo("/tmp/requests", 0660) < 0)
        if (errno == EEXIST)
            printf("FIFO '/tmp/requests' already exists\n");
        else
            printf("Can't create FIFO\n");
    else
        printf("FIFO '/tmp/requests' sucessfully created\n");
    if ((fd = open("/tmp/requests", O_RDONLY)) != -1)
        printf("FIFO '/tmp/requests' openned in READONLY mode\n");
    if ((fd_dummy = open("/tmp/requests", O_WRONLY)) != -1)
        printf("FIFO '/tmp/requests' openned in WRONLY mode\n");
    do
    {
        n = read(fd, str, MAX_MSG_LEN);
        sscanf(str, "%d %d", &int1, &int2);
        sprintf(str, "%d\n", int1 + int2);
        n = strlen(str);
        write(fd_dummy, str, n);
    } while (!(int1 == 0 && int2 == 0));

    close(fd);
    close(fd_dummy);
    if (unlink("/tmp/requests") < 0)
        printf("Error when destroying FIFO '/tmp/requests'\n");
    else
        printf("FIFO '/tmp/requests' has been destroyed\n");
    exit(0);
}