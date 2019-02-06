#include<stdio.h>
#include<stdlib.h>

typedef enum Color
{
    black,
    red
} Color;

struct Node
{
    int data;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    Color color;
};

typedef enum bool
{
    false,
    true
} bool;

struct Node* NIL;

struct Node* createTree()
{
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->parent = NIL;
    root->data = 5;
    root->left = NIL;
    root->right = NIL;
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->parent = root;
    newnode->data = 3;
    newnode->left = NIL;
    newnode->right = NIL;
    root->left = newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->parent = root;
    newnode->data = 8;
    newnode->left = NIL;
    newnode->right = NIL;
    root->right = newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->parent = root->left;
    newnode->data = 2;
    newnode->left = NIL;
    newnode->right = NIL;
    root->left->left = newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->parent = root->left;
    newnode->data = 4;
    newnode->left = NIL;
    newnode->right = NIL;
    root->left->right = newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->parent = root->right;
    newnode->data = 6;
    newnode->left = NIL;
    newnode->right = NIL;
    root->right->left = newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->parent = root->right;
    newnode->data = 9;
    newnode->left = NIL;
    newnode->right = NIL;
    root->right->right = newnode;
    return root;
}

void preorder_treeTraversal(struct Node* head)
{
    if(head!=NIL)
    {
        printf("%d ", head->data);
        preorder_treeTraversal(head->left);
        preorder_treeTraversal(head->right);
    }
}

void printlevel(struct Node* head, int level)
{
    if(head!=NIL)
    {
        printf("%d ", level);
        printlevel(head->left, level + 1);
        printlevel(head->right, level + 1);
    }
}

void leftRotate(struct Node** headref, struct Node* x)
{
    if(x == NIL || x->right == NIL)
        return;
    struct Node* y = x->right;

    x->right = y->left;
    if(y->left != NIL)
        y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == NIL)
        (*headref) = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotate(struct Node** headref, struct Node* y)
{
    if(y == NIL || y->left == NIL)
        return;
    struct Node* x = y->left;
    y->left = x->right;
    if(x->right != NIL)
        x->right->parent = y;
    x->parent = y->parent;
    if(y->parent == NIL)
        (*headref) = x;
    else if(y->parent->left == y)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

int main()
{
    NIL = (struct Node*)malloc(sizeof(struct Node));
    NIL->color = black;
    struct Node* head = createTree();
    //rightRotate(&head, head);
    leftRotate(&head, head);
    printlevel(head, 1);
    printf("\n");
    preorder_treeTraversal(head);
}
