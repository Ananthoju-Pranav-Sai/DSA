#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

Node *create_node(int x)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void insert_node(Node *root,Node *x)
{
    if(root==NULL)
    {
        root=x;
        return;
    }
    else
    {
        if(root->data>x->data)
        {
            if(root->left==NULL)
                root->left=x;
            else
                insert_node(root->left,x);
        }
        else
        {
            if(root->right==NULL)
                root->right=x;
            else
                insert_node(root->right,x);
        }
    }
}
Node *parent(Node *root,Node *x)
{
    Node *p = NULL;
    if(root->left == x || root->right == x)
    {
        p = root;
    }
    else if(root->data > x->data)
    {
        p = parent(root->left,x);
    }
    else
    {
        p = parent(root->right,x);
    }
    return p;
}
Node *succesor(Node *root,Node *x)
{
    Node *p=x->right;
    if(p!=NULL)
    {
        while(p->left!=NULL)
        {
            p=p->left;
        }
        return p;
    }
    p = parent(root,x);
    while(p!=NULL && x==p->right)
    {
        x=p;
        p=parent(root,p);
    }
    return p;
}
void search_node(Node *root,Node *x)
{
    if(root->data!=x->data && parent(root,x)==NULL)
    {
        printf("Element not found\n");
        return;
    }
    printf("Element found\n");
}
void delete_node(Node *root,Node *x)
{
    if(x->left==NULL && x->right==NULL)
    {
        Node *p=parent(root,x);
        if(p->left==x)
            p->left=NULL;
        else
            p->right=NULL;
        return;
    }
    else if(x->left!=NULL && x->right==NULL)
    {
        Node *p=parent(root,x);
        if(p->left==x)
            p->left=x->left;
        else
            p->right=x->left;
        return;
    }
    else if(x->left==NULL && x->right!=NULL)
    {
        Node *p=parent(root,x);
        if(p->left==x)
            p->left=x->right;
        else
            p->right=x->right;
        return;
    }
    else
    {
        Node *s=succesor(root,x);
        if(x==root)
        {
            root->data=s->data;
            delete_node(root,s);
        }
        else
        {
            x->data = s->data;
            delete_node(root,s);
        }
    }
}
void inorder(Node *root)
{
    if(root->left!=NULL)
        inorder(root->left);
    printf("%d ",root->data);
    if(root->right!=NULL)
        inorder(root->right);
}