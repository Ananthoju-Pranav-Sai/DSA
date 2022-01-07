#include "node.c"

int main()
{
    Node *root;
    root = create_node(15);
    root->left = create_node(10);
    root->right = create_node(20);
    (root->left)->left = create_node(25);
    (root->left)->right = create_node(30);
    print_tree(root);
}