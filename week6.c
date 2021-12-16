// Read 11 integers from the standard input and assign first
// ten integers to the array.
// • Then if the 11th integer is in the array, output the position
// of the element (1 – 10). If not, output 0.
#include<stdio.h>
#include<stdlib.h>
int linear_search(int n[])
{
    int i=0;
    int x = n[10];
    while (n[i] != x)
        i++;
    return i;
}
int main ()
{
    int T[11];
    for (int i = 0; i < 11; i++)
    {
        scanf("%d",&T[i]);
    };
    int t = linear_search(T);
    if (t == 10)
        printf("not found\n");
    else printf("found \n");
    return 0;
}