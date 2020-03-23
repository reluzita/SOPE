#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    char * s;
    sscanf(argv[1], "%s", s);
    for(int i = 0; i < 6;i++) {
        printf("%s", s);
        sleep(5);
    }
    exit(0);
}