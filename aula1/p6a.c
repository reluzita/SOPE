// PROGRAMA p6a.c 
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define BUF_LENGTH 256 

extern int errno;

int main(int argc, char *argv[]) 
{
    if (argc == 3) {
        FILE *src, *dst;   
        char buf[BUF_LENGTH];   
        if ( ( src = fopen( argv[1], "r" ) ) == NULL )
        {
            int errnum;
            errnum = errno;
            fprintf(stderr, "Value of errno: %d\n", errno);
            perror("Error printed by perror");
            fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
            exit(1);           
        }
        if ( ( dst = fopen( argv[2], "w" ) ) == NULL )
        {    
            perror("Error: "); 
            exit(2) ; 
        }  
        while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )   
        {     
            fputs( buf, dst );   
        }   
        fclose( src );   
        fclose( dst );   
        exit(0);  // zero é geralmente indicativo de "sucesso" 
    }
    else {
        printf("usage: ./p6a file1 file2 \n");
        exit(3);
    }
   
} 