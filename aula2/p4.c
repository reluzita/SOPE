#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>


int main(void) {
    int fd1;
    char ch, name[50], mark[3];
    fd1 = open("students.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    do
    {
        printf("Name?\n");
        scanf("%s", name);
        write(fd1, name, strlen(name));
        write(fd1, "\n", strlen("\n"));

        printf("Mark?\n");
        scanf("%s", mark);
        write(fd1, mark, strlen(mark));
        write(fd1, "\n", strlen("\n"));

        getchar();
        printf("Done? [Y/N]");
        scanf("%c", &ch);
       
    } while (ch != 'Y');
    
    close(fd1);
    return 0;
}