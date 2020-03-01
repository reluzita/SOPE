#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <sys/times.h>
 #include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc == 3) {
        clock_t start, end;   
        struct tms t;   
        long ticks;   
        int k; 

        start = times(&t);
        ticks = sysconf(_SC_CLK_TCK); 

		int n1, n2;
		sscanf(argv[1], "%d", &n1);
        sscanf(argv[2], "%d", &n2);
        bool notFound = true;
        int num, n = 1;
		while(notFound) {
            srand(time(NULL) + n);
            n++;
            num  = (rand() % n1);
            printf("%d \n", num);
            if (num == n2)
                notFound = false;
        };
        printf("\nClock ticks per second: %ld\n", ticks);   
        end = times(&t);                            
        /* fim da medição de tempo */   
        printf("Clock:                %f s\n", (double)(end-start)/ticks);   
        printf("User time:            %f s\n", (double)t.tms_utime/ticks);   
        printf("System time:          %f s\n", (double)t.tms_stime/ticks);   
        printf("Children user time:   %f s\n", (double)t.tms_cutime/ticks);
        printf("Children system time: %f s\n", (double)t.tms_cstime/ticks); 
        return 0;
	}
	return 1;
}
