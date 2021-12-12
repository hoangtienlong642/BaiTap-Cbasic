// Write a program to read a text file created with emacs. Put a line number 
// to the head of the line and output the contents of the file to the standard output. 
// A text file name can be specified as the argument to the program.
// For example, the following content of a text file
// This is sample file.
// Hello!
// •is output as follows.
// 1 This is sample file.
// 2 Hello!
#include <stdio.h>
#include <stdlib.h>
enum {SUCCESS,FAIL, MAX_LEN = 81};
void readfile ( FILE *ptr )
{
    char buf[MAX_LEN];
    int count = 0;
    while ( fgets ( buf, MAX_LEN, ptr ) != NULL )
    {
        count++;
        printf ("%d  %s", count, buf);
    }
}
int main ( int argc, char *argv[] )
{
    if ( argc < 2 ) {
        printf("Ban chua nhap ten file\n");
        return 0;
    }
    else if (argc == 2 )  
    {
        FILE *fptr;
        int reval = SUCCESS;
        if ( ( fptr = fopen( argv[1] , "r") )== NULL)
        {
            printf("Error opening file %s\n", argv[1]);
            reval = FAIL;
        }
        else
        {
            readfile(fptr);
            fclose(fptr);
        }
        return 1;
    }
    else if (argc > 2) 
    { printf("Ban nhap qua nhieu file\n");
        return 1;
    }
    return 0;
}