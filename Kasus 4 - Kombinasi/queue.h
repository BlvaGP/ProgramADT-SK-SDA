//file queue.h
#include "LinkedList.h"

typedef struct {
    address head;
    address tail;
} Queue;

void createQueue(Queue *Q);
void enqueue(Queue *Q, item info);
void dequeue(Queue *Q, item *info);
void printCart(Queue *Q);
int countQueue(Queue *Q);
void deleteFromCart(Queue *Q, item info);