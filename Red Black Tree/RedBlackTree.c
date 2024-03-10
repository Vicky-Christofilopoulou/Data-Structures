#include <stdio.h>
#include <stdlib.h>
#include "RedBlackTree.h"

void Initialize(Tree_ptr *root)
{
    *root= NULL;
}

Tree_ptr min(Tree_ptr node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

void RightRotate(Tree_ptr *root,Tree_ptr node)
{
    Tree_ptr x = node->left;
    node->left = x->right;
    if (x->right != NULL)
        x->right->parent = node;
    x->parent =node->parent;

    if (x->parent == NULL)
        (*root) = x;
    else if (node == node->parent->left)
        node->parent->left = x;
    else node->parent->right = x;
    x->right = node;
    node->parent = x;
}

void LeftRotate(Tree_ptr *root,Tree_ptr node)
{
    Tree_ptr x = node->right;
    node->right = x->left;
 
    if (node->right != NULL)
        node->right->parent = node;
    x->parent = node->parent;
 
    if (node->parent == NULL)
        (*root) = x;
    else if (node == node->parent->left)
        node->parent->left = x;
    else  node->parent->right = x;
    x->left = node;
    node->parent = x;
}

void Transplant(Tree_ptr root,Tree_ptr u, Tree_ptr v)
{
	if (u->parent == NULL) 
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else 
		u->parent->right = v;
    if ( v != NULL)
	    v->parent = u->parent;
}

void InsertFixUp(Tree_ptr *root, Tree_ptr node)
{
    Tree_ptr uncle;
    while (node->parent->color == 1)
    {
        if (node->parent == node->parent->parent->right)
        {
            uncle = node->parent->parent->left;
            if (uncle->color == 1)
            {
                uncle->color =0;
                node->parent->color =1;
                node->parent->parent->color =1;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->left) {
					node = node->parent;
					RightRotate(root, node);
				}
				node->parent->color = 0;
				node->parent->parent->color = 1;
				LeftRotate(root, node->parent->parent);
            }
        }
        else
        {
            uncle = node->parent->parent->right;
            if (uncle->color == 1) {
				uncle->color = 0;
				node->parent->color = 0;
				node->parent->parent->color = 1;
                node = node->parent->parent;	
			} 
            else 
            {
				if (node == node->parent->right) {
					node = node->parent;
					LeftRotate(root, node);
				}
				node->parent->color = 0;
				node->parent->parent->color = 1;
				RightRotate(root, node->parent->parent);
			} 
        }
        if (node == (*root))
        {
            break;
        }
    }
    (*root)->color =0;
}


void DeleteFixUp(Tree_ptr *root, Tree_ptr node)
{
    Tree_ptr uncle;
    while (node != *root && node->color == 0)
    {
        if (node == node->parent->left)
        {
            uncle = node->parent->right;
            if (uncle->color == 1)
            {
                uncle->color =0;
                node->parent->color =1;
                LeftRotate(root, node->parent);
                uncle = node->parent->right;
            }

            if (uncle->left->color == 0 && uncle->right->color ==0)
            {
                uncle->color=1;
                node= node->parent;
            }
            else
            {
                if (uncle->right->color ==0)
                {
                    uncle->left->color=0;
                    uncle->color=1;
                    RightRotate(root, uncle);
                    uncle = node->parent->right;
                }

                uncle->color= node->parent->color;
                node->parent->color=0;
                uncle->right->color=0;
                LeftRotate(root, node->parent);
                node = *root;
            }
        }
        else
        {
            uncle = node->parent->left;
            if (uncle->color ==1)
            {
                uncle->color =0;
                node->parent->color =1;
                RightRotate(root, node->parent);
                uncle = node->parent->right;
            }

            if (uncle->left->color == 0 && uncle->right->color ==0)
            {
                uncle->color=1;
                node= node->parent;
            }
            else
            {
                if (uncle->left->color ==0)
                {
                    uncle->right->color=0;
                    uncle->color=1;
                    LeftRotate(root, uncle);
                    uncle = node->parent->left;
                }

                uncle->color= node->parent->color;
                node->parent->color=0;
                uncle->right->color=0;
                RightRotate(root, node->parent);
                node = (*root);
            }
        }
    }
    (*root)->color =0;
}

int InsertKey(Tree_ptr *root, elem data)
{
    Tree_ptr newnode;
    newnode =(Tree_node *)malloc(sizeof(Tree_node));
    if (!newnode)
    {
        printf("Error allocating memory!");
        return FALSE;
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    newnode->color =1; //the new node must be red

    Tree_ptr y=NULL;
    Tree_ptr node =(*root);

    //We need to find the right place because the tree is BST

    while (node != NULL)
    {
        y=node;
        if(newnode->data < node->data)
            node= node->left;
        else 
            node= node->right;
    }

    //y is the parent of the node
    newnode->parent = y;
    if (y == NULL) //If the root is null, the newnode is the root
        (*root) = newnode;
    else if (newnode->data > y->data)
        y->right = newnode;
    else
        y->left = newnode;

    if (newnode->parent == NULL)
    {
        newnode->color=0;
        return TRUE;
    }

    //If the grandparent is null, we just return
    if (newnode->parent->parent == (*root))
        return TRUE;  

    //We have to check if the red black tree rules apply to this tree
    InsertFixUp(root, newnode);
    return TRUE;
}

Tree_ptr Search(Tree_ptr node, elem key)
{
    if (node == NULL || key == node->data)
        return node;
    if (key < node->data)
       return Search(node->left, key);
    return Search(node->right, key);
}

int RemoveKey(Tree_ptr *root, elem key)
{
    Tree_ptr curr= (*root);
    Tree_ptr find=NULL;
    while (curr != NULL) //we find the node
    {
        if (curr->data == key)
            find = curr;
        if (curr->data <= key)
            curr= curr->right;
        else
            curr= curr->left;
    }
    
    if (find == NULL)
    {
        printf("Key not found in the tree.\n\n");
        return FALSE;
    }

    Tree_ptr y = find;
    Tree_ptr x =NULL;
    int ycolor = y->color; //Save the color of the node which is going to be deleted
    if (find->left == NULL)
    {
        x= find->right;
        Transplant(*root, find, find->right);
    }
    else if (find->right == NULL)
    {
        x= find->left;
        Transplant(*root, find, find->left);
    }
    else
    {
        y = min(find->right);
        ycolor= y->color;
        x= y->right;
        if (y->parent == find)
        {
            x->parent= y;
        }
        else
        {
            Transplant(*root, y,y->right);
            y->right = find->right;
            y->right->parent = y;
        }

        Transplant(*root, find, y);
        y->left= find->left;
        y->left->parent=y;
        y->color= find->color;
    }
    free (find);
    if (ycolor == 0)
        DeleteFixUp(root, x);
}

void Print_Node(Tree_ptr r)
{
    printf("Data: %d ", r->data);
    if (r->color == 0)
        printf ("Color: Black\n");
    else 
        printf ("Color: Red\n");
}

void PrintElements(Tree_ptr root)
{
    //In ascending order means Left, Root, Right -> Inorder
    if ( root == NULL)  //Empty tree
        return;
    else
    {
        PrintElements(root->left);
        Print_Node(root);
        PrintElements(root->right);
    }
}