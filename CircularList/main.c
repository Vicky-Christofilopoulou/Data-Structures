#include <stdio.h>
#include <stdlib.h>
#include "CircularList.h"

int main(void)
{

    CircularList_ptr cursor;
    elem element;
    int i, c, r;        //We make the assumption that i>3, because we remove 3 nodes after

    Create(&cursor);
    
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &c);
    
    for(i=0;i<c; i++)
    {
        CircularList_ptr newnode;
        newnode= (CircularList_Node *) malloc (sizeof(CircularList_Node));
        if (!newnode)
        {
            printf("Error allocating memory!");
            return FALSE;
        }
        int r=rand()%100; 
        newnode->data=r;
        printf("Adding a new node with data: %d\n", newnode->data);
        Add(&cursor, newnode);
        Print(cursor);
        printf("\n");

        int r2= rand()% 2; 
        if (r2 == 0 && i>1)    //move cursor one place & at least 2 nodes
        {
            Advance(&cursor);
            printf("The cursor is moved to the next node.\n");
        }
    }
    
    CircularList_ptr node;
    node = GetFirst(cursor);    //removes the node which the cursor points
    Remove(&cursor, node);
    Print(cursor);
    printf("\n");

    node = GetAfter(cursor);    //removes the node after the cursor
    Remove(&cursor, node);
    Print(cursor);
    printf("\n");

    node = GetFirst(cursor);    //removes the node which the cursor points
    Remove(&cursor, node);
    Print(cursor);
    printf("\n");
    return 0;
}