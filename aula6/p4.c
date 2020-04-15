#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 10

void *func(void *threadnum)
{
    sleep(1);
    printf("ID: %lu\n", pthread_self());
    void* ret;
    ret = malloc(sizeof(int));
    *(int*)ret = *(int*)threadnum;
    return ret;
}
int main()
{
    pthread_t threads[NUM_THREADS];
    void* r[NUM_THREADS];
    int t;
    for (t = 0; t < NUM_THREADS; t++)
    {
        printf("Creating thread %d\n", t);
        pthread_create(&threads[t], NULL, func, (void *)&t);
        pthread_join(threads[t], &r[t]);
        printf("returned %d\n", *(int*)r[t]);
        free(r[t]);
    }
    exit(0);
}