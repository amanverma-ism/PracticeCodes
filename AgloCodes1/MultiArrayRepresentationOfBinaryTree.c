#include<stdio.h>
#include<stdlib.h>
#include "Stack.c"

int key[10];
int right[10];
int left[10];
int Root;
int x=10;
void print_tree(int root)
{
    if(root == -1)
        return;
    print_tree(left[root]);
    printf("%d ", key[root]);
    print_tree(right[root]);

}

void print_treeNonRecursive(int root)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    push(stack, root);

    while(!stack_empty(stack))
    {
        int currkey = top(stack);
        while(currkey!=-1)
        {
            push(stack, left[currkey]);
            currkey = left[currkey];
        }
        if(!stack_empty(stack))
        {
            pop(stack);
        }
        if(!stack_empty(stack))
        {
            currkey = pop(stack);
            printf("%d ", key[currkey]); x--;
            push(stack, right[currkey]);
        }
    }
}

int main()
{
    Root = 0;
    int i;
    key[0] = 1; key[1] = 2; key[2] = 3; key[3] = 4; key[4] = 5; key[5] = 6; key[6] = 7; key[7] = 8; key[8] = 9; key[9] = 10;
    left[0] = 1; left[1] = 3; left[2] = 5; left[3] = 7; left[4] = 9; left[5] = -1; left[6] = -1; left[7] = -1; left[8] = -1; left[9] = -1;
    right[0] = 2; right[1] = 4; right[2] = 6; right[3] = 8; right[4] = -1; right[5] = -1; right[6] = -1; right[7] = -1; right[8] = -1; right[9] = -1;

    print_tree(Root);
    printf("\n");
    print_treeNonRecursive(Root);

    return 0;
}

