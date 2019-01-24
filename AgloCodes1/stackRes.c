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

int top(Stack* stack)
{
    if(stack_empty(stack))
        return -1;
    else
        return stack->data[stack->top];
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
