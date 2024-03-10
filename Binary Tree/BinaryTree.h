#define TRUE 1
#define FALSE 0

typedef int elem;          /* typos dedomenwn dendrou*/

struct node {
    elem data;
    struct node* left;
    struct node* right;
};

typedef struct node Tree_node; /* Sinwnimo tou komvou dendrou */
typedef struct node * Tree_ptr; /* Sinwnimo tou deikti komvou */

int MakeTree(Tree_ptr *r, elem root, elem right, elem left);
void Print_Node(Tree_ptr r);
void Currentlevel(Tree_ptr r, int level);

void Root(Tree_ptr r);
Tree_ptr Parent(Tree_ptr r, int value);
Tree_ptr Siblings(Tree_ptr r, int value);

int IsInternal(Tree_ptr r);
int IsExternal(Tree_ptr r);

int InsertLeft(Tree_ptr r, elem x);
int InsertRight(Tree_ptr r, elem x);

void Attach(Tree_ptr tree1, Tree_ptr tree2, Tree_ptr root);
int Remove(Tree_ptr *root, Tree_ptr Parent, elem *x);

void Destroy(Tree_ptr r);
void PreOrder(Tree_ptr r);
void InOrder(Tree_ptr r);
void PostOrder(Tree_ptr r);
void LevelOrder(Tree_ptr r);
int Heigth (Tree_ptr r);
int Size (Tree_ptr r);