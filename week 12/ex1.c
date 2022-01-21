#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
enum {SUCCESS,FAIL,NAME_LENGTH = 30, TELE_LENGTH = 10};
typedef struct address_t
{
    char name[NAME_LENGTH];
    char telephone[TELE_LENGTH];
    char email[NAME_LENGTH];
} address;
static address list[100];
void Create_addr( address *curr_addr,int i, char *name, char *telephone, char *email ) // create a new address, return a pointer 
{
    strcpy((curr_addr+i)->name, name);
    strcpy((curr_addr+i)->email, email) ;
    strcpy((curr_addr+i)->telephone, telephone) ;
}
void SWAP( address a, address b, address temp )
{
    a = temp; 
    a = b;
    b = temp;
}
// void quicksort(int left, int right)
// {
//     int i, j;
//     char pivot[NAME_LENGTH];
//     address temp;
//     if (left < right) {
//          i = left;    j = right+1;
//          strcmp (pivot , list[left].name);
//          do {
//              do i++; while (list[i].name[0] < pivot[0]);
//              do j--; while (list[j].name[0] > pivot[0]);
//              if (i < j) SWAP(list[i], list[j], temp);
//         } while (i < j);
//         SWAP(list[left], list[j], temp);
//         quicksort( left, j-1);
//         quicksort( j+1, right);
//     }
// }
void quicksort(int first, int last)
{
	int privot=last-1;
	address tmp;
	int i;
	if (last<=first)
		return;
	for (i=0;i<(last-first);i++)
		if (strcmp(list[i].name,list[last].name)>0)
		{
			tmp=list[i];
			list[i]=list[privot];
			list[privot--]=tmp;
		}
	tmp=list[last];
	list[last]=list[privot];
	list[privot]=tmp;
	quicksort(first,privot-1);
	quicksort(privot+1,last);
}
void print_addr(address list)
{
    printf("Name: "); printf("%s\n", list.name);
    printf("Email: "); printf("%s\n", list.email);
    printf("Telephone: "); printf("%s\n", list.telephone);
}
int main()
{
    char key[NAME_LENGTH];
    char name[NAME_LENGTH];
    char telephone[TELE_LENGTH];
    char email[NAME_LENGTH];
    int k,i=0,n;
    FILE *f1,*f2;
    f1 = fopen("address.txt","r");
    if ( f1 == NULL ) 
        printf ("File empty\n");
    else printf ("Reading successfully\n");
    f2 = fopen("output.txt","w");
    while(name != NULL && i != 9)
    {
        fscanf(f1, "%s",name);
        fscanf(f1, "%s",telephone);
        fscanf(f1, "%s",email);
        Create_addr(list,i,name,telephone,email);
        i++;
    };
    n = i;
    quicksort(0,n-1);
    for (k=0; k<n; k++) {
        print_addr(list[k]);
    }
    fclose(f1);
    fclose(f2);
    return 0;

}