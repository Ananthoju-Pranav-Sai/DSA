struct node
{
    struct node *left;
    struct node *right;
    int value;
};
typedef struct node Node;

Node *create_node(int x);
void print_tree(Node *root);


