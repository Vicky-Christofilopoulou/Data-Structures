#include <stdio.h>
#include <stdlib.h>
#include "UndirectedGraph.h"

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

node_ptr CreateNode(int d)
{
    node_ptr newnode;
    newnode = (NODE *) malloc (sizeof(NODE));
    if (!newnode)
    {
        printf("Error allocating memory!\n");
        exit(0);
    }
    newnode->vertex = d;
    newnode->next = NULL;
    return newnode;
}

void InsertEdge(graph_ptr *g, int source, int dest)
{
    //Add the edge from source to destination
    node_ptr newnode = CreateNode(dest);
    newnode->next = (*g)->adjList[source];
    (*g)->adjList[source] = newnode;

    //Add the edge from destination to source
    newnode = CreateNode(source);
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
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
        
    }
}

void SimplePathCheck(graph_ptr g, int v1, int v2, int *visited, int* path, int path_index)
{
    node_ptr temp = g->adjList[v1];
    visited[v1]=1;
    path[path_index]=v1;
    path_index++;

    // If current vertex is same as destination, then print path
    if (v1 == v2) {
        for (int i = 0; i < path_index; i++)
            printf("%d ", path[i]);
        printf("\n");
    }
    else //current vertex is not destination
    {
        while(temp)
        {
            if (!visited[temp->vertex])
            {
                SimplePathCheck(g,temp->vertex, v2, visited, path, path_index);
            }
            temp= temp->next;
        }
    }
    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[v1] = 0;
}