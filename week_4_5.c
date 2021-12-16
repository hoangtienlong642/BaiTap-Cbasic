// By using a queue, write a To Do List
// management program with a menu for
// adding, deleting, modifying elements in
// the list.
// • A work has the following fields:
// – Time
// – Place
// – People
// – Description.
// • The time field can be the system time at
// the moment of input.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
enum { SUCCESS , FAIL};
#define MAX_LEN  50
static char infix[MAX_LEN];
typedef struct node 
{
    char time[MAX_LEN];
    char place[MAX_LEN];
    char people[MAX_LEN];
    char description[MAX_LEN];
    node *next;
} node;
typedef node *position;
typedef struct {
    position front,rear;
} queue;
static queue *q;
void init ()
{
    q->front = q->rear = NULL;
}
// void MakeNullQueue()
// {
//     position Header;
//     Header=(node*)malloc(sizeof(node));
//     Header->next=NULL;
//     // q->front=Header;
//     // q->rear=Header;
//     free (Header)
// }
node *createnode ( char *place, char *people, char *description)
{
    node *temp;
    time_t cur;
    temp = ( node*) malloc (sizeof (node));
    strcpy (temp->time, ctime(&cur));
    strcpy (temp->place, place);
    strcpy (temp->description, description);
    strcpy (temp->people, people);
    temp-> next = NULL;
    return temp;
}
bool IsEmpty ()
{
    return (q->front == q->rear);
}
void EnQueue (node *temp)
{
     q-> rear -> next =(node*)malloc (sizeof (node));
     q-> rear = q->rear -> next;
     q-> rear = temp;
     q-> rear -> next =NULL;
}
void DeqQueue ()
{
    if (IsEmpty())
    {
        position T;
        T = q->front;
        q->front = q->front->next;
        free (T);
    }
    else printf ("Queue is empty\n");
} 
int main()
{
    int key,i,n;
    char place[MAX_LEN];
    char people[MAX_LEN];
    char description[MAX_LEN];
    node *temp;
    init();
    while (true)
    {
        system("cls");
        printf("**************************************************************\n");
        printf("**              To Do List management program               **\n");
        printf("**      1. Add new NodeType                                 **\n");
        printf("**      2. Delete a note                                    **\n");
        printf("**      3. Modify note                                      **\n");
        printf("**      4. Exit program                                     **\n");
        printf("**************************************************************\n");
        printf("**                       Enter a number                     **\n");
        printf("**************************************************************\n");
        scanf("%d",&key);
        printf("**************************************************************\n");
        switch (key)
        { 
            case 1:
                printf("Enter place\n");
                fflush(stdin);
                gets( place);
                printf("Enter people\n");
                fflush(stdin);
                gets( people);
                printf ("Enter description\n");
                fflush(stdin);
                gets( description);
                temp = createnode( place, people, description);
                EnQueue(temp);
                free(temp);
                break;
            case 2:
                printf {"delete the newest note\n"};
                DeqQueue();
                break;
            case 3:
                printf ("Modify the newest note\n");
                DeqQueue();
                printf("Enter the new information\n");
                printf("Enter new place\n");
                fflush(stdin);
                gets( place);
                printf("Enter new people\n");
                fflush(stdin);
                gets( people);
                printf ("Enter new description\n");
                fflush(stdin);
                gets( description);
                temp = createnode( place, people, description);
                EnQueue(temp);
                free(temp);
            case 4:
                printf ("You chose to exit program.\nPress any key to continue.\n");
                getch();
                return SUCCESS;
            default: 
                printf("Unavailable select  \nPress any key to continue\n");
                getch();
                break;
        }
    }
}



