// We assume that you write a mobile phone’s
// address book.
// • Declare a structure "Address" that can hold at
// least name, telephone number, and e-mail
// address, and write a program that can handle
// about 100 address data.
// • Read about 10 address data from the input file,
// search a name by the linear search, and write the
// data matched first to the output file.
// – (1) Implement this program using an array of structure.
// – (2) Implement this program using a singly-linked list or
// a doubly-linked list. Confirm the second search is
// accelerated by moving data matched to the head of list
// (self-organizing search).
// Read this array data of about 10 from an
// input file, and write a name which is equal
// to a specified name and whose array index
// is the smallest to an output file. Use the
// binary search for this exercise
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
enum {MAX_NAME = 31, MAX_PHONE = 12, MAX_EMAIL = 31};
typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
} elementtype;
typedef struct node_type{ 
    elementtype element;
    node_type *next;
}node_type;
static node_type *root;
static elementtype list[100];
void make_list();
void quicksort(int first, int last);
void input();
void  print_node (node_type *temp);
void print_list();
node_type *create_node ( elementtype element);
void insert_head (  elementtype element);
void insert_middle(elementtype element);
void insert_last (elementtype element);
void sentinel_search ( char key[]);
void make_list (){
    root = NULL;
};
void quicksort(int first, int last)
{
	int privot=last-1;
	elementtype tmp;
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
void input(){
    FILE *f ;
    int i;
    char line[200];
    f = fopen("phonebook.txt","r");
    for (int i=0; i<10; i++){
        fgets(line,150,f);
        sscanf(line, "%s\t%s\t%s[\n]",list[i].name,list[i].phone,list[i].email);
        if(feof(f)) break;
    }
    quicksort(0,9);
    for (i=0; i<10; i++)
	{
		printf("Name:      %s\n",list[i].name);
		printf("Telephone: %s\n",list[i].phone);
		printf("Email:     %s\n",list[i].email);
	}
    for (i = 9; i>=0; i--){
        insert_head (list[i]);
    }
}
void output(){
    FILE *f;
    f = fopen("phonebook_out.txt","w");
    for (int i=0; i<10; i++){
        fprintf(f, "%s\t%s\t%s\n",list[i].name,list[i].phone,list[i].email);
    };
    fclose(f);   
}
void  print_node (node_type *temp){
    printf("Name:       %s\n", temp-> element.name);
    printf("Telephone:  %s\n", temp-> element.phone);
    printf("Email:      %s\n", temp-> element.email);
}
void print_list(){
    node_type *temp;
    temp=root;
    while (temp->next != NULL)
    {
        print_node (temp);
        temp =temp->next;
    }
}
node_type *create_node ( elementtype element){
    node_type *temp;
    temp = (node_type *)malloc(sizeof(node_type));
    temp->element = element;
    temp->next = NULL;
    return temp;
}
void insert_head (  elementtype element){ 
    node_type *temp;
    temp = create_node(element);
    temp-> next = root;
    root = temp;
}
void insert_middle ( node_type *pred, elementtype element){ //insert a node after the pred 
    node_type *temp;
    temp = create_node(element);
    temp->next = pred->next;
    pred->next = temp;
}
void insert_last ( elementtype element){
    node_type *temp, *p;
    p = root;
    temp = create_node(element);
    while ( p-> next != NULL )
        p = p-> next;
    p -> next = temp;
}
void sentinel_search ( char key[]) {
    node_type *p;
    p = root;
    while ( p-> next != NULL ){
        if (strcmp( p->element.name,key ) == 0 )
        {
            printf ("Found!!\n");
            print_node(p);
            return;
        }; 
        p = p->next ;
    };
    printf ("Not found\n");
}
int binary_search(char *key,int low,int high)
{
    if (high >= low){
        int mid = (low + high) / 2;
        if (strcmp(key,list[mid].name) == 0)
            return mid;
        if (strcmp(key,list[mid].name)<0)
            return binary_search (key,low,mid-1);
        return binary_search(key,mid+1,high);
    };
    return -1;
}
int main(){
    int a;
    char key[MAX_NAME];
    make_list();
    input();
    output();
    printf("*****************************************\n");
    print_list();
    printf("Enter the name you want to search for:\n");
    fflush(stdin);
    gets(key);
    printf("Use:\n1. Sentinel search.\n2. Binary search.\n");
    scanf("%d",&a);
    if (a == 1) sentinel_search(key);
    else {
        int i = binary_search(key,0,9);
        if (i==-1) printf("Not found\n");
        else {
            printf("Nummber: %d\n",i+1);
            printf("Name:       %s\n", list[i].name);
            printf("Telephone:  %s\n", list[i].phone);
            printf("Email:      %s\n", list[i].email);
        }
    };
    getch();
    return 1;
}