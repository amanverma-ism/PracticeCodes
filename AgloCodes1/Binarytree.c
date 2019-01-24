#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
};

typedef enum bool
{
    false,
    true
} bool;

struct Node* createTree()
{
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->parent = NULL;
    root->data = 5;
    root->left = NULL;
    root->right = NULL;
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->parent = root;
    newnode->data = 3;
    newnode->left = NULL;
    newnode->right = NULL;
    root->left = newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->parent = root;
    newnode->data = 8;
    newnode->left = NULL;
    newnode->right = NULL;
    root->right = newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->parent = root->left;
    newnode->data = 2;
    newnode->left = NULL;
    newnode->right = NULL;
    root->left->left = newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->parent = root->left;
    newnode->data = 4;
    newnode->left = NULL;
    newnode->right = NULL;
    root->left->right = newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->parent = root->right;
    newnode->data = 6;
    newnode->left = NULL;
    newnode->right = NULL;
    root->right->left = newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->parent = root->right;
    newnode->data = 9;
    newnode->left = NULL;
    newnode->right = NULL;
    root->right->right = newnode;
    return root;
}

void non_recursive_inorder_tree_traversal(struct Node* root)
{
    struct Node* current, left, right, prev;
    bool leftdone = false;
    current = root;
    while(current != NULL)
    {
        if(leftdone == false)
        {
            while(current->left != NULL)
                current = current->left;
            leftdone = true;
        }
        printf("%d ", current->data);
        if(current->right != NULL)
        {
            current = current->right;
            leftdone = false;
        }
        else if(current->parent != NULL)
        {
            while(current != NULL && current->parent!=NULL && current != current->parent->left)
                current = current->parent;
            if(current != NULL)
            {
                current = current->parent;
            }
            else
                break;
        }
        else
            break;
    }
}

struct Node* treeSearch(struct Node* root, int key)
{
    if(root == NULL || root->data == key)
        return root;
    if(key < root->data)
        return treeSearch(root->left, key);
    else
        return treeSearch(root->right, key);
}

struct Node* treeMinimum(struct Node* root)
{
    while(root->left!=NULL)
        root = root->left;
    return root;
}

struct Node* treeMaximum(struct Node* root)
{
    while(root->right!=NULL)
        root = root->right;
    return root;
}

struct Node* treeSuccessor(struct Node* x)
{
    if(x->right!=NULL)
        return treeMinimum(x->right);
    struct Node* y = x->parent;
    while(y!=NULL && y->right == x)
    {
        x = y;
        y = y->parent;
    }
    return y;
}



struct Node* treePredecessor(struct Node* x)
{
    if(x->left!=NULL)
        return treeMaximum(x->left);
    struct Node* y = x->parent;
    while(y!=NULL && y->left == x)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

int main()
{
    struct Node* root = createTree();
    printf("%d", treeSuccessor(treeSearch(root, 5))->data);
    return 0;

}
