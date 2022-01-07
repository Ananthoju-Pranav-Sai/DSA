#include "avl.c"

int main()
{
    Node *root = create_node(15);
    Node *x = create_node(10);
    root = insert_node(root,x);
    inorder(root);
    printf("\n%d",root->data);
    printf("\n");
    Node *a = create_node(30);
    root = insert_node(root,a);
    inorder(root);
    printf("\n%d",root->data);
    printf("\n");
    Node *b = create_node(40);
    root = insert_node(root,b);
    inorder(root);
    printf("\n%d",root->data);
    printf("\n");
    Node *c = create_node(50);
    root = insert_node(root,c);
    inorder(root);
    printf("\n%d",root->data);
    printf("\n");
    Node *d = create_node(25);
    root = insert_node(root,d);
    inorder(root);
    printf("\n%d",root->data);
    printf("\n");
    root = delete_node(root,d);
    inorder(root);
    printf("\n");
    search_node(root,a);
}