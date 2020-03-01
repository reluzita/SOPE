#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>


int main(void) {
    int fd1;
    unsigned char ch, name[50], mark[3];
    fd1 = open("students.txt", O_WRONLY | O_APPEND | O_CREAT | O_EXCL, 0644);

    do
    {
        write(STDOUT_FILENO, "Name : ", 7);
        int i = 0;
        do {
            read(STDIN_FILENO, &ch, 1);
            name[i] = ch;
            i++;
        } while(ch != '\n');
        name[i] = 0;
        write(fd1, name, sizeof(name));

        write(STDOUT_FILENO, "Mark : ", 7);
        i = 0;
        while (i < 2 && read(STDIN_FILENO, &ch, 1) && ch != '\n') {   
            mark[i++] = ch;   
        }
        mark[i] = 0;
        write(fd1, mark, sizeof(mark));

        write(STDOUT_FILENO, "Done? [Y/N]", 11);
        read(STDIN_FILENO, &ch, 1);
        if (ch == 'Y') {
            read(STDIN_FILENO, &ch, 1);
            break;
        }
        else {
            read(STDIN_FILENO, &ch, 1);
        }
    } while (true);
    
    close(fd1);
    return 0;
}