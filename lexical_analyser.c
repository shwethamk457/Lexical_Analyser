#include "header.h"

int error_flag = 0;

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Pass the file name to read\n");
        printf("Usage: ./a.out <sample.c file>\n");
        return 0;
    }

    char filename[50];
    strcpy(filename, argv[1]);

    if(!strstr(filename, ".c"))
    {
        printf("ERROR: Please pass .c file\n");
        return 0;
    }

    FILE *fptr = fopen(filename, "r");

    printf("Open : %s : ", filename);

    if(fptr)
    {
        printf("SUCCESS\n");
    }
    else
    {
        printf("FAILED\n");
        return 0;
    }

    lexical_analyze(fptr);

    fclose(fptr);

    if(error_flag)
        printf("Tokens cannot be generated.\n");
    else
        printf("Tokens generated successfully.\n");

    return 0;
}