#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "convention.h" 

typedef int infotype;
typedef struct Node {
    infotype info;
    struct Node *next;
} node;

typedef node* address;

boolean isEmpty(address p);
address createNode(infotype info);
void insertAtLast(address *L, address newP);
void deleteFirst(address *L, infotype *info);
void printList(address L);
int NbElmt (address L);

#endif