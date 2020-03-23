#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <time.h>

#define _XOPEN_SOURCE 700

int increment = 1;

void sigusr_handler(int signo)
{
    if((signo == 10 && increment < 0) || (signo == 12 &&increment > 0)){
        increment = -increment;
    } 
}

int main(void)
{
    pid_t pid;
    struct sigaction action;

    action.sa_handler = sigusr_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    int var = 0;
    if(sigaction(SIGUSR1, &action, NULL)) {
        exit(1);
    }
    if(sigaction(SIGUSR2, &action, NULL)) {
        exit(2);
    }

    if((pid = fork())>0) {
        int s, signo;
        srand(time(NULL));
        for (int i = 0; i < 10; i++) {
            s = rand() % 2 + 1;
            if(s == 1) {
                signo = SIGUSR1;
            }
            else
            {
                signo = SIGUSR2;
            }
            kill(pid, signo);
            sleep(5);
        }
    } else
    {
        for(int i = 0; i < 50; i++) {
            var+=increment;
            printf("%d\n", var);
            sleep(1);
        }
        exit(0);
    }
    exit(0);
}