#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Deque.h"

void Create (Deque_ptr *head)
{
    *head= NULL;
}

int SizeOf (Deque_ptr head) //Returns the number of nodes
{
   int count= 0;
   Deque_ptr current;
   current = head;
   while (current != NULL)
   {
       count++;
       current = current->next; 
   }
   return count;
}

int IsEmpty (Deque_ptr head)
{
    return head == NULL;
}

int Enqueue (Deque_ptr *head, elem x)    //Add the elem X at the end
{
    Deque_ptr newnode;
    newnode= (Deque_Node *) malloc (sizeof(Deque_Node));
    if (!newnode)
    {
        printf("Error allocating memory!");
        return FALSE;
    }

    if (*head == NULL)  //if queue is empty, new node is the head
    { 
        newnode->data=x;
        *head = newnode;
        return TRUE;
    }
    else
    {
        Deque_ptr current, prev;
        current = *head;
        prev= current;
        while (current->next !=NULL)    //finds the last node
        {
            prev = current;
            current=current->next;
        }
        newnode->data=x;
        current->next = newnode;    //change next of last node
        return TRUE;
    }
    return FALSE;
}

int Push (Deque_ptr *head, elem x)      //Add at the beginning
{
    Deque_ptr newnode;
    newnode= (Deque_Node *) malloc (sizeof(Deque_Node));

    if (!newnode)
    {
        printf("Error allocating memory!");
        return FALSE;
    }
    newnode->data=x;

    newnode->next=*head; 
    *head=newnode;
    return TRUE;
}

int Pop(Deque_ptr *head, elem *x)   //Delete first node
{
    Deque_ptr current;
    if (*head==NULL)    //Empty
    {
        return FALSE;
    }
    current=*head;
    *x=current->data;

    (*head)=(*head)->next;
    free(current);
    return TRUE;
}

int Dequeque (Deque_ptr *head, elem *x) //Delete last node
{
    Deque_ptr current;
    Deque_ptr prev;
    if (*head==NULL)    //Empty
    {
        return FALSE;
    }
    current = *head;
    prev=current;
    while (current->next !=NULL)    //finds the last node
    {
        prev = current;
        current=current->next;
    }
    *x=current->data;
    prev->next=NULL;

    free (current);
    return TRUE;
}

void Print(Deque_ptr head)
{
    Deque_ptr current;
	
	current=head;
	while(current!=NULL)
	{
		printf("(%d)->",current->data);
		current=current->next;
	}
	printf(".");
}

void Destroy (Deque_ptr *head)     //free extra space
{
    Deque_ptr ptr;
	
	while (*head!=NULL)
	{
		ptr=*head;
		*head=(*head)->next;
		free(ptr);
	}
}