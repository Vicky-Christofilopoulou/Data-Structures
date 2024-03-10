#include <stdio.h>
#include <stdlib.h>
#include "WeightedUndirectedGraph.h"

void Initialize(graph_ptr *g, int N)
{
    (*g) = (GRAPH *) malloc(sizeof(GRAPH));
    if(!g)
    {
        printf("Error allocating memory!");
        exit(0);
    }

    (*g)->NUmVertices = N;
    (*g)->adjList = malloc(N * sizeof(node_ptr));
    if (!(*g)->adjList)
    {
        printf("Error allocating memory!");
        exit(0);
    }
    for (int i=0; i<N; i++)
        (*g)->adjList[i] = NULL;
}

node_ptr CreateNode(int d, int w)
{
    node_ptr newnode;
    newnode = (NODE *) malloc (sizeof(NODE));
    if (!newnode)
    {
        printf("Error allocating memory!\n");
        exit(0);
    }
    newnode->vertex = d;
    newnode->weight = w;
    newnode->next = NULL;
    return newnode;
}

void InsertEdge(graph_ptr *g, int source, int dest , int weight)
{
    //Add the edge from source to destination
    node_ptr newnode = CreateNode(dest, weight);
    newnode->next = (*g)->adjList[source];
    (*g)->adjList[source] = newnode;

    //Add the edge from destination to source
    newnode = CreateNode(source, weight);
    newnode->next = (*g)->adjList[dest];
    (*g)->adjList[dest] = newnode;

}

void ShowGraph(graph_ptr g)
{
    int i;
    node_ptr temp = NULL;
    for (i=1; i <= (*g).NUmVertices; i++)
    {
        temp = (*g).adjList[i];
        printf("Vertex:  %d  --> ", i);
        while(temp)
        {
            printf("%d (Weight: %d), ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
        
    }
}