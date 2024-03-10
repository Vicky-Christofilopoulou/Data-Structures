#define MAXCOUNT 10

typedef int PQItem;

struct PQNodeTag {
  PQItem   NodeItem;
  struct PQNodeTag *Link;
};

typedef struct PQNodeTag PQListNode;

struct PriorityQueue{
  int Count;
  PQListNode *ItemList;
};

typedef struct PriorityQueue *PQ_ptr;

void Initialize (PQ_ptr *pq);
int Empty (PQ_ptr *pq);
int Full (PQ_ptr *pq);
void Insert (PQItem item, PQ_ptr *pq);
PQItem Remove (PQ_ptr *pq);