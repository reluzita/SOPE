#include <termios.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    struct termios term, oldterm;
    int i = 0;
    char pass[50], ch, echo = '*';

    write(STDOUT_FILENO, "\nPassword? ", 11);

    tcgetattr(STDIN_FILENO, &oldterm);
    term = oldterm;
    term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

    while(i < 50 && read(STDIN_FILENO, &ch, 1) && ch != '\n') {
        pass[i] = ch;
        write(STDOUT_FILENO, &echo, 1);
        i++;
    }
    pass[i] = 0;

    tcsetattr(STDOUT_FILENO, TCSANOW, &oldterm);
    write(STDOUT_FILENO, "\n", 1);

    return 0;
}