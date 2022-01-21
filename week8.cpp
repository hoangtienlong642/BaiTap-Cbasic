// Create an binary search tree with 10
// nodes. Each node contains an
// random integer.
// • Ask user to input an number and
// search for it.
// • Print the content of the trees.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<time.h>
typedef int elementtype;
typedef struct node{
    elementtype element;
    node *left,*right;
}nodeType ;
typedef node *treeType;
void MakeNullTree(treeType *root){
    root = NULL;
}
int IsEmpty (treeType *root){
    return root == NULL;
}
// int IsLeaf (treeType *root){
//     return (root->left == NULL) && (root->right == NULL);
// }
// int IsInternal (nodeType *N){
//     return (N->left != NULL) || (N->right != NULL);
// }
treeType *LeftChild(treeType *temp){
    if (temp!= NULL) return temp->left;
    else return NULL;
}
treeType *RightChild(treeType *temp){
    if (temp!= NULL) return temp->right;
    else return NULL;
}
nodeType *CreateNode (elementtype x){
    nodeType *temp;
    temp = (nodeType *)malloc(sizeof(nodeType));
    temp->element = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
} 
int IsLeaf(nodeType *N){
    if (N!=NULL) return (N->left==NULL) && (N->right==NULL);
    else return -1;
}
void AddLeft (treeType *root, elementtype x){
    nodeType *temp = CreateNode(x);
    if (IsEmpty(root)) 
    {
        root = temp;
    }
    else {
        treeType *p = root;
        while (p->left != NULL) \
            p = p->left;
        p->left = temp;
    }
}
void AddRight (treeType *root, elementtype x){
    nodeType *temp = CreateNode(x);
    
    if (IsEmpty(root)) 
    {
        root = temp;
    }
    else {
        treeType *p = root;
        while (p->right != NULL) \
            p = p->right;
        p->right = temp;
    }
}
int random(int l, int r){
    return (l + rand() % (r-l+1));
}
void fill_tree(treeType *root, int x){ 
   if (root == NULL){ 
       nodeType *temp = CreateNode(x);
       root = temp;   
    }
    if (root->right == NULL) return fill_tree(RightChild(root), x);
    if (root->left == NULL) return fill_tree(LeftChild(root), x);
}
void create_rand_tree (treeType *root, int n){
    int *arr;
    arr = (int *) malloc(sizeof(int)*n);
    for (i=0; i<n;i++){ 
        arr[i] = ran(0,20);
        fill_tree(root,arr[i]);
    };
}
int NumberNode(nodeType *N){
    if (IsEmpty(N)) return 0;
    else return 1 + NumberNode(LeftChild(N)) + NumberNode(RightChild(N));
}
int Max(int a, int b){
    if(a>=b) return a
    else return b;
}
int TreeHeight(nodeType *N){
    if(N==NULL) 
        return 0;
    else 
        return 1 + Max(TreeHeight(LeftChild(N)), TreeHeight(RightChild(N)));
}
int NumberLeaf(nodeType *N){    
    if (IsLeaf(N)) return 1;
    else return NumberLeaf(LeftChild(N)) + NumberLeaf(RightChild(N));
}
int NumberInternals(nodeType *N){
    if (IsInternals(N)) return 1;
    else return NumberInternals(LeftChild(N)) + NumberInternals(RightChild(N));
}
int NumberRightChild(nodeType *N){
    if (IsEmpty(N)) return 0;
    if (RightChild(N)!=NULL) 
        return 1+ NumberInternals(RightChild(N)) + NumberRightChild(LeftChild(N));
    else return NumberRightChild(LeftChild(N));
}
treeType *Search(treeType *root ,elementtype key){
    if (IsEmpty(root)) return NULL;
    if (root-> element == key) return root;
    if (root-> element >key ) return Search(root-> left, key);
    else return Search(root-> right, key);
}
void print_tree(treeType *root){
    if (root == NULL) return;
    else {
        printf("%d\n", root-> element;
        return print_tree(LeftChild(root));
        return print_tree(RightChild(root));
    }
}
int main(){
    int key ;
    treeType *root;
    MakeNullTree(root);
    srand((int)time(0));
    create_rand_tree(root,10);
    print_tree(root);
    printf ("Enter a number: "); 
    scanf("%d",key);
    root = search(root,key);
    if (root == NULL) printf("Not found\n");
    else printf("found\n"); 
    return 0;
}