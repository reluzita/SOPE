#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char* envp[])
{
	if(argc == 1) {
		char *user;
		user = getenv("USER_NAME");
		printf("Hello %s !\n", user);
	}
	if(argc == 3) {
		int n;
		sscanf(argv[2], "%d", &n);
		for(int i = 0; i < n; i++)
			printf("Hello %s !\n", argv[1]);
	}
	
	return 0;
}
