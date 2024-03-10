#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
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
void InsertEdge(graph_ptr *g, int source, int dest);
void ShowGraph(graph_ptr g);
void SimplePathCheck(graph_ptr g, int v1, int v2, int *visited, int* path, int path_index);

node_ptr CreateNode(int d);
