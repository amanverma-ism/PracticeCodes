#include<stdio.h>
#include<stdlib.h>

int list[30];

int L;
int Free;

int allocate_object()
{
    int x = Free;
    Free = list[Free + 1];
    return x;
}

void insert_data(int data)
{
    int x = allocate_object();
    if(x == -1)
        return;
    if(L != -1)
        list[L + 2] = x;
    list[x] = data;
    list[x + 1] = L;
    list[x + 2] = -1;
    L = x;
}

void free_object(int x)
{
    list[x+1] = Free;
    list[x+2] = -2;
    Free = x;
}

void delete_data(int x)
{
    if(x == L)
    {
        L = list[x+1];
    }
    list[list[x+2] + 1] = list[x+1];
    if(list[x+1] != -1)
        list[list[x+1] + 2] = list[x+2];
    free_object(x);

}

void print_list()
{
    int x = L;
    while(x != -1)
    {
        printf("%d ", list[x]);
        x = list[x+1];
    }
    printf("\n");
}

int main()
{
    L = -1;
    Free = 0;
    memset(list, 0, sizeof(int)*30);
    int i;
    for(i=0; i<27; i= i + 3)
     {
         list[i+1] = i+3; list[i+2] = -2;
     }
    list[i + 1] = -1;
    list[i +2] = -2;
    insert_data(1); insert_data(2); insert_data(3); insert_data(4);
    insert_data(5); insert_data(6); insert_data(7); insert_data(8);
    insert_data(9); insert_data(10);
    print_list();
    delete_data((4 - 1)*3); delete_data((7 - 1)*3); delete_data((10 - 1)*3); delete_data((1 - 1)*3);
    print_list();
    insert_data(7); insert_data(10);
    print_list();
    delete_data((3 - 1)*3); delete_data((9 - 1)*3); delete_data((1 - 1)*3);
    print_list();
    printf("free = %d, L = %d\n", Free, L);

    printf("i\tkey\tnext\tprev\n");
    for(i = 0; i< 10; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i, list[i], list[i+1], list[i+2]);
    }

}
