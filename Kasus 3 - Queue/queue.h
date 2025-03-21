#include "LinkedList.h"

typedef struct {
    address head;
    address tail;
} Queue;

void createQueue(Queue *Q);
void enqueue(Queue *Q, infotype info);
void dequeue(Queue *Q, infotype *info);
void printQueue(Queue *Q);
int countQueue(Queue *Q);
void rekomendasiAntrian(Queue *Q1, Queue *Q2, infotype info);
void urutanProses(Queue *Q1, Queue *Q2, infotype *processed);