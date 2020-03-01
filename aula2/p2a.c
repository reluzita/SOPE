#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");

    fseek(fp1, 0, SEEK_END);
    long fsize = ftell(fp1);
    fseek(fp1, 0, SEEK_SET);

    char *string = malloc(fsize + 1);
    fread(string, fsize, 1, fp1);
    fclose(fp1);

    string[fsize] = 0;

    fp2 = fopen(argv[2], "w");

    fwrite(string, fsize, 1, fp2);
    fclose(fp2);

    return 0;

};