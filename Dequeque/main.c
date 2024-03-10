#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

int main(void)
{
    
    Deque_ptr head;
    elem element;

    Create(&head);

    Enqueue(&head, 1);  //insert 1
    Print(head);
    printf("\n");

    Enqueue(&head, 2);  //insert 2
    Print(head);
    printf("\n");

    Enqueue(&head, 3);  //insert 3
    Print(head);
    printf("\n");

    Push(&head, 4);     //insert 4 at the beginning
    Print(head);
    printf("\n");

    Push(&head, 5);     //insert 5 at the beginning
    Print(head);
    printf("\n");

    Push(&head, 6);     //insert 6 at the beginning
    Print(head);
    printf("\n");

    Pop(&head,&element);        //remove the first node
    printf("Successfull removal. Item removed: %d", element);
    printf("\n");
    printf("The deque now contains: ");
    Print(head);
    printf("\n");

    Dequeque(&head, &element);      //remove the last node
    printf("Successfull removal. Item removed: %d", element);
    printf("\n");
    printf("The deque now contains: ");
    Print(head);
    printf("\n");

    printf("The dequeue has %d nodes\n\n", SizeOf(head));
    printf("\n");

    Destroy(&head);
    return 0;
}