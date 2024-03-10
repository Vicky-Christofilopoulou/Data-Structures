#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int MakeTree(Tree_ptr *r, elem root,elem left, elem right)
{
   Tree_ptr newnode;
   newnode =(Tree_node *)malloc(sizeof(Tree_node));
   if (!newnode)
   {
       printf("Error allocating memory!");
       return FALSE;
    }
    newnode->data = root;
    *r = newnode;

    Tree_ptr R;
    R =(Tree_node *)malloc(sizeof(Tree_node));
    if (!R)
    {
        printf("Error allocating memory!");
        return FALSE;
    }
    R->data = right;
    R->left = NULL;
    R->right = NULL;
    (*r)->right = R;

    Tree_ptr L;
    L =(Tree_node *)malloc(sizeof(Tree_node));
    if (!L)
    {
        printf("Error allocating memory!");
        return FALSE;
    }
    L->data = left;
    L->left = NULL;
    L->right = NULL;
    (*r)->left = L;
}

void Print_Node(Tree_ptr r)
{
    printf("%d \n", r->data);
}

void Root(Tree_ptr r)
{
    printf("Root: ");
    Print_Node(r);
}

Tree_ptr Parent(Tree_ptr r, int value)
{
    if(r == NULL || r->data == value)
        return NULL;
    if (r->left != NULL && r->left->data == value || r->right != NULL && r->right->data == value)
        return r;
    
    Tree_ptr temp = Parent(r->left, value);
    if (temp != NULL)
        return temp;
    
    temp= Parent(r->right, value);
    return temp;
}

Tree_ptr Siblings(Tree_ptr r, int value)
{
    //Base cases
    if(r == NULL || r->data == value)
        return NULL;
    if (r->left != NULL && r->left->data == value)
        return r->right;
    if (r->right != NULL && r->right->data == value)
        return r->left;

    //We recursive call the left children
    Tree_ptr temp = Siblings(r->left, value);
    if (temp != NULL)
        return temp;
    
    //then we recursive call the right children
    temp = Siblings(r->right, value);
    return temp;
}

int IsInternal(Tree_ptr r)
{
    //Means that the node has at least a single child
    if (r->left == NULL && r->right == NULL)
        return FALSE;
    else
        return TRUE;
}

int IsExternal(Tree_ptr r)
{
    //Means that the node is a leaf aka no children
    if (r->left == NULL && r->right == NULL)
        return TRUE;
    else
        return FALSE;
}

int InsertLeft(Tree_ptr r, elem x)
{
    Tree_ptr newnode;
    if (r->right != NULL)
        return FALSE;

    newnode =(Tree_node *)malloc(sizeof(Tree_node));
    if (!newnode)
    {
        printf("Error allocating memory!");
        return FALSE;
    }
    newnode->data =x;
    newnode->left=NULL;
    newnode->right=NULL;

    r->left= newnode;
    return TRUE;
}

int InsertRight(Tree_ptr r, elem x)
{
    Tree_ptr newnode;
    if (r->right != NULL)
        return FALSE;

    newnode =(Tree_node *)malloc(sizeof(Tree_node));
    if (!newnode)
    {
        printf("Error allocating memory!");
        return FALSE;
    }
    newnode->data =x;
    newnode->left=NULL;
    newnode->right=NULL;

    r->right= newnode;
    return TRUE;
}

void Attach(Tree_ptr tree1, Tree_ptr tree2, Tree_ptr root)
{
    //Root is an external node, so it has 0 or 1 child
    if (root->left == NULL && root->right == NULL)
    {
        root->left= tree1;
        root->right= tree2;
    }
    else if(root->left != NULL)
    {
        root->left->left = tree1;
        root->right= tree2;
    }
    else
    {
        root->left= tree1;
        root->right->left= tree2;
    }
}

int Remove(Tree_ptr *root, Tree_ptr node, elem *x)
{
    Tree_ptr father= Parent((*root), node->data);
    Tree_ptr child;

    //If the node has 2 childern
    if (node->left != NULL && node->right != NULL)
        return FALSE;
    
    //If the node has 0 childen aka leaf
    if (node->left == NULL && node->right == NULL)
    {
        if (node != (*root))//The node is not the root
        {
            if (father->left == node)
                father->left = NULL;
            else
                father->right = NULL;
        }
        else    //The node is the root
            (*root) = NULL;
        *x = node->data;
        free(node);
        return TRUE;
    }
    else //The node has 1 child
    {
        if (node->left != NULL)
            child = node->left;
        else if (node->right != NULL)
            child = node->right;
        if (node != (*root)) //The node is not the root
        {
            if (father->left == node)
                father->left = child;
            else
                father->right = child;
        }
        else
            (*root)= child;
        *x = node->data;
        free(node);
    }

}

void Destroy(Tree_ptr r)
{
    if (r == NULL)
        return;
    
    //We have to delete the subtrees
    Destroy(r->left);
    Destroy(r->right);

    //Now we delete the node
    printf("\n Deleting node: %d", r->data);
    free(r);
}

void Currentlevel(Tree_ptr r, int level)
{
    if (r== NULL)
        return;
    else if (level == 1)
        Print_Node(r);
    else if (level > 1)
    {
        Currentlevel(r->left, level-1);
        Currentlevel(r->right, level-1);
    }
}

void PreOrder(Tree_ptr r)
{
    //Root, Left, Right
    if ( r == NULL)  //Empty tree
        return;
    else
    {
        Print_Node(r);
        PreOrder(r->left);
        PreOrder(r->right);
    }
}

void InOrder(Tree_ptr r)
{
    //Left, Root, Right
    if ( r == NULL)  //Empty tree
        return;
    else
    {
        InOrder(r->left);
        Print_Node(r);
        InOrder(r->right);
    }
}

void PostOrder(Tree_ptr r)
{
    //Left, Right, Root 
    if ( r == NULL)  //Empty tree
        return;
    else
    {
        PostOrder(r->left);
        PostOrder(r->right);
        Print_Node(r); 
    }
}

void LevelOrder(Tree_ptr r)
{
    int h= Heigth(r);
    for (int i=1; i<=h; i++)
        Currentlevel(r, i);
}

int Heigth (Tree_ptr r)
{
    if ( r == NULL)
    {
        return 0;
    }
    else
    {
        //We calculate the depth of each subtree
        int Left = Heigth(r->left);
        int Right = Heigth(r->right);

        //Height is the lager one + 1
        if (Right > Left)
        {
            return (Right + 1);
        }
        else
        {
            return (Left + 1);
        }
    }
}

int Size(Tree_ptr r)
{
   if ( r == NULL)  //Empty tree
        return 0;
    else
        return (Size(r->left) +1 + Size(r->right));
}