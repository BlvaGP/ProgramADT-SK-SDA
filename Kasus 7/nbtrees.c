#include "nbtrees.h"

void Create_tree(Isi_Tree X, int Jml_Node) {
    for (int i = 0; i <= Jml_Node; i++) {
        X[i].info = '\0';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }
    return;
}

boolean IsEmpty (Isi_Tree P) {
    return (P[1].info == '\0');
}

/***** Traversal *****/

void PreOrder (Isi_Tree P) {
    if (IsEmpty(P)) return;
    
    boolean visited[jml_maks + 1];
    InitVisited(visited);

    address pcurr = 1;
    printf("%c ", P[pcurr].info);
    visited[pcurr] = true;
    
    while (pcurr != nil) {
        if (P[pcurr].ps_fs != nil && !visited[P[pcurr].ps_fs]) {
            pcurr = P[pcurr].ps_fs;
            printf("%c ", P[pcurr].info);
            visited[pcurr] = true;
        } else if (P[pcurr].ps_nb != nil && !visited[P[pcurr].ps_nb]) {
            pcurr = P[pcurr].ps_nb;
            printf("%c ", P[pcurr].info);
            visited[pcurr] = true;
        } else {
            pcurr = P[pcurr].ps_pr;
        }
    }
    printf("\n");
}

void InOrder (Isi_Tree P) {
    if (IsEmpty(P)) return;
    
    boolean visited[jml_maks + 1];
    InitVisited(visited);
    
    address pcurr = 1;
    
    while (pcurr != nil) {
        if (P[pcurr].ps_fs != nil && !visited[P[pcurr].ps_fs]) {
            pcurr = P[pcurr].ps_fs;
        } else {
            if (!visited[pcurr]) {
                printf("%c ", P[pcurr].info);
                visited[pcurr] = true;
            }
            
            if (P[pcurr].ps_pr != nil && pcurr == P[P[pcurr].ps_pr].ps_fs && !visited[P[pcurr].ps_pr]) {
                printf("%c ", P[P[pcurr].ps_pr].info);
                visited[P[pcurr].ps_pr] = true;
            }
            
            if (P[pcurr].ps_nb != nil && !visited[P[pcurr].ps_nb]) {
                pcurr = P[pcurr].ps_nb;
            } else {
                pcurr = P[pcurr].ps_pr;
            }
        }
    }
    printf("\n");
}

void PostOrder (Isi_Tree P) {
    if (IsEmpty(P)) return;
    
    boolean visited[jml_maks + 1];
    InitVisited(visited);

    address pcurr = 1;
    address arah = kebawah;
    
    while (pcurr != nil) {
        switch (arah) {
            case kebawah:
                if (P[pcurr].ps_fs != nil && !visited[P[pcurr].ps_fs]) {
                    arah = kebawah;
                    pcurr = P[pcurr].ps_fs;
                } else if (P[pcurr].ps_fs == nil && P[pcurr].ps_nb != nil && !visited[P[pcurr].ps_nb]) {
                    arah = kekanan;
                    if (!visited[pcurr]) {
                        printf("%c ", P[pcurr].info);
                        visited[pcurr] = true;
                    }
                    pcurr = P[pcurr].ps_nb;
                } else {
                    arah = keatas;
                    if (!visited[pcurr]) {
                        printf("%c ", P[pcurr].info);
                        visited[pcurr] = true;
                    }
                    pcurr = P[pcurr].ps_pr;
                }
                break;
            case kekanan:
                if (P[pcurr].ps_fs != nil && !visited[P[pcurr].ps_fs]) {
                    arah = kebawah;
                    pcurr = P[pcurr].ps_fs;
                } else if ((P[pcurr].ps_fs == nil) && (P[pcurr].ps_nb != nil) && !visited[P[pcurr].ps_nb]) {
                    arah = kekanan;
                    if (!visited[pcurr]) {
                        printf("%c ", P[pcurr].info);
                        visited[pcurr] = true;
                    }
                    pcurr = P[pcurr].ps_nb;
                } else {
                    arah = keatas;
                    if (!visited[pcurr]) {
                        printf("%c ", P[pcurr].info);
                        visited[pcurr] = true;
                    }
                    pcurr = P[pcurr].ps_pr;
                }
                break;
            case keatas:
                if (pcurr == 1) {
                    if (!visited[pcurr]) {
                        printf("%c ", P[pcurr].info);
                        visited[pcurr] = true;
                    }
                    pcurr = nil;
                } else if (P[pcurr].ps_nb != nil && !visited[P[pcurr].ps_nb]) {
                    arah = kekanan;
                    if (!visited[pcurr]) {
                        printf("%c ", P[pcurr].info);
                        visited[pcurr] = true;
                    }
                    pcurr = P[pcurr].ps_nb;
                } else {
                    arah = keatas;
                    if (!visited[pcurr]) {
                        printf("%c ", P[pcurr].info);
                        visited[pcurr] = true;
                    }
                    pcurr = P[pcurr].ps_pr;
                }
                break;
        }
    }
    printf("\n");
}

void Level_order(Isi_Tree X, int Maks_node) {
    if (IsEmpty(X)) return;
    
    Isi_Queue Q;
    init_queue(&Q);
    
    enqueue(&Q, 1);
    
    while (!is_queue_empty(Q)) {
        address pcur = dequeue(&Q);
        printf("%c ", X[pcur].info);
        
        if (X[pcur].ps_fs != nil) {
            address child = X[pcur].ps_fs;
            enqueue(&Q, child);
            
            while (X[child].ps_nb != nil) {
                child = X[child].ps_nb;
                enqueue(&Q, child);
            }
        }
    }
    printf("\n");
}

void PrintTree (Isi_Tree P) {
    if (IsEmpty(P)) return;
    address pcurr = 1;
    
    printf("Seluruh Node pada Non Binary Tree:\n")
	for (pcurr ; pcurr < jml_maks ; pcurr++) {
		if (P[pcurr].info == nil) return;
		
		printf("\n--> Indeks ke-%d\n", pcurr);
		printf("-----------------------------------\n");
		printf("info array ke %d			: %c\n", pcurr, P[pcurr].info);
		printf("first son array ke %d		: %d\n", pcurr, P[pcurr].ps_fs);
		printf("next brother array ke %d	: %d\n", pcurr, P[pcurr].ps_nb);
		printf("parent array ke %d			: %d\n", pcurr, P[pcurr].ps_pr);
		printf("-----------------------------------\n");
	}
}

/***** Search *****/

boolean Search (Isi_Tree P, infotype X) {
    if (IsEmpty(P)) return false;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) return true;
    }
    return false;
}

/***** Fungsi Lain *****/

int nbElmt (Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') count++;
    }
    return count;
}

int nbDaun (Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0' && P[i].ps_fs == nil) count++;
    }
    return count;
}

int Level (Isi_Tree P, infotype X) {
    int idx = -1;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            idx = i;
            break;
        }
    }
    if (idx == -1) return -1; 

    int level = 0;
    while (P[idx].ps_pr != nil) {
        idx = P[idx].ps_pr;
        level++;
    }
    return level;
}

int Depth (Isi_Tree P) {
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

int Max (infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}

void InitVisited(boolean visited[]) {
    for (int i = 0; i <= jml_maks; i++) {
        visited[i] = false;
    }
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