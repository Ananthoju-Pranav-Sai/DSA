#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
Node *create_node(int x)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int height(Node *root)
{
    int h=0;
    if(root==NULL)
        return -1;
    else
    {
        h=1+max(height(root->left),height(root->right)); 
    }
    return h;
}
int balance(Node *root)
{
    return (height(root->left)-height(root->right));
}
Node *left_rotate(Node *root)
{
    Node *y = root->right;
    Node *T2 = y->left;
    y->left=root;
    root->right=T2;
    return y;
}
Node *right_rotate(Node *root)
{
    Node *x = root->left;
    Node *T2 = x->right;
    x->right=root;
    root->left=T2;
    return x;
}
Node *insert_node(Node *root,Node *x)
{
    if (root == NULL)
    {
        root = x;
        return root;
    }
    if (x->data < root->data)
        root->left = insert_node(root->left, x);
    else 
        root->right = insert_node(root->right, x);

    int b = balance(root);
    printf("%d\n",b);
    if(b>1 && (root->left)->data>x->data)
    {
        return(right_rotate(root));
    
    }
    if(b<-1 && (root->right)->data<x->data)
    {
        return(left_rotate(root));
    }
    if(b>1 && (root->left)->data<x->data)
    {
        root->left = left_rotate(root->left);
        return(right_rotate(root));
    }
    if(b<-1 && (root->right)->data>x->data)
    {
        root->right = right_rotate(root->right);
        return(left_rotate(root));
    }
    return root;
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
Node *delete_node(Node *root,Node *x)
{
    if(x->left==NULL && x->right==NULL)
    {
        Node *p=parent(root,x);
        if(p->left==x)
            p->left=NULL;
        else
            p->right=NULL;
    }
    else if(x->left!=NULL && x->right==NULL)
    {
        Node *p=parent(root,x);
        if(p->left==x)
            p->left=x->left;
        else
            p->right=x->left;
    }
    else if(x->left==NULL && x->right!=NULL)
    {
        Node *p=parent(root,x);
        if(p->left==x)
            p->left=x->right;
        else
            p->right=x->right;
    }
    else
    {
        Node *s=succesor(root,x);
        if(x==root)
        {
            root->data=s->data;
            root = delete_node(root,s);
        }
        else
        {
            x->data = s->data;
            root = delete_node(root,s);
        }
    }
    int b = balance(root);
    printf("%d\n",b);
    if(b>1 && (root->left)->data>x->data)
    {
        return(right_rotate(root));
    
    }
    if(b<-1 && (root->right)->data<x->data)
    {
        return(left_rotate(root));
    }
    if(b>1 && (root->left)->data<x->data)
    {
        root->left = left_rotate(root->left);
        return(right_rotate(root));
    }
    if(b<-1 && (root->right)->data>x->data)
    {
        root->right = right_rotate(root->right);
        return(left_rotate(root));
    }
    return root;
}
void inorder(Node *root)
{
    if(root->left!=NULL)
        inorder(root->left);
    printf("%d ",root->data);
    if(root->right!=NULL)
        inorder(root->right);
}