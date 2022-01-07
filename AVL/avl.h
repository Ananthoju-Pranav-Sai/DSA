struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

Node *create_node(int x);
int height(Node *root);
int balance(Node *root);
Node *left_rotate(Node *root);
Node *right_rotate(Node *root);
Node *insert_node(Node *root,Node *x);
Node *parent(Node *root,Node *x);
void search_node(Node *root,Node *x);
Node *succesor(Node *root,Node *x);
Node *delete_node(Node *root,Node *x);
void inorder(Node *root);