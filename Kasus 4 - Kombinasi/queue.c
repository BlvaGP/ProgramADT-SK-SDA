//file queue.c
#include "queue.h"

void createQueue(Queue *Q) {
    head(Q) = Nil;
    tail(Q) = Nil;
}

void enqueue(Queue *Q, item info) {
    address newNode = createNode(info);
    
    if (head(Q) == Nil) {
        head(Q) = newNode;
        tail(Q) = newNode;
    } else {
        insertAtLast(&(tail(Q)), newNode);
        tail(Q) = newNode;
    }
}

void dequeue(Queue *Q, item *info) {
    deleteFirst(&(head(Q)), info);
    if (head(Q) ==  Nil) {
        tail(Q) = Nil;
    }
}

void printCart(Queue *Q) {
    if (head(Q) == Nil) {
        printf("Keranjang kosong\n");
        return;
    }
    address p = head(Q);
    while (p != Nil) {
        printf("Nama: %s, Kategori: %s, Jumlah: %d, Harga: %.2f, Total Harga: %.2f\n",
               info(p).nama, info(p).kategori, info(p).jumlah, info(p).harga, info(p).total);
        p = next(p);
    }
}

int countQueue(Queue *Q) {
    return NbElmt(head(Q));
}

void deleteFromCart(Queue *Q, item info) {
    deleteValue(&(head(Q)), info);
    if (head(Q) == Nil) {
        tail(Q) = Nil; 
    }
}