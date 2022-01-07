#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_node(int x)
{
    Node *n;
    n = (Node*)malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    n->value = x;
    return n;
}
void print_tree(Node *root)
{
    if(root->left!=NULL)
    {
        print_tree(root->left);
    }
    printf("%d ",root->value);
    if(root->right!=NULL)
    {
        print_tree(root->right);
    }
}