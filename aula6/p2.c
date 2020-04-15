#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#define STDERR 2
#define NUMITER 10000

int n;
void *thrfunc(void *arg)
{
    void* ret;
    ret = malloc(sizeof(int));
    int value = *(int*) arg;
    char s[5];
    sprintf(s, "%d", value);
    int i = 0;
    fprintf(stderr, "Starting thread %d\n", value);
    while(n > 0) {
        write(STDERR, s, 1);
        i++;
        n--;
    }
    *(int *) ret = i;
    return ret;
}
int main()
{
    n = 5000;
    pthread_t t[2];
    int list[2] = {1, 2};
    void* r[2];
    for (int i = 0; i < 2; i++) {
        pthread_create(&t[i], NULL, thrfunc, &list[i]);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(t[i], &r[i]);
    }
    printf("n1 : %d\n", *(int*)r[0]);
    printf("n2 : %d\n", *(int*)r[1]);
    free(r[0]);
    free(r[1]);
    return 0;
}