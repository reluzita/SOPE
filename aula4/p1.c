#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h>

#define _XOPEN_SOURCE 700

void sigint_handler(int signo) { printf("In SIGINT handler ...\n"); }


int main(void)
{
    struct sigaction action;

    action.sa_handler = sigint_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    if (sigaction(SIGINT,&action, NULL) < 0)
    {
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(1);
    }
    printf("Sleeping for 30 seconds ...\n");
    int sleepleft = 30;
    while(sleepleft > 0) {
        sleepleft = sleep(sleepleft);
    }
    printf("Waking up ...\n");
    exit(0);
}