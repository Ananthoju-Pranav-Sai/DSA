struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node* create_node(int d);
void print_tree(Node *root);
void insert_node(Node *x,Node *root);
void delete_node(Node *x,Node *root);

