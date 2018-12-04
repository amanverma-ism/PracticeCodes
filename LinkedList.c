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

void printInfiniteList(Node *head, int count)
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

void swapNodesForValue(Node **headref, int x, int y)
{
    if((*headref) == null || x == y)
        return;
    Node *first, *firstprev = NULL, *second, *secondprev = NULL;
    first = (*headref);
    while(first && first->data!=x)
     {
         firstprev = first;
         first = first->next;
     }
    second = (*headref);
    while(second && second->data!=y)
    {
        secondprev = second;
        second = second->next;
    }
    if(first==null || second == null)
        return;
    if(firstprev == null)
    {
        (*headref) = second;
    }
    else
    {
        firstprev->next = second;
    }
    if(secondprev == null)
    {
        (*headref) = first;
    }
    else
    {
        secondprev->next = first;
    }
    Node * temp = first->next;
    first->next = second->next;
    second->next = temp;
}

void swapNodes(Node **firstref, Node **secondref)
{
    if((*firstref) == null || (*secondref) == null)
        return;
    if((*firstref)->next == (*secondref))
    {
        Node *first = (*firstref);
        Node *second = (*secondref);
        (*firstref) = second;
        first->next = second->next;
        second->next = first;
        return;
    }
    Node *temp = (*firstref)->next;
    (*firstref)->next = (*secondref)->next;
    (*secondref)->next = temp;
    temp = (*firstref);
    (*firstref) = (*secondref);
    (*secondref) = temp;
}

void swapNodesPairwise(Node **headref)
{

    if((*headref) == null && (*headref)->next == null)
        return;
    swapNodes(headref, &((*headref)->next));
    Node *current = (*headref)->next;

    while(current!=null && current->next != null && current->next->next != null)
    {
        swapNodes(&current->next, &current->next->next);
        current = current->next->next;
    }
}

void movelastToFront(Node **headref)
{
    Node *current = (*headref);
    if(current== null || current->next == null)
    {
        return;
    }
    while(current->next->next != null)
        current = current->next;
    swapNodes(headref, &current->next);
}

int findIntersectionPoint(Node *head1, Node *head2)
{
    int c1 = GetTotalNodes(head1);
    int c2 = GetTotalNodes(head2);
    if(c2>c1)
    {
       int c = (c2-c1);
       while(c--)
            head2=head2->next;
       while(head1!=null && head2!=null)
       {
           if(head1 == head2)
            return head1->data;
           head1=head1->next;
           head2=head2->next;
       }
    }
    else
    {
        int c = (c1-c2);
       while(c--)
            head1=head1->next;
       while(head1!=null && head2!=null)
       {
           if(head1 == head2)
            return head1->data;
           head1=head1->next;
           head2=head2->next;
       }
    }
    return -1;
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
    /*Node *head2 = NULL;
    InsertAtLast(&head2, -1);
    InsertAtLast(&head2, -2);*/

    //head2->next->next = head->next->next->next;
    //InsertAtLast(&head, 6);
    //head->next->next->next->next->next->next = head->next->next;
    //int x, y;
    //printf("Enter x and y: ");
    //scanf("%d %d", &x, &y);
    PrintList(head);
    /*swapNodesPairwise(&(head));
    swapNodesForValue(&head, 1, 3);
    detectAndRemoveLoop(head);
    isListPalindrome(head);
    reverseList(&head);
    movelastToFront(&head);
    movelastToFront(&head);*/

    printf("\n%d\n", findIntersectionPoint(head, head2));
    printInfiniteList(head2, 20);
    return 0;
}
