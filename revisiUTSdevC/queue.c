#include "queue.h"

void createQueue(Queue *Q) {
    Q->head = Nil;
    Q->tail = Nil;
}

void enqueue(Queue *Q, infotype info, int level, address book, int isSingleLinkedList) {
    if (isSingleLinkedList) {
        enqueuePriorityTailSingle(Q, info, level, book);
    } else {
        enqueuePriorityTail(Q, info, level);
    }
}
void enqueuePriorityTail(Queue *Q, infotype info, int level) {
    address newNode = createNode(info);
    newNode->level = level;
    newNode->stok = 0;
    newNode->activityStack = (Stack*)malloc(sizeof(Stack));
    createStack(newNode->activityStack);

    if (Q->head == Nil) {
        Q->head = newNode;
        Q->tail = newNode;
        next(newNode) = Nil;
    } else if (level <= Q->head->level) {
        next(newNode) = Q->head;
        Q->head = newNode;
    } else if (level > Q->tail->level) {
        next(Q->tail) = newNode;
        next(newNode) = Nil;
        Q->tail = newNode;
    } else {
        address prev = Nil;
        address current = Q->head;
        while (current != Nil && current->level >= level) {
            prev = current;
            current = next(current);
        }
        next(newNode) = current;
        next(prev) = newNode;
        if (current == Nil) {
            Q->tail = newNode;
        }
    }
}

void enqueuePriorityTailSingle(Queue *Q, infotype info, int level, address book) {
    address newNode = createNode(info);
    newNode->level = level;
    newNode->stok = 0;
    newNode->activityStack = (Stack*)malloc(sizeof(Stack));
    createStack(newNode->activityStack);

    if (Q->head == Nil) {
        Q->head = newNode;
        Q->tail = newNode;
        next(newNode) = book; 
    } else if (level <= Q->head->level) {
        next(newNode) = Q->head;
        Q->head = newNode;
    } else {
        address prev = Nil;
        address current = Q->head;
        while (current != Nil && current != book && current->level < level) {
            prev = current;
            current = next(current);
        }
        next(newNode) = current;
        if (prev == Nil) {
            Q->head = newNode;
        } else {
            next(prev) = newNode;
        }
        if (current == book) {
            Q->tail = newNode;
        }
    }
}

void dequeue(Queue *Q, infotype *info) {
    if (Q->head == Nil) {
        *info = NULL;
        return;
    }

    if (Q->head == Q->tail) {
        *info = strdup(info(Q->head));
        free(Q->head->info);
        free(Q->head);
        Q->head = Nil;
        Q->tail = Nil;
        return;
    }

    address prev = Q->head;
    while (next(prev) != Q->tail) {
        prev = next(prev);
    }

    *info = strdup(info(Q->tail));
    free(Q->tail->info);
    free(Q->tail);
    Q->tail = prev;
    next(Q->tail) = Nil;
}

void dequeueSingle(Queue *Q, infotype *info, address book) {
    if (Q->head == Nil) {
        *info = NULL;
        return;
    }

    if (Q->head == Q->tail) {
        *info = strdup(info(Q->head));
        free(Q->head->info);
        free(Q->head);
        Q->head = Nil;
        Q->tail = Nil;
        return;
    }

    address prev = Q->head;
    address current = Q->head;
    while (next(current) != book) {
        prev = current;
        current = next(current);
    }

    *info = strdup(info(current));
    next(prev) = book;
    Q->tail = prev;
    free(current->info);
    free(current);
}