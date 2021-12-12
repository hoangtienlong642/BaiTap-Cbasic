// Develop a simple student management program
// using linked list composed of node like this:
// typedef struct Student_t {
// char id[ID_LENGTH];
// char name[NAME_LENGTH];
// int grade;
// struct Student_t *next;
// } Student;41
// so that:
// - The list is sorted in descending order of
// student's grades.
// - Program provide the functionality of:
    // - Insert new student (when you insert a new
    // student into this list, first find the right
    // position)
    // - searching a student by ID: return to a pointer
    // - delete a student with a given ID
// - Add a change_grade function. The function should take 
// as parameters the root of the list, the ID whose grade 
// we’d like to change, and the new grade
// • Hint – Create a new student with the same name, ID as the old one, 
// with the new grade. Then remove the old student from the list and 
// add the new one using the existing functions
// #include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
enum {SUCCESS,FAIL,NAME_LENGTH = 30, ID_LENGTH = 5};
typedef struct Student_t {
    char ID[ID_LENGTH];
    char name[NAME_LENGTH];
    int grade;
    struct Student_t *next;
} Student;
static Student *root ;
Student *Create_std ( char *ID, int grade, char *name ) // create a new Student, return a pointer 
{
    Student *curr_std ;
    curr_std = (Student *) malloc(sizeof(Student));
    strcpy(curr_std->ID, ID);
    strcpy(curr_std->name, name) ;
    curr_std-> grade = grade;
    curr_std-> next = NULL;
    return curr_std;
}
Student *Insert_std ( Student *root, Student *to_add) //nsert new student (when you insert a new student into this list, first find the right position)
{
    if (root == NULL) 
    { 
        return to_add;
    };
    if ( to_add-> grade > root->grade )
    {
        to_add-> next = root;
        return to_add;
    };
    Student *curr_std, *temp_std = NULL;
    curr_std = root;
    while (curr_std != NULL && curr_std->grade > to_add->grade)
    {
        temp_std = curr_std;
        curr_std = curr_std->next;
    };
    temp_std->next = to_add;
    to_add->next = curr_std;
    return root;
}
Student *Search_std ( char *ID, Student *root )  //searching a student by ID: return to a pointer
{
    Student *curr_std;
    curr_std = root;
    while (curr_std != NULL )
    {
        if (strcmp(curr_std->ID, ID) == 0)
            return curr_std;
        curr_std = curr_std->next;
    };
    return curr_std;
}
Student *Delete_std ( char *ID, Student *root ) //delete a student with a given ID
{
    if (root == NULL)
        return NULL;
    Student *curr_std, *prev_std ;
    curr_std = root;
    if (strcmp(curr_std->ID, ID) == 0) 
    {
        root = root->next;
        free(curr_std);
        return root;
    };
    while (curr_std != NULL && strcmp(curr_std->ID, ID) != 0)
    {
        prev_std = curr_std;
        curr_std = curr_std->next;
    }
    if (curr_std != NULL)
        prev_std->next = curr_std-> next; 
    free(curr_std);
    return root;
}
Student *Change_grade ( char *ID, int newgrade ,Student *root) // change grade function
{
    Student *curr_std;
    curr_std = Search_std (ID,root);
    curr_std -> grade = newgrade;
    root = Delete_std (ID,root);
    return Insert_std (root, curr_std);
}
int Print_std (Student *root) // print all of students
{
    Student *curr_std;
    curr_std = root;
    if (curr_std == NULL) 
    {
        printf ("No information available\n");
        return 0;
    };
    int i=0;
    do
    {
        i++;
        printf ("%d\n",i);
        printf ("Student's ID: %s\n",curr_std->ID);
        printf ("Student's name: %s\n",curr_std->name);
        printf ("Student's grade: %d\n",curr_std->grade);
        curr_std = curr_std->next;
    }while (curr_std!= NULL);
    return 1;
}
int main()
{
    Student *to_add,*cur;
    int key,n,i,newgrade;
    char ID[ID_LENGTH] , name[NAME_LENGTH];
    int grade;
    while (true)
    {
        system("cls");
        printf("**************************************************************\n");
        printf("**              STUDENT MANAGEMENT PROGRAM                  **\n");
        printf("**      1. Insert new student                               **\n");
        printf("**      2. Print student infomation                         **\n");
        printf("**      3. Delete student information                       **\n");
        printf("**      4. Search student by ID                             **\n");
        printf("**      5. Change student's grade                           **\n");
        printf("**      6. Exit program                                     **\n");
        printf("**************************************************************\n");
        printf("**                    Enter a number                        **\n");
        printf("**************************************************************\n");
        scanf("%d",&key);
        printf("**************************************************************\n");
        switch (key)
        { 
            case 1:
                printf ("You chose to insert new student.\nEnter the number of student you want to insert: \n");
                scanf("%d",&n);
                getchar();
                for (int i = 1; i <= n; i++)
                {
                    printf("%dth insert\n",i);
                    printf("Enter Student's ID: ");
                    fflush(stdin);
                    gets(ID);
                    printf("Enter Student's name: ");
                    fflush(stdin);
                    gets(name);
                    printf("Enter Student's grade: ");
                    scanf("%d",&grade);
                    // if (i==0 && root->next == NULL)
                    //     root = Create_std(ID, grade, name);
                    // else {
                    to_add = Create_std(ID, grade, name);
                    root = Insert_std(root, to_add);
                    // free(to_add);
                    // // }
                }
                printf ("Insert successfully.\nPress any key to continue.\n");
                getch();
                break;
            case 2:
                printf("List of students: \n");
                Print_std(root);
                printf ("Print successfully.\nPress any key to continue.\n");
                getch();
                break;
            case 3:
                printf("Enter ID of students you want to delete: ");
                fflush(stdin); gets(ID);
                root = Delete_std(ID, root);
                if ( root == NULL)
                {
                    printf("There is no students to delete.\nPress any key to continue.\n");
                    getch();
                    break;
                }
                else {
                    printf("Delete successfully.\nPress any key to continue.\n");
                    getch();
                    break;
                };
            case 4:
                printf("Enter ID of students you want to search: ");
                fflush(stdin); gets(ID);
                cur = Search_std(ID,root);
                if (cur == NULL) 
                    printf("There is no students with ID %s.\n", ID);
                else 
                {
                    printf("Result:\n");
                    printf(" %s %s %d\n", cur->ID, cur->name, cur->grade);
                };
                free(cur);
                printf("Press any key to continue.\n");
                getch();
                break;
            case 5:
                printf("Enter ID of students you want to change the grade: ");
                fflush(stdin); gets(ID);
                cur = Search_std(ID,root);
                if (cur == NULL)
                { 
                    printf("There is no students with ID %s.\n", ID);
                    free(cur);
                }
                else 
                {
                    printf("You chose student :\n");
                    printf(" %s %s %d\n", cur->ID, cur->name, cur->grade);
                    printf("Enter new grade: ");
                    scanf("%d",&newgrade);
                    cur -> grade = newgrade;
                    root = Delete_std (ID,root);
                    Insert_std (root, cur);
                    // root = Change_grade(ID,newgrade,root);
                    printf("Change successfully.\n");
                };
                printf("Press any key to continue.\n");
                getch();
                break;
            case 6:
                printf ("You chose to exit program.\nPress any key to continue.\n");
                getch();
                return SUCCESS;
            default:
                printf ("Your choosen is not valid.\nPress any key to continue.\n");
                getch();
                break;
        }
    };
    return SUCCESS;
}

