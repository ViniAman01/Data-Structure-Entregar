#include "stack.h"

struct _snode
{
    int val;
    SNode *next;
    SNode *prev;
};

struct _dynamic_stack
{
    SNode *top;
    SNode *end;
    int size;
};

SNode *Node_create(int val)
{
    SNode *node = (SNode*)malloc(sizeof(SNode));
    node->next = NULL;
    node->prev = NULL;
    node->val = val;
    return node;
}

Stack* Stack_create()
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->end = NULL;
    stack->size = 0;
    return stack;
}

void Stack_push(Stack *stack, int val)
{
    SNode *node = Node_create(val);
    if(stack->size == 0)
    {
        stack->top = node; 
    }
    else
    {
        node->next = stack->top;
        stack->top->prev = node;
        stack->top = node;
    }
    stack->size++;
}

int Stack_peek(Stack *stack)
{
    return stack->top->val;
}

void Stack_pop(Stack *stack)
{
    SNode *node;
    node = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    free(node);
}

void Stack_print(const Stack *stack)
{
    SNode *node = stack->top;
    while(node != NULL)
    {
        printf("%d ",node->val);
        node = node->next;
    }
    printf("\n");
}
