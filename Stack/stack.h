#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _snode SNode;
typedef struct _dynamic_stack Stack;

SNode* Node_create(int val);
Stack* Stack_create();

void Stack_push(Stack *stack, int val);
int Stack_peek(Stack *stack);
void Stack_pop(Stack *stack);
void Stack_print(const Stack *list);

#endif 
