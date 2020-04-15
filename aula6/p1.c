#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#define STDERR 2
#define NUMITER 10000

void *thrfunc(void *arg)
{
    int value = *(int*) arg;
    char s[5];
    sprintf(s, "%d", value);
    int i;
    fprintf(stderr, "Starting thread %d\n", value);
    for (i = 1; i <= NUMITER; i++)
        write(STDERR, s, 1);
    return NULL;
}
int main()
{
    pthread_t t[2];
    int list[2] = {1, 2};
    for (int i = 0; i < 2; i++) {
        pthread_create(&t[i], NULL, thrfunc, &list[i]);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(t[i], NULL);
    }
    return 0;
}