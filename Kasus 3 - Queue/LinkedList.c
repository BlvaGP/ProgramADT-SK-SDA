#include "LinkedList.h"

boolean isEmpty(address p) {
    return (p == Nil);
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
    *info = info(temp);  // Simpan nilai sebelum dihapus
    *L = next(*L);
    free(temp);
}

void printList(address L) {
    address p = L;
    printf("Antrian: ");
    while (p != Nil) {
        printf("%d -> ", info(p));
        p = next(p);
    }
    printf("Nil\n");
}

int NbElmt (address L) {
    address p = L;
    int count = 0;
    while (p != Nil) {
        count++;
        p = next(p);
    }
    return count;
}
