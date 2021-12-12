// Write a program to read some numbers from the standard input and output them to an “out.txt” file in reverse order. 
// In addition, output a sum of the numbers to the end of out.txt.
// •The format loaded from the standard input is that the 1st number is the number of data, and the 2nd and proceeding 
// numbers are for process. In a case when you input 
// •4 12 -45 56 3 
// •“4” is the number of numbers that follows, and the remainder “12 -45 56 3” should be an output numbers onto the “out.txt” file. 
// The output to “out.txt” is,
// •3 56 -45 12 26
// •The last number “26” is the sum of four numbers. 
// •Because the number of numbers you input changes each time, you must dynamically allocate memory for the number of data: using the malloc( ) function.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum {SUCCESS,FAIL};
int main()
{
    int *p;
    FILE *f;
    int n,i,s;
    s=0;
    i=0;
    printf("Enter a list of numbers with the first is the size of list: \n");
    scanf("%d",&n);;
    p = (int*)malloc(n*sizeof(int));
    while (i<n){
        scanf("%d",&p[i]);
        s = s + p[i];
        i++;
    };
    f = fopen("out.txt","w") ;
    if (  f ==  NULL ) 
    {
        printf("Error opening output file \n");
        return FAIL;
    };
    for (i= n-1 ;i >= 0; i--){
        fprintf(f, "%d ",p[i]);
    };
    fprintf(f, "%d \n",s);
    free(p);
    fclose(f);
    return SUCCESS;
}