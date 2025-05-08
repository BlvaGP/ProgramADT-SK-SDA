#ifndef STACK_H
#define STACK_H
#include "convention.h"

typedef char* infotypeStack;

typedef struct NodeStack *addressStack;
struct NodeStack {
    infotypeStack info;
    addressStack next;
};

typedef struct Stack {
    addressStack list;
} Stack;

typedef struct HistoryNode {
    infotype borrowerName;
    int level;
    Stack *activityStack;
    struct HistoryNode *next;
} HistoryNode;

typedef struct {
    HistoryNode *head;
} History;

extern History globalHistory;

void createStack(Stack *S);
void push(Stack *S, infotypeStack info);
void pop(Stack *S, infotypeStack *info);
void printStack(Stack *S);
void deallocateStack(Stack *S);

void createHistory(History *history);
void addToHistory(History *history, infotype borrowerName, int level, Stack *activityStack);
HistoryNode* findHistory(History *history, infotype borrowerName);
void deallocateHistory(History *history);

#endif