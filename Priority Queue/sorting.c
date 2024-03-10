#include <stdio.h>
#include "PQInterface.h"

typedef PQItem SortingArray[MAXCOUNT];
/* Note: MAXCOUNT is 10 */

void PriorityQueueSort(SortingArray A)
{
   int i;
   PQ_ptr PQ;
   Initialize(&PQ);
   
   for (i=0; i<MAXCOUNT; ++i) Insert(A[i], &PQ);
   printf("The queue contains %d elements\n", PQ->Count);
   for (i=MAXCOUNT-1; i>=0; --i) A[i]=Remove(&PQ);
}

int SquareOf(int x)
{
  return x*x;
}

int main(void)
{
   int i; SortingArray A;

   for (i=0; i<10; ++i){
      A[i]=SquareOf(3*i-13);
      printf("%d ",A[i]);
    }
    printf("\n");
    
    PriorityQueueSort(A);

    for (i=0; i<10; ++i) {
      printf("%d ",A[i]);
    }
    printf("\n");
}