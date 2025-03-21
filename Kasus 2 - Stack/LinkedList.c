//file LinkedList.c
#include "LinkedList.h"

//createList
void createList(List* L) {
    head(L) = Nil;
}

//createNode
address createNode(infotype info) {
    address p = (address)malloc(sizeof(node));
    if (p != Nil) {
        info(p) = info;
        next(p) = Nil;
    }
    return p;
}

//insert
void insertAtFirst(List *L, address newP) {
    if (newP != Nil){
        next(newP) = head(L);
        head(L) = newP;
    }
}

//delete
void deleteLast(List *L, infotype *info) { //menghapus node paling terakhir
    if (head(L) == Nil) return;
    address temp = L->head, prev = NULL;

    if (next(temp) == Nil) {
        *info = info(temp);
        free(temp);
        head(L) = Nil;
        return;
    }

    while (next(temp) != Nil) {
        prev = temp;
        temp = next(temp);
    }
    *info = info(temp);
    next(prev) = Nil;
    free(temp);
}

void printList(address head) {
    address p = head;
    while (p != Nil) {
        printf("%d -> ", info(p));
        p = next(p);
    }
    printf("Nil\n");
}