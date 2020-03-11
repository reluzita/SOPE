#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h> 

int main(int argc, char *argv[])
{
    char prog[20];
    sprintf(prog, "%s.c", argv[1]);
    if(execlp("gcc", "gcc", prog, "-Wall", "-o", argv[1], NULL) == -1)
        perror("exec");
    printf("something?");
    exit(0); 
}