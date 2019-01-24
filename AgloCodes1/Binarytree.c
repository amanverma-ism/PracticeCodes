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

struct Node* createNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->data = key;
    node->parent = NULL;
    return node;
}

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

void inorder_treeTraversal(struct Node* root)
{
    if(root != NULL)
    {
        inorder_treeTraversal(root->left);
        printf("%d ", root->data);
        inorder_treeTraversal(root->right);
    }
}

void preorder_treeTraversal(struct Node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder_treeTraversal(root->left);
        preorder_treeTraversal(root->right);
    }
}

void postorder_treeTraversal(struct Node* root)
{
    if(root != NULL)
    {
        postorder_treeTraversal(root->left);
        postorder_treeTraversal(root->right);
        printf("%d ", root->data);
    }
}

void treeInsert(struct Node** rootref, struct Node* z)
{
    struct Node* y = NULL;
    struct Node* x = (*rootref);
    while(x!=NULL)
    {
        y = x;
        if(x->data > z->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    z->parent = y;
    if(y == NULL)
    {
        (*rootref) = z;
    }
    else if(z->data < y->data)
        y->left = z;
    else
        y->right = z;
}

void transplant(struct Node**rootref, struct Node* u, struct Node* v)
{
    if(u->parent == NULL)
        (*rootref) = v;
    else if(u==u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    if(v!=NULL)
        v->parent = u->parent;
}

void treeDelete(struct Node** rootref, struct Node* z)
{
    if(z->left == NULL)
        transplant(rootref, z, z->right);
    else if(z->right == NULL)
        transplant(rootref, z, z->left);
    else
    {
        struct Node* y = treeMinimum(z->right);
        if(y->parent != z)
        {
            transplant(rootref, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(rootref, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
}


int main()
{
    struct Node* root = NULL;

    treeInsert(&root, createNode(5));
    treeInsert(&root, createNode(3));
    treeInsert(&root, createNode(8));
    treeInsert(&root, createNode(2));
    treeInsert(&root, createNode(4));
    treeInsert(&root, createNode(6));
    treeInsert(&root, createNode(9));
    inorder_treeTraversal(root);
    printf("\n");
    preorder_treeTraversal(root);
    printf("\n");
    postorder_treeTraversal(root);
    printf("\n");
    treeDelete(&root, treeSearch(root, 8));
    inorder_treeTraversal(root);
    printf("\n");
    preorder_treeTraversal(root);
    printf("\n");
    postorder_treeTraversal(root);
    printf("\n");
    return 0;

}
