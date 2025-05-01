#include "stack.h"

// Define globalHistory
History globalHistory;

void createStack(Stack *S) {
    list(S) = Nil;
}

void push(Stack *S, infotypeStack info) {
    addressStack newNode = (addressStack)malloc(sizeof(struct NodeStack));
    if (newNode != NULL) {
        info(newNode) = strdup(info);
        if (info(newNode) == NULL) {
            free(newNode);
            return; 
        }
        next(newNode) = list(S);
        list(S) = newNode;
    }
}

void pop(Stack *S, infotypeStack *info) {
    if (list(S) == Nil) {
        *info = NULL;
        return;
    }

    addressStack temp = list(S);
    *info = info(temp); 
    list(S) = next(temp);
    free(temp);
}

void printStack(Stack *S) {
    addressStack current = list(S);
    if (current == Nil) {
        printf("No activities.\n");
        return;
    }
    while (current != Nil) {
        printf("- %s\n", info(current));
        current = next(current);
    }
}

void deallocateStack(Stack *S) {
    addressStack current = list(S);
    while (current != Nil) {
        addressStack temp = current;
        current = next(current);
        free(info(temp)); 
        free(temp);       
    }
    list(S) = Nil;
}

void createHistory(History *history) {
    history->head = NULL;
}

void addToHistory(History *history, infotype borrowerName, int level, Stack *activityStack) {
    HistoryNode *current = history->head;
    while (current != NULL) {
        if (strcmp(current->borrowerName, borrowerName) == 0) {
            current->activityStack = activityStack;
            return;
        }
        current = current->next;
    }

    HistoryNode *newNode = (HistoryNode*)malloc(sizeof(HistoryNode));
    if (newNode == NULL) return; 
    newNode->borrowerName = strdup(borrowerName);
    if (newNode->borrowerName == NULL) {
        free(newNode);
        return; 
    }
    newNode->level = level;
    newNode->activityStack = activityStack;
    newNode->next = history->head;
    history->head = newNode;
}

HistoryNode* findHistory(History *history, infotype borrowerName) {
    HistoryNode *current = history->head;
    while (current != NULL) {
        if (strcmp(current->borrowerName, borrowerName) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deallocateHistory(History *history) {
    HistoryNode *current = history->head;
    while (current != NULL) {
        HistoryNode *temp = current;
        current = current->next;
        free(temp->borrowerName);
        if (temp->activityStack != NULL) {
            deallocateStack(temp->activityStack);
            free(temp->activityStack);
        }
        free(temp);
    }
    history->head = NULL;
}