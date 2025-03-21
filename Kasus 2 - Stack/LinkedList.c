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
void deleteFirst(List *L, infotype *info) { 
    if (head(L) == Nil) return;

    address temp = head(L);
    *info = info(temp);  // Simpan nilai sebelum dihapus
    head(L) = next(head(L));
    free(temp);
}
