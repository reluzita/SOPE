#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char str[512];
   const char s[2] = " ";
   char *token;
   char * strings[5];
   int i = 0;
   
   printf("Command?");
   fgets(str,512,stdin);

   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
        strings[i] = token;
        i++;
    
        token = strtok(NULL, s);
   }
   for (int j = 0; j < i; j++) {
        printf( "%s\n", strings[j] );
   }
   
   return(0);
}