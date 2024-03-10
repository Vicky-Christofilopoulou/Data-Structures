#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularList.h"

void Create (CircularList_ptr *cursor)
{
    *cursor= NULL;
}

int IsEmpty (CircularList_ptr cursor)
{
    return cursor == NULL;
}

int Add(CircularList_ptr *cursor, CircularList_ptr node)
{
    if(*cursor == NULL)      //Empty Circular List
    {
        node->next =  node;
        (*cursor)=  node;
        return TRUE;
    }
    else
    {
        node->next= (*cursor)->next;    //Conect the new node with the node after the cursor
        (*cursor)->next =  node;         //connect the new node with its previous one
        return TRUE;
    }
    return FALSE;
}

CircularList_ptr GetFirst(CircularList_ptr cursor)
{
    return cursor;
}

CircularList_ptr GetAfter(CircularList_ptr cursor)
{
    return cursor->next;
}

CircularList_ptr Remove(CircularList_ptr *cursor, CircularList_ptr node)
{
    CircularList_ptr current= (*cursor);
    if (cursor == NULL )
    {
        printf("CircularList_ptr empty!\n");
        return *cursor;
    }
    else if ((*cursor)-> data == node->data && (*cursor)->next == *cursor)    //list contains only a single node
    {
        free(*cursor);
        printf("The list is now empty!\n");
        (*cursor)=NULL;
        return (*cursor);
    }
    else if((*cursor)->data == node->data)       // If node is the cursor
    {
        //we have to find the last node in order to change the next link
        while (current->next != *cursor)
        {
            current=current->next;
        }
        current->next = (*cursor)->next; 
        printf("Removed node with data: %d\n", (*cursor)->data); 
        free(*cursor);
        *cursor=current->next;      //move cursor to the next node
        return (*cursor)->next;
    }
    else
    {
        CircularList_ptr prev;
        prev=current;

        if (current->next == node)  //We need to remove the node after the cursor
        {
            prev->next= node->next; //connect the cursor to the next node
            printf("Removed node with data: %d\n", node->data); 
            free(node);
        }
        else
        {
            while (current->next != node)
            {
                prev= current;
                current=current->next;
            }
            prev->next= current->next;
            current->next = node->next;
            printf("Removed node with data: %d\n", current->data); 
            free(current);
        }
        return (*cursor)->next;;
    }
}

void Advance(CircularList_ptr *cursor)
{
    (*cursor)=(*cursor)->next;
}

void Print(CircularList_ptr cursor)
{
    CircularList_ptr current;
	current=cursor;
    if (IsEmpty(cursor) == FALSE)
    {
        do
        {
            printf("(%d)->",current->data);
            current=current->next;
            printf(".");
        } while ((current->data) != (*cursor).data);
    }
}