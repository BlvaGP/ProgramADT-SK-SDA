#include "Stack.h"

void createStack(Stack *S) {
    createList(&list(S));
}

void push(Stack *S, infotype info) {
    address newP = createNode(info);
    insertAtFirst(&list(S), newP);
}

void pop(Stack *S, infotype *info) {
    deleteFirst(&list(S), info);
}

void convertDecimalToBinary(int num) {
    Stack S;
    createStack(&S);

    while (num > 0) {
        push(&S, num % 2);
        num /= 2;
    }

    printf("Biner: ");
    while (S.list.head != Nil) {
        int bit;
        pop(&S, &bit);
        printf("%d", bit);
    }
    printf("\n");
}