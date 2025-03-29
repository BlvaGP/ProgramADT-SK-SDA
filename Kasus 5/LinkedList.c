#include "LinkedList.h"

//createNode
address createNode(infotype info) {
    address p = (address)malloc(sizeof(node));
    if (p != Nil) {
        info(p) = strdup(info);
        next(p) = Nil;
    }
    return p;
}

//insert
void insertAtLast(address *L, address newP) {
    if (newP == Nil) return;
    next(newP) = Nil;
    
    if (*L == Nil) {
        *L = newP;
    } else {
        address last = *L;
        while (next(last) != Nil)
        {
            last = next(last);
        }
        next(last) = newP;
    }
}

//delete
void deleteFirst(address *L, infotype *info) { 
    if (*L == Nil) return;

    address temp = *L;
    *info = info(temp);
    *L = next(*L);
    free(info(temp));
    free(temp);
}

void deleteValue(address *L, infotype info) { 
    if (*L == Nil) return;

    if (strcmp(info(*L), info) == 0) {
        deleteFirst(L, &info);
        return;
    }

    address prev = *L, temp = next(*L);
    while (temp != Nil && strcmp(info(temp), info) != 0) 
    {
        prev = temp;
        temp = next(temp);
    }
    
    if (temp != Nil) {
        next(prev) = next(temp);
        free(info(temp));
        free(temp);
    }
}

void DeAlokasi (address *L) {
    address temp;
    while (*L != Nil)
    {
        temp = *L;
        *L = next(*L);
        free(info(temp));
        free(temp);
    }  
    *L = Nil; 
}