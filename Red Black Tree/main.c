#include <stdio.h>
#include <stdlib.h>
#include "RedBlackTree.h"


int main()
{
    Tree_ptr root;
    Initialize(&root);

    //Ylopoiw to dentro poy parousiazetai stis diafaneies
    //Chapter 12: Red Black Trees, page 5 
    InsertKey(&root,12);
    InsertKey(&root,5);
    InsertKey(&root,15);
    InsertKey(&root,3);
    InsertKey(&root,10);
    InsertKey(&root,13);
    InsertKey(&root,17);
    InsertKey(&root,4);
    InsertKey(&root,7);
    InsertKey(&root,11);
    InsertKey(&root,14);
    InsertKey(&root,6);
    InsertKey(&root,8);

    printf("Root: %d\n", root->data);
    printf("Inorder Traversal is: \n");
    PrintElements(root);
    printf("\n");

    RemoveKey(&root, 30);   //A node which is not in the tree

    RemoveKey(&root, 13);   //A node which is black
    printf("Inorder Traversal is: \n");
    PrintElements(root);
    printf("\n");

    RemoveKey(&root, 14);   //A node which is red
    printf("Inorder Traversal is: \n");
    PrintElements(root);
    printf("\n");

    return 0;
}