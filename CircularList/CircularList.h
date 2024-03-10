#define TRUE 1
#define FALSE 0

typedef int elem; //Data type of the Circular List

struct node
{
    elem data;  
    struct node *next;  //next  
};

typedef struct node CircularList_Node;      //Sinwnimo tou komvou Circular List 
typedef struct node *CircularList_ptr;      //Sinwnimo tou deikti komvou 


void Create (CircularList_ptr *cursor);
int IsEmpty (CircularList_ptr cursor);
int Add (CircularList_ptr *cursor,CircularList_ptr node);          //Add after the cursor
CircularList_ptr Remove(CircularList_ptr *cursor, CircularList_ptr node);
CircularList_ptr GetFirst(CircularList_ptr cursor);
CircularList_ptr GetAfter(CircularList_ptr cursor);
void Advance(CircularList_ptr *cursor);
void Print(CircularList_ptr cursor);