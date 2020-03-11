#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    int pid, pid_terminated, status, p;
    char *s_begin;
    char cmd[100];
    char *o = "-o ";
    printf("minish > ");
    scanf("%s", cmd);
    while (strcmp(cmd, "quit") != 0)
    {
        pid = fork();
        if (pid > 0)
        {
            pid_terminated = wait(&status);
            printf("PARENT: son %d terminated with exit code %d\n", pid_terminated, WEXITSTATUS(status));
        }
        else
        {
            s_begin = strstr(cmd, o);
            if(s_begin != NULL) {
                s_begin += 3;
                char sub[100];
                memcpy(sub, s_begin, strlen(s_begin));
                p = open(sub, O_WRONLY | O_CREAT, 0644);
                dup2(p, STDOUT_FILENO);
            }
            execlp(cmd, cmd, NULL);
            printf("Command not found !!!\n");
            exit(1);
        }
        printf("minish > ");
        scanf("%s", cmd);
    }
    return 0;
}
