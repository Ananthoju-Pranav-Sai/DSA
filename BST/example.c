#include "bst.c"

int main()
{
    Node *root = create_node(15);
    Node *x = create_node(10);
    insert_node(root,x);
    inorder(root);
    printf("\n");
    Node *a = create_node(30);
    insert_node(root,a);
    inorder(root);
    printf("\n");
    Node *b = create_node(40);
    insert_node(root,b);
    inorder(root);
    printf("\n");
    Node *c = create_node(50);
    insert_node(root,c);
    inorder(root);
    printf("\n");
    Node *d = create_node(25);
    insert_node(root,d);
    inorder(root);
    printf("\n");
    Node *p = parent(root,b);
    printf("%d\n",p->data);
    delete_node(root,root);
    inorder(root);
    printf("\n");
    Node *s = succesor(root,root);
    printf("%d\n",s->data);
}