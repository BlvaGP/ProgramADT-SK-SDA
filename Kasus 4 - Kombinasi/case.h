//file case.h
#include "stack.h"
#include "queue.h"

void addItem(Queue *cart);
void buyItem(Queue *cart, Stack *history);
void undoItem(Queue *cart, Stack *history);
void deleteItem(Queue *cart, Stack *history);