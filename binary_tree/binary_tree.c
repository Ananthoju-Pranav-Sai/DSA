#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

Node* create_node(int d)
{
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
}
void print_tree(Node *root)
{
    if(root->left!=NULL)
    {
        print_tree(root->left);
    }
    printf("%d ",root->data);
    if(root->right!=NULL)
    {
        print_tree(root->right);
    }
}