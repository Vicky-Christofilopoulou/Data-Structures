#include <stdio.h>
#include <stdlib.h>
#include "UndirectedGraph.h"


int main(void) 
{
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

  printf("Following are all different paths from 2 to 3\n");
  SimplePathCheck(g,2,3,&visited,&path,path_index);
  return 0;
}