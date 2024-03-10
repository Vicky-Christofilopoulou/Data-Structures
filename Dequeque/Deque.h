#define TRUE 1
#define FALSE 0

typedef int elem; //Data type of the deque

struct node
{
    elem data;  
    struct node *next;  //next  
};

typedef struct node Deque_Node;  // Sinwnimo tou komvou deque 
typedef struct node *Deque_ptr; // Sinwnimo tou deikti komvou 


void Create (Deque_ptr *head);
int SizeOf (Deque_ptr head);
int IsEmpty (Deque_ptr head);
int Enqueue (Deque_ptr *head, elem x);       //Add at the end
int Push (Deque_ptr *head, elem x);         //Add at the start
int Pop(Deque_ptr *head, elem *x);          //remove from start
int Dequeque (Deque_ptr *head, elem *x);    //remove from end
void Print(Deque_ptr head);
void Destroy (Deque_ptr *head);