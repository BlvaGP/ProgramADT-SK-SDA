#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"

typedef struct Queue {
    address head;
    address tail;
} Queue;

void createQueue(Queue *Q);
void enqueue(Queue *Q, infotype info, int level, address book, int isSingleLinkedList);
void enqueuePriorityTail(Queue *Q, infotype info, int level);
void enqueuePriorityTailSingle(Queue *Q, infotype info, int level, address book);
void dequeueSingle(Queue *Q, infotype *info, address book);
void dequeue(Queue *Q, infotype *info);

#endif