#include "sbtrees.h"

void Create_tree(Isi_Tree X, int Jml_Node) {
    for (int i = 0; i <= Jml_Node; i++) { 
        X[i].info = '\0';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }
}

boolean IsEmpty(Isi_Tree P) {
    return (P[1].info == '\0');
}

void InitVisited(boolean visited[]) {
    for (int i = 0; i <= jml_maks; i++) {
        visited[i] = false;
    }
}

/***** Traversal *****/

void PreOrder(Isi_Tree P) {
    if (P[1].info != '\0' && 1 <= jml_maks) {
        printf("%c ", P[1].info);
        if (P[1].ps_fs != 0 && P[1].ps_fs <= jml_maks) PreOrder(&P[P[1].ps_fs]);
        if (P[1].ps_nb != 0 && P[1].ps_nb <= jml_maks) PreOrder(&P[P[1].ps_nb]);
    }
}

void InOrder(Isi_Tree P) {
	//prosedur helper untuk rekursif
    void inorderHelper(Isi_Tree P, address curr) {
        if (curr == 0 || curr > jml_maks) return;

        if (P[curr].ps_fs != 0) {
            inorderHelper(P, P[curr].ps_fs);
        }

        if (P[curr].info != '\0') {
            printf("%c ", P[curr].info);
        }

        if (P[curr].ps_nb != 0) {
            inorderHelper(P, P[curr].ps_nb);
        }
    }

    if (IsEmpty(P)) return;
    inorderHelper(P, 1);
}

void PostOrder(Isi_Tree P) {
    if (P[1].info != '\0' && 1 <= jml_maks) {
        if (P[1].ps_fs != 0 && P[1].ps_fs <= jml_maks) PostOrder(&P[P[1].ps_fs]);
        if (P[1].ps_nb != 0 && P[1].ps_nb <= jml_maks) PostOrder(&P[P[1].ps_nb]);
        printf("%c ", P[1].info);
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    if (IsEmpty(X)) return;
    
    Isi_Queue Q;
    init_queue(&Q);
    
    enqueue(&Q, 1);
    
    while (!is_queue_empty(Q)) {
        address pcur = dequeue(&Q);
        if (pcur <= jml_maks && X[pcur].info != '\0') {
            printf("%c ", X[pcur].info);
            if (X[pcur].ps_fs != 0 && X[pcur].ps_fs <= jml_maks) {
                address child = X[pcur].ps_fs;
                enqueue(&Q, child);
                while (X[child].ps_nb != 0 && X[child].ps_nb <= jml_maks) {
                    child = X[child].ps_nb;
                    enqueue(&Q, child);
                }
            }
        }
    }
    printf("\n");
}

void PrintCode(Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Pohon kosong.\n");
        return;
    }
    
    printf("Seluruh Node pada Non Binary Tree:\n");
    for (address pcurr = 1; pcurr <= jml_maks; pcurr++) {
        if (P[pcurr].info == '\0') continue;
        
        printf("\n--> Indeks ke-%d\n", pcurr);
        printf("-----------------------------------\n");
        printf("info array ke %d        : %c\n", pcurr, P[pcurr].info);
        printf("first son array ke %d   : %d\n", pcurr, P[pcurr].ps_fs);
        printf("next brother array ke %d: %d\n", pcurr, P[pcurr].ps_nb);
        printf("parent array ke %d      : %d\n", pcurr, P[pcurr].ps_pr);
        printf("-----------------------------------\n");
    }
}

/***** Search *****/

boolean Search(Isi_Tree P, infotype X) {
    if (IsEmpty(P)) return false;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) return true;
    }
    return false;
}

/***** Fungsi Lain *****/

int nbElmt(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') count++;
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0' && P[i].ps_fs == 0) count++;
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    int idx = -1;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            idx = i;
            break;
        }
    }
    if (idx == -1) return -1; 

    int level = 0;
    while (P[idx].ps_pr != 0 && P[idx].ps_pr <= jml_maks) {
        idx = P[idx].ps_pr;
        level++;
    }
    return level;
}

int Depth(Isi_Tree P) {
    if (IsEmpty(P)) return 0;
    
    int max_depth = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            int depth = Level(P, P[i].info);
            if (depth > max_depth) max_depth = depth;
        }
    }
    return max_depth;
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}

/***** Queue *****/

void init_queue(Isi_Queue * Q) {
    Q->front = -1;
    Q->rear = -1;
}

boolean is_queue_empty(Isi_Queue Q) {
    return (Q.front == -1);
}

boolean is_queue_full(Isi_Queue Q) {
    return (Q.rear == MAX_QUEUE - 1);
}

void enqueue(Isi_Queue * Q, address node) {
    if (is_queue_empty(*Q)) {
        Q->front = 0;
    }
    Q->rear++;
    Q->data[Q->rear] = node;
}

address dequeue(Isi_Queue * Q) {
    address item = Q->data[Q->front];
    
    if (Q->front == Q->rear) {
        Q->front = -1;
        Q->rear = -1;
    } else {
        Q->front++;
    }
    
    return item;
}

/***** Stack *****/
void init_stack(Stack *S) {
    S->top = -1;
}

boolean is_stack_empty(Stack S) {
    return S.top == -1;
}

boolean is_stack_full(Stack S) {
    return S.top == MAX_STACK - 1;
}

void push(Stack *S, address node) {
    if (!is_stack_full(*S)) {
        S->top++;
        S->data[S->top] = node;
    }
}

address pop(Stack *S) {
    if (!is_stack_empty(*S)) {
        address node = S->data[S->top];
        S->top--;
        return node;
    }
    return 0;
}