#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "stack.h"
#include "convention.h"

typedef struct Node* address;
typedef struct DNode* dAddress;

struct Node {
    infotype info;        
    int stok;             
    int level;            
    address next;         
    Stack *activityStack; 
};

struct DNode {
    infotype info;        
    int stok;             
    address queueHead;    
    dAddress next;        
};

void createList(address *L);
address createNode(infotype info);
void insertAtFirst(address *L, address newP);
void insertAtLast(address *L, address newP);
void insertBeforeBetween(address *L, address newP);
void insertAfterBetween(address *L, address newP);
void insertBeforeValue(address *L, infotype targetInfo, infotype newInfo); 
void insertAfterValue(address L, infotype targetInfo, infotype newInfo);  
void insertSortedByPriority(address *L, address newP);
void DeAlokasi(address *L);
address searchNode(address L, infotype info);
boolean FSearch(address L, address P);
address searchPrec(address L, infotype info);
void deleteFirst(address *L, infotype *info);
void deleteLast(address *L, infotype *info);
void deleteBeforeBetween(address *L);
void deleteAfterBetween(address *L);
void deleteValue(address *L, infotype info);
void modifyAtFirst(address *L, int newInfo);
void modifyAtLast(address *L, int newInfo);
void modifyBeforeBetween(address *L, int newInfo);
void modifyAfterBetween(address *L, int newInfo);
void modifyValue(address *L, int targetInfo, int newInfo);
int countNode(address L);
void printList(address L);
infotype Max(address L);
address addressMax(address L);
infotype Min(address L);
address addressMin(address L);
infotype Average(address L);

void createDList(dAddress *L);
dAddress createDNode(infotype info);
void insertAtFirstDList(dAddress *L, dAddress newP);
void insertAtLastDList(dAddress *L, dAddress newP);
void deAlokasiDList(dAddress *L);
dAddress searchDNode(dAddress L, infotype info);
void deleteFirstDList(dAddress *L, infotype *info);
void deleteLastDList(dAddress *L);
void deleteValueDList(dAddress *L, infotype info);

#endif