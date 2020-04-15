#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *sum(void *nums)
{
    int *n = (int *)nums;
    int n1 = n[0];
    int n2 = n[1];
    printf("Sum: %d!\n", n1 + n2);
    pthread_exit(NULL);
}

void *sub(void *nums)
{
    int *n = (int *)nums;
    int n1 = n[0];
    int n2 = n[1];
    printf("Sub: %d!\n", n1 - n2);
    pthread_exit(NULL);
}

void *divi(void *nums)
{
    int *n = (int *)nums;
    int n1 = n[0];
    int n2 = n[1];
    printf("Div: %d!\n", n1 / n2);
    pthread_exit(NULL);
}

void *mul(void *nums)
{
    int *n = (int *)nums;
    int n1 = n[0];
    int n2 = n[1];
    printf("Mul: %d!\n", n1 * n2);
    pthread_exit(NULL);
}
int main()
{
    pthread_t t1, t2, t3, t4;

    int *nums = (int*)malloc(sizeof(int)*2);
    printf("Enter 2 nums like dis: num1 num2\n");
    scanf("%d %d", &nums[0], &nums[1]);
    pthread_create(&t1, NULL, sum, (void *)nums);
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, sub, (void *)nums);
    pthread_join(t2, NULL);
    pthread_create(&t3, NULL, divi, (void *)nums);
    pthread_join(t3, NULL);
    pthread_create(&t4, NULL, mul, (void *)nums);
    pthread_join(t4, NULL);
    exit(0);
}