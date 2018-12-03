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

void InsertAtLast(Node **headref, int data)
{
    if((*headref) == null)
    {
        (*headref) = (Node*)malloc(sizeof(Node));
        (*headref)->data = data;
        (*headref)->next = NULL;
    }
    else
    {
        Node *current = (*headref);
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = (Node*)malloc(sizeof(Node));
        current= current->next;
        current->data = data;
        current->next = NULL;
    }
}

void InsertInFront(Node **headref, int data)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = (*headref);
    (*headref) = newnode;
}

void InsertAfter(Node *node, int data)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = node->next;
    node->next = newnode;
}

void deleteNode(Node **headref, int key)
{
    if((*headref) == null)
        return;
    Node *current = (*headref);
    if(current->data == key)
    {
        (*headref) = current->next;
        free(current);
        return;
    }
    while(current->next != null)
    {
        if(current->next->data == key)
        {
            Node *tobedeleted = current->next;
            current->next = tobedeleted->next;
            free(tobedeleted);
            break;
        }
        current = current->next;
    }
}

void PrintList(Node *head)
{
    while(head!=NULL)
    {
        printf("%d", head->data);
        head = head->next;
        if(head!=NULL)
            printf(" -> ");
        else
            printf("\n");
    }
}

void deleteList(Node **headref)
{
    if((*headref) == null)
        return;
    deleteList(&((*headref)->next));
    free((*headref));
    (*headref) = null;
}

int GetTotalNodes(Node *head)
{
    int count = 0;
    while(head!=null)
    {
        count++;
        head=head->next;
    }
    return count;
}

int getTotalNodesRecursive(Node *head)
{
    if(head == null)
        return 0;
    return getTotalNodesRecursive(head->next) + 1;
}

bool detectLoop(Node *head)
{
    if(head == null || head->next == null)
        return false;
    Node *second = head->next;
    while(head!=null && second!=null)
    {
        if(head == second)
            return true;
        head = head->next;
        second = second->next;
        if(second!=null)
            second = second->next;
    }
    return false;
}

void reverseList(Node **headref)
{
    Node *prev=NULL, *current = (*headref), *next;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headref = prev;
}

bool compareLists(Node *head1, Node *head2)
{
    while(head1 && head2)
    {
        if(head1->data != head2->data)
            return false;
        head1=head1->next;
        head2=head2->next;
    }
    if(head1 == null && head2 == null)
        return true;
    return false;
}

bool isListPalindrome(Node *head)
{
    Node *slowPtr = head, *fastPtr = head, *prev_of_slow_ptr = head, *midnode=null;
    bool res = true;
    if(head && head->next)
    {
        while(fastPtr && fastPtr->next)
        {
            fastPtr = fastPtr->next->next;
            prev_of_slow_ptr = slowPtr;
            slowPtr = slowPtr->next;
        }
        if(fastPtr == null)
        {
            prev_of_slow_ptr->next = null;
            reverseList(&slowPtr);
            res = compareLists(head, slowPtr);
            reverseList(&slowPtr);
            prev_of_slow_ptr->next = slowPtr;
        }
        else
        {
            midnode = slowPtr;
            slowPtr = slowPtr->next;
            prev_of_slow_ptr->next = null;
            reverseList(&slowPtr);
            res = compareLists(head, slowPtr);
            reverseList(&slowPtr);
            slowPtr = midnode;
            prev_of_slow_ptr->next = slowPtr;
        }
    }
    return res;
}

void detectAndRemoveLoop(Node *head)
{
    Node *slowPtr = head, *fastPtr=head;
    if(slowPtr && slowPtr->next)
    {
        while(fastPtr && fastPtr->next)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(slowPtr == fastPtr)
                break;
        }
        if(fastPtr == NULL || fastPtr->next == NULL)
            return;
        int k=0;
        while(true)
        {
            fastPtr = fastPtr->next;
            k++;
            if(slowPtr == fastPtr)
                break;
        }
        printf("%d is k\n", k);
        slowPtr = head;
        fastPtr = head;
        int i=0;
        for(i =0; i<k; i++)
            fastPtr = fastPtr->next;
        printf("value of fastptr %d, value of slowptr %d\n", fastPtr->data, slowPtr->data);
        Node *prev = NULL;
        while(slowPtr != fastPtr)
        {
            prev = fastPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        prev->next = NULL;
    }
}

void PrintInfiniteList(Node *head, int count)
{
    while(head!=NULL && count--)
    {
        printf("%d", head->data);
        head = head->next;
        if(head!=NULL)
            printf(" -> ");
        else
            printf("\n");
    }
}


int main()
{
    Node *head = NULL;
    char ch='Y';
    int data;
    InsertAtLast(&head, 1);
    InsertAtLast(&head, 2);
    InsertAtLast(&head, 3);
    InsertAtLast(&head, 4);
    InsertAtLast(&head, 5);
    //InsertAtLast(&head, 6);
    //head->next->next->next->next->next->next = head->next->next;
    PrintInfiniteList(head, 20);
    printf("\n");
    detectAndRemoveLoop(head);
    PrintList(head);
    return 0;
}
