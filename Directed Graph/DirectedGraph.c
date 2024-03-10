#include <stdio.h>
#include <stdlib.h>
#include "DirectedGraph.h"

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

void DFS(graph_ptr g, int vertex, int *visited, int* path, int path_index)
{
    node_ptr temp = g->adjList[vertex];
    visited[vertex] = 1;
    path[path_index]=vertex;
    path_index++;
    printf("Visited: %d\n", vertex);

    while (temp!= NULL)
    {
        int connected = temp->vertex;
        if (visited[connected] == 0)
        {
            printf("Tree Edge: %d --> %d \n", vertex, connected);
            DFS(g, connected, visited, path, path_index);
        }
        else
        {
            if (search(path, path_index, vertex, connected) == 2)
                printf("Back Edge: %d --> %d \n", vertex, connected);
            else if (search(path, path_index, vertex, connected) == 1)
                printf("Forward  Edge: %d --> %d \n", vertex, connected);
            else
                printf("Cross Edge: %d --> %d \n", vertex, connected);
        }
        temp = temp->next;
    }
}

int search(int *path, int path_index, int v1,int v2)
{
    //check if v1 prohgeitei v2 sthn lista episkepshs
    int visited_v1 = FALSE;
    int visited_v2 = FALSE;

    for (int i=0; i<path_index; i++)
    {
        if (path[i]== v1 && visited_v2 == FALSE)
            return 1; //forward
        else if (path[i] == v2 &&visited_v1 == FALSE)
            return 2; //back
        else if (path[i]== v1)
            visited_v1 = TRUE;
        else if (path[i]== v2)
            visited_v2 = TRUE;
    }

}

graph_ptr GraphReverse(graph_ptr g)
{
    int num = g->NUmVertices;
    graph_ptr new_g;
    Initialize(&new_g, num);
    
    for(int i=1; i<= num; i++)
    {
        node_ptr temp = g->adjList[i];
        while (temp!= NULL)
        {
            int connected = temp->vertex;
            InsertEdge(&new_g,connected, i);
            temp = temp->next;
        }
    }
    return new_g;
}
