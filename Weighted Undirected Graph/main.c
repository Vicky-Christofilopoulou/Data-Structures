#include <stdio.h>
#include <stdlib.h>
#include "WeightedUndirectedGraph.h"


int main(void) 
{
  int num;
  scanf("%d", &num); /*The number of nodes*/
  graph_ptr g;
  Initialize(&g, num);
  int source, dest, weight;

  while (scanf("%d %d %d", &source, &dest, &weight) != EOF)
  {
    InsertEdge(&g,source, dest, weight);
    printf("source: %d\n", source);
    printf("dest: %d\n", dest);
    printf("Weight %d\n", weight);
  }

  printf("Adjacency List Represenation: \n");
  ShowGraph(g);
  printf("\n");  

    return 0;
}