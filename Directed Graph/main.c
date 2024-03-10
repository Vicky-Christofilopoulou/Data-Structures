#include <stdio.h>
#include <stdlib.h>
#include "DirectedGraph.h"


int main(void) 
{
    graph_ptr g;
    int num;
    scanf("%d", &num); /*The number of nodes*/
    graph_ptr g;
    Initialize(&g, num);
    int source, dest;

    while (scanf("%d %d", &source, &dest) != EOF)
    {
      InsertEdge(&g,source, dest);
      printf("source: %d\n", source);
      printf("dest: %d\n", dest);
    }
    printf("Adjacency List Represenation: \n");
    ShowGraph(g);
    printf("\n");

    int visited[g->NUmVertices];
    int path[g->NUmVertices];
    int path_index=0;
    for (int i=1; i<= g->NUmVertices; i++)
    {
      visited[i]=0;
      path[i]=0;
    }
    printf("DFS Traversal: \n");
    DFS(g, 1, &visited, &path, path_index);
    printf("\n");


    graph_ptr new_g;
    new_g = GraphReverse(g);
    printf("The reverse Adjacency List Represenation:\n");
    ShowGraph(new_g);
    


  return 0;
}