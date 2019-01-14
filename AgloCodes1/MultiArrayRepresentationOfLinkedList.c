#include<stdio.h>
#include<stdlib.h>

int key[10];
int next[10];
int prev[10];
int L;
int Free;

int allocate_object()
{
    if(Free == -1)
        return -1;
    else
    {
        int x = Free;
        Free = next[Free];
        return x;
    }
}

void free_object(int x)
{
    next[x] = Free;
    prev[x] = -2;
    Free = x;
}

void deletefromList(int x)
{
    x = x - 1;
    if(L == x)
    {
        L = next[x];
    }
    else if(next[x] == -1)
    {
        next[prev[x]] = -1;
    }
    else
    {
        next[prev[x]] = next[x];
        prev[next[x]] = prev[x];
    }
    free_object(x);
}

void addtoList(int data)
{
    int x = allocate_object();
    if(x == -1)
        return;
    if(L != -1)
    {
        prev[L] = x;
    }
    key[x] = data;
    prev[x] = -1;
    next[x] = L;
    L = x;
}

void compactify_list()
{
    int curr = L;
    int count = 0;
    while(curr!=-1)
    {
        count++;
        curr = next[curr];
    }
    int x = Free;
    while(x!=-1)
        {prev[x] = -10; x = next[x];}
    int head = 0;
    int tail = 9;
    while(head!= tail)
    {
        if(prev[head] == -10)
        {
            if(prev[tail] != -10)
            {
                if(tail == L)
                    L = head;
                else
                    next[prev[tail]] = head;
                prev[next[tail]] = head;
                key[head]= key[tail];
                next[head] = next[tail];
                prev[head] = prev[tail];
                head++;
                tail--;
            }
            else
            {
                tail--;
            }
        }
        else
        {
            head++;
        }
    }
    Free = count;
    int i;
    for(i = count; i<10-1; i++)
    {
        next[i] = i+1;
        prev[i] = -2;
    }
    next[i] = -1;
    prev[i] = -2;
}

void print_list()
{
    int x = L;
    while(x!=-1)
    {
        printf("%d ", key[x]);
        x = next[x];
    }
    printf("\n");
}

int main()
{
    L = -1;
    Free = 0;
    memset(key, 0, sizeof(int)*10);
    memset(next, 0, sizeof(int)*10);
    memset(prev, 0, sizeof(int)*10);
    int i;
    for(i=0; i<10 -1; i++)
        next[i] = i+1; prev[i] = -2;
    next[i] = -1;
    prev[i] = -2;
    addtoList(1); addtoList(2); addtoList(3); addtoList(4);
    addtoList(5); addtoList(6); addtoList(7); addtoList(8);
    addtoList(9); addtoList(10);
    deletefromList(4); deletefromList(7); deletefromList(10); deletefromList(1);
    addtoList(7); addtoList(10);
    deletefromList(3); deletefromList(9); deletefromList(1);
    print_list();
    printf("free = %d, L = %d\n", Free, L);

    printf("i\tkey\tnext\tprev\n");
    for(i = 0; i< 10; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i, key[i], next[i], prev[i]);
    }
    compactify_list();
    printf("free = %d, L = %d\n", Free, L);

    printf("i\tkey\tnext\tprev\n");
    for(i = 0; i< 10; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i, key[i], next[i], prev[i]);
    }
    print_list();
    return 0;
}
