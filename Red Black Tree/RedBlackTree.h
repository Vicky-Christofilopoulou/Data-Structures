#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef int elem;          /* typos dedomenwn dendrou*/

struct node
{
    elem data;
    int color;      //1 - red , black - 0
    struct node* left;
    struct node* right; 
    struct node* parent;
};

typedef struct node Tree_node; 
typedef struct node* Tree_ptr; 


void Initialize(Tree_ptr *root);
int InsertKey(Tree_ptr *root, elem data);
void InsertFixUp(Tree_ptr *root, Tree_ptr node);
int RemoveKey(Tree_ptr *root, elem key);
Tree_ptr Search(Tree_ptr node, elem key);

void RightRotate(Tree_ptr *root, Tree_ptr y);
void LeftRotate(Tree_ptr *root, Tree_ptr y);
void Transplant(Tree_ptr root,Tree_ptr u, Tree_ptr v);

void Print_Node(Tree_ptr r);
void PrintElements(Tree_ptr root);