#include "Stack.h"

void createStack(Stack *S) {
    createList(&list(S));
}

void push(Stack *S, infotype info) {
    insertAtFirst(&list(S), info);
}

void pop(Stack *S, infotype *info) {
    deleteAtLast(&list(S), info);
}

void printStack(Stack S) {
    printList(S.list);
}

void convertDecimalToBinary(int num) {
    Stack S;
    createStack(&S);

    while (num > 0) {
        push(&S, num % 2);
        num /= 2;
    }

    printf("Biner: ");
    printStack(S);
}