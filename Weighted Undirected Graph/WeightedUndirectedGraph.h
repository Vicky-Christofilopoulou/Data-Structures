#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 90000
struct Node
{
    int vertex;
    int weight;
    struct Node* next;
};

struct graph
{
    int NUmVertices;
    struct Node** adjList;
};

typedef struct graph GRAPH;
typedef struct graph *graph_ptr;
typedef struct Node *node_ptr;
typedef struct Node NODE;

void Initialize(graph_ptr *g, int N);
void InsertEdge(graph_ptr *g, int source, int dest, int weight);
void ShowGraph(graph_ptr g);

node_ptr CreateNode(int d, int weight);
