#include<stdio.h>
#include<stdlib.h>
#define null ((void *)0)

typedef enum bool
{
    false,
    true
} bool;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void push(Node **lastref, int data)
{
    if((*lastref) == null)
    {
        Node *newnode = (Node*)malloc(sizeof(Node));
        newnode->data = data;
        newnode->next = newnode;
        (*lastref) = newnode;
    }
    else
    {
        Node *newnode = (Node*)malloc(sizeof(Node));
        newnode->data = data;
        newnode->next = (*lastref)->next;
        (*lastref)->next = newnode;
        (*lastref) = newnode;
    }
}

void printList(Node *last)
{
    if(last == null)
        return;
    Node *current = last;
    do
    {
        current = current->next;
        printf("%d", current->data);
        if(current != last)
            printf("->");
        else
            printf("\n");
    } while(current != last);
}

int main()
{
    Node *last = null;
    push(&last, 1);
    push(&last, 2);
    push(&last, 3);
    printList(last);
    return 0;
}
