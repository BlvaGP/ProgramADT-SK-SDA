//file stack.h
#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"

typedef struct {
    address list;
} Stack;

//modules
void createStack(Stack *S);
void push(Stack *S, item info);
void pop(Stack *S, item *info);
void printChangesHistory(Stack *S);

#endif