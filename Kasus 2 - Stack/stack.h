#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"

typedef struct {
    List list;
} Stack;

#define list(s) (s)->list

//modules
void createStack(Stack *S);
void push(Stack *S, infotype info);
void pop(Stack *S, infotype *info);
void convertDecimalToBinary(int num);

#endif