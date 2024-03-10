/* This is the file PQImplementation.c */

#include <stdio.h>
#include <stdlib.h>
#include "PQInterface.h"

/* Now we give all the details of the functions */
/* declared in the interface file together with */
/* local private functions.                     */

void Initialize(PQ_ptr *PQ)
{
   *PQ=(PQ_ptr)malloc(sizeof(struct PriorityQueue)); 
   (*PQ)->Count=0;
   (*PQ)->ItemList=NULL;
}

int Empty(PQ_ptr *PQ)
{
   return((*PQ)->Count==0);
}


int Full(PQ_ptr *PQ)
{
   return((*PQ)->Count==MAXCOUNT);
}

PQListNode *SortedInsert(PQItem Item, PQListNode *P)
{
   PQListNode *N;

   if ((P==NULL)||(Item >=P->NodeItem)){
      N=(PQListNode *)malloc(sizeof(PQListNode));
      N->NodeItem=Item;
      N->Link=P;
      return(N);
   } else {
      P->Link=SortedInsert(Item, P->Link);
      return(P);
   }
}


void Insert(PQItem Item, PQ_ptr *PQ)
{
   if (!Full(PQ)){
     (*PQ)->Count++;
     (*PQ)->ItemList=SortedInsert(Item, (*PQ)->ItemList);
   }
}

PQItem Remove(PQ_ptr *PQ)
{
   PQItem temp;
   if (!Empty(PQ)){
     temp=(*PQ)->ItemList->NodeItem;
     (*PQ)->ItemList=(*PQ)->ItemList->Link;
     (*PQ)->Count--;
     return(temp);
   }
}