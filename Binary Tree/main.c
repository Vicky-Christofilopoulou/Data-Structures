#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int main(void)
{
  /* Construct the following tree
          1
       /     \
      /       \
     2         3
      \     /    \
       4   5      6
          / \    /
         7   8   9
  */
  Tree_ptr root=NULL;
  MakeTree(&root, 1,2,3);
  int result=IsExternal(root);
  if (result == 1)
    printf("The root is external.\n");
  else
    printf("The root is not external.\n");
  InsertRight(root->left, 4);
  InsertLeft(root->right, 5);
  InsertRight(root->right, 6);
  InsertRight(root->right->right, 9);
  InsertLeft(root->right->left, 7);
  InsertRight(root->right->left,8);

  //Check the print functions
  printf("Level Order traversal of binary tree is \n");
  LevelOrder(root);printf("\n");
  printf("The tree in preorder: \n");
  PreOrder(root); printf("\n");
  printf("The tree in inorder: \n");
  InOrder(root); printf("\n");
  printf("The tree in postorder: \n");
  PostOrder(root);printf("\n");

  printf("Height of tree is %d\n", Heigth(root));
  printf("Size of the tree is %d\n\n", Size(root));

  result=IsInternal(root);
  if (result == 1)
    printf("The root is external.\n");
  else
    printf("The root is not external.\n");
  
  Tree_ptr father = Parent(root, 5);
  if (father != NULL)
  {
    printf("The father of node is %d\n", father->data);
  }
  else
  {
    printf("Parent is NULL.\n");
  }

  Tree_ptr siblings = Siblings(root, 5);
  if (siblings != NULL)
    {
      printf("The siblings are %d\n", siblings->data);
    } 
    else 
    {
      printf("The node does not have any sibling");
    }
  elem x;
  Remove(&root, root->right->right, &x);
  printf("Removed node with value: %d\n\n", x);
  printf("Level Order traversal of binary tree is \n");
  LevelOrder(root);printf("\n");

  /* Construct the following tree
          10
       /     \
      /       \
     12        13
      \     /    
       14  15     
  */
  Tree_ptr root1=NULL;
  MakeTree(&root1, 10,12,13);
  InsertRight(root1->left, 14);
  InsertLeft(root1->right, 15);

  printf("Level Order traversal of binary tree is \n");
  LevelOrder(root1);printf("\n");

  Tree_ptr NewRoot;
  if (NewRoot->right != NULL)
      return FALSE;

  NewRoot =(Tree_node *)malloc(sizeof(Tree_node));
  if (!NewRoot)
  {
    printf("Error allocating memory!");
    return FALSE;
  }
  NewRoot->data =20;
  NewRoot->left=NULL;
  NewRoot->right=NULL;
  
  Attach(root,root1,NewRoot);

  printf("Level Order traversal of binary tree is \n");
  LevelOrder(NewRoot);printf("\n");

  Destroy(root);
  printf("\n");

  Destroy(root1);
  printf("\n");
  return 0;
}
