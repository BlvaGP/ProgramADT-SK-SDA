#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "convention.h" 

typedef char* infotype;

typedef struct Node {
    infotype info;
    struct Node *next;
} node;

typedef node* address;

address createNode(infotype info);
void insertAtLast(address *L, address newP);
void deleteFirst(address *L, infotype *info);
void deleteValue(address *L, infotype info);
void DeAlokasi (address *L);

#endif