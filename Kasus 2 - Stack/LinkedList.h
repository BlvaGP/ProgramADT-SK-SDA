#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "convention.h" 

typedef int infotype;
typedef struct Node {
    infotype info;
    struct Node *next;
} node;

typedef node* address;

typedef struct {
    address head;
} List;

void createList(List* L);

address createNode(infotype info);
void insertAtFirst(List *L, address newP);
void deleteFirst(List *L, infotype *info);

#endif