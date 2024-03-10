#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

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
void ShowGraph(graph_ptr G);
void DFS(graph_ptr g, int vertex, int *visited, int* path, int path_index);
graph_ptr GraphReverse(graph_ptr g);

node_ptr CreateNode(int d);
int search(int *path, int path_index, int v1,int v2);
