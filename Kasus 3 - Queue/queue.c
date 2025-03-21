#include "queue.h"

void createQueue(Queue *Q) {
    head(Q) = Nil;
    tail(Q) = Nil;
}

void enqueue(Queue *Q, infotype info) {
    address newNode = createNode(info);
    
    if (head(Q) == Nil) {
        head(Q) = newNode;
        tail(Q) = newNode;
    } else {
        insertAtLast(&(tail(Q)), newNode);
        tail(Q) = newNode;
    }
}

void dequeue(Queue *Q, infotype *info) {
    deleteFirst(&(head(Q)), info);
    if (head(Q) ==  Nil) {
        tail(Q) = Nil;
    }
}

void printQueue(Queue *Q) {
    printList(head(Q));
}

int countQueue(Queue *Q) {
    return NbElmt(head(Q));
}

void rekomendasiAntrian(Queue *Q1, Queue *Q2, infotype info) {
    if (countQueue(Q1) <= countQueue(Q2)) {
        enqueue(Q1, info);
    } else {
        enqueue(Q2, info);
    }
}

void urutanProses(Queue *Q1, Queue *Q2, infotype *processed) {
    if (countQueue(Q1) > countQueue(Q2)) {
        dequeue(Q1, processed);
    } else {
        dequeue(Q2, processed);
    }
}