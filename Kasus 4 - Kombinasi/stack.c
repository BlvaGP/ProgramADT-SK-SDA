//file stack.c
#include "Stack.h"

void createStack(Stack *S) {
    list(S) = Nil;
}

void push(Stack *S, item info) {
    address newP = createNode(info);
    insertAtFirst(&list(S), newP);
}

void pop(Stack *S, item *info) {
    deleteFirst(&list(S), info);
}

void printChangesHistory(Stack *S) {
    if (list(S) == Nil) {
        printf("Riwayat kosong\n");
        return;
    }
    address p = list(S);
    while (p != Nil) {
        printf("Aksi: %s (%s), Kategori: %s, Jumlah: %d, Harga: %.2f, Total Harga: %.2f\n",
               info(p).nama, info(p).aksi, info(p).kategori, info(p).jumlah, info(p).harga, info(p).total);
        p = next(p);
    }
}