#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
    int data[50];
    int top;
} Stack;

typedef enum bool
{
    false,
    true
} bool;

bool stack_empty(Stack *stack)
{
    if(stack->top == -1)
        return true;
    else
        return false;
}

void push(Stack *stack, int x)
{
    stack->top++;
    stack->data[stack->top] = x;
}

int pop(Stack *stack)
{
    if(stack_empty(stack))
        return -1;
    else
    {
        stack->top = stack->top - 1;
        return stack->data[stack->top + 1];
    }
}

int main()
{
    Stack *stack;
    stack = (Stack*)malloc(sizeof(stack));
    stack->top = -1;
    push(stack, 2);
    push(stack, 5);
    push(stack, 1);
    printf("Popped %d\n", pop(stack));
    push(stack, 9);
    printf("Popped %d\n", pop(stack));
    return 0;
}
