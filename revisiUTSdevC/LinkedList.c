#include "LinkedList.h"

// Kreator
void createList(address *L) {
    *L = Nil;
}

// Manajemen memori
address createNode(infotype info) {
    address p = (address)malloc(sizeof(struct Node));
    if (p != Nil) {
        info(p) = strdup(info);
        p->stok = 0;
        p->level = 0;
        next(p) = Nil;
        p->activityStack = NULL;
    }
    return p;
}

void DeAlokasi(address *L) {
    address temp;
    while (*L != Nil) {
        temp = *L;
        *L = next(*L);
        if (temp->activityStack != NULL) {
            deallocateStack(temp->activityStack); // Deallocate stack entries
            free(temp->activityStack);            // Free the Stack structure
        }
        free(info(temp)); // Free the info string
        free(temp);       // Free the Node
    }
    *L = Nil;
}

// Insert
void insertAtFirst(address *L, address newP) {
    if (newP != Nil) {
        next(newP) = *L;
        *L = newP;
    }
}

void insertAtLast(address *L, address newP) {
    if (newP == Nil) return;
    next(newP) = Nil;

    if (*L == Nil) {
        *L = newP;
    } else {
        address last = *L;
        while (next(last) != Nil) {
            last = next(last);
        }
        next(last) = newP;
        next(newP) = Nil;
    }
}

void insertBeforeBetween(address *L, address newP) {
    if (*L == Nil || newP == Nil) return;

    int n = countNode(*L);
    if (n < 2) return; // Tidak ada cukup node untuk menyisipkan

    int mid = n / 2; // Posisi tengah
    address temp = *L;
    address prev = Nil;

    for (int i = 0; i < mid; i++) {
        prev = temp;
        temp = next(temp);
    }

    next(newP) = temp; // Menyisipkan sebelum node tengah
    if (prev != Nil) {
        next(prev) = newP;
    } else {
        *L = newP; // Jika menyisipkan di depan
    }
}

void insertAfterBetween(address *L, address newP) {
    if (*L == Nil || newP == Nil) return;

    int n = countNode(*L);

    int mid = n / 2; // Posisi tengah
    address temp = *L;

    for (int i = 0; i < mid; i++) {
        temp = next(temp);
    }

    next(newP) = next(temp); // Menyisipkan setelah node tengah
    next(temp) = newP;
}

void insertBeforeValue(address *L, infotype targetInfo, infotype newInfo) {
    if (*L == Nil) return;

    if (strcmp(info(*L), targetInfo) == 0) { // Jika target adalah node pertama
        address newP = createNode(newInfo);
        insertAtFirst(L, newP);
        return;
    }

    address prev = *L, temp = next(*L);
    while (temp != Nil && strcmp(info(temp), targetInfo) != 0) { // Cari node sebelum target
        prev = temp;
        temp = next(temp);
    }
    if (temp != Nil) { // Jika ditemukan
        address newP = createNode(newInfo);
        next(newP) = next(prev);
        next(prev) = newP;
    }
}

void insertAfterValue(address L, infotype targetInfo, infotype newInfo) {
    address temp = L;
    while (temp != Nil && strcmp(info(temp), targetInfo) != 0) { // Cari node dengan nilai target
        temp = next(temp);
    }
    if (temp != Nil) { // Jika ditemukan
        address newP = createNode(newInfo);
        next(newP) = next(temp);
        next(temp) = newP;
    }
}

void insertSortedByPriority(address *L, address newP) {
    if (newP == Nil) return;

    // If list is empty or newP has higher priority than the first node
    if (*L == Nil || newP->level > (*L)->level) {
        newP->next = *L;
        *L = newP;
        return;
    }

    // Find the correct position to insert based on priority
    address current = *L;
    address prev = Nil;
    while (current != Nil && current->level >= newP->level) {
        prev = current;
        current = current->next;
    }

    // Insert the new node
    newP->next = current;
    if (prev != Nil) {
        prev->next = newP;
    } else {
        *L = newP;
    }
}

// Delete
void deleteFirst(address *L, infotype *info) {
    if (*L == Nil) return;

    address temp = *L;
    *info = info(temp);
    *L = next(*L);
    if (temp->activityStack != NULL) {
        free(temp->activityStack);
    }
    free(temp);
}

void deleteLast(address *L, infotype *info) {
    if (*L == Nil) {
        *info = NULL;
        return;
    }

    if (next(*L) == Nil) {
        address temp = *L;
        *info = temp->info;
        *L = Nil;
        if (temp->activityStack != NULL) {
            free(temp->activityStack);
        }
        free(temp);
        return;
    }

    address prev = Nil, temp = *L;
    while (next(temp) != Nil) {
        prev = temp;
        temp = next(temp);
    }
    next(prev) = Nil;
    *info = temp->info;
    if (temp->activityStack != NULL) {
        free(temp->activityStack);
    }
    free(temp);
}

void deleteBeforeBetween(address *L) {
    int n = countNode(*L);
    if (n < 2) return;

    int mid = n / 2;
    if (n % 2 == 0) mid--;

    address prev = Nil, temp = *L;
    for (int i = 0; i < mid; i++) {
        prev = temp;
        temp = next(temp);
    }

    if (prev == Nil) {
        deleteFirst(L, &info(*L));
    } else {
        next(prev) = next(temp);
        if (temp->activityStack != NULL) {
            free(temp->activityStack);
        }
        free(temp);
    }
}

void deleteAfterBetween(address *L) {
    int n = countNode(*L);
    if (n < 2) return;

    int mid = n / 2;

    address prev = Nil, temp = *L;
    for (int i = 0; i < mid; i++) {
        prev = temp;
        temp = next(temp);
    }

    if (prev == Nil) {
        deleteFirst(L, &info(*L));
    } else {
        next(prev) = next(temp);
        if (temp->activityStack != NULL) {
            free(temp->activityStack);
        }
        free(temp);
    }
}

void deleteValue(address *L, infotype info) {
    if (*L == Nil) return;

    if (strcmp(info(*L), info) == 0) {
        deleteFirst(L, &info);
        return;
    }

    address prev = *L, temp = next(*L);
    while (temp != Nil && strcmp(info(temp), info) != 0) {
        prev = temp;
        temp = next(temp);
    }

    if (temp != Nil) {
        next(prev) = next(temp);
        if (temp->activityStack != NULL) {
            free(temp->activityStack);
        }
        free(info(temp));
        free(temp);
    }
}

// Modify
void modifyAtFirst(address *L, int newInfo) {
    if (*L == Nil) return;
    free(info(*L));
    char buffer[20];
    sprintf(buffer, "%d", newInfo);
    info(*L) = strdup(buffer);
}

void modifyAtLast(address *L, int newInfo) {
    if (*L == Nil) return;

    address temp = *L;
    while (next(temp) != Nil) {
        temp = next(temp);
    }
    free(info(temp));
    char buffer[20];
    sprintf(buffer, "%d", newInfo);
    info(temp) = strdup(buffer);
}

void modifyBeforeBetween(address *L, int newInfo) {
    int n = countNode(*L);
    if (n < 2) return;

    int mid = (n - 1) / 2;  // Ambil indeks sebelum tengah

    address temp = *L;
    for (int i = 0; i < mid; i++) {
        temp = next(temp);
    }
    free(info(temp));
    char buffer[20];
    sprintf(buffer, "%d", newInfo);
    info(temp) = strdup(buffer);
}

void modifyAfterBetween(address *L, int newInfo) {
    int n = countNode(*L);
    if (n < 2) return;

    int mid = n / 2;  // Ambil indeks tengah pertama

    address temp = *L;
    for (int i = 0; i < mid; i++) {
        temp = next(temp);
    }
    free(info(temp));
    char buffer[20];
    sprintf(buffer, "%d", newInfo);
    info(temp) = strdup(buffer);
}

void modifyValue(address *L, int targetInfo, int newInfo) {
    if (*L == Nil) return;

    address temp = *L;
    char targetStr[20];
    sprintf(targetStr, "%d", targetInfo);
    while (temp != Nil && strcmp(info(temp), targetStr) != 0) {
        temp = next(temp);
    }

    if (temp != Nil) { // Jika ditemukan
        free(info(temp));
        char buffer[20];
        sprintf(buffer, "%d", newInfo);
        info(temp) = strdup(buffer);
    }
}

// Search
address searchNode(address L, infotype info) {
    address temp = L;
    while (temp != Nil) {
        if (strcmp(info(temp), info) == 0) {
            return temp; // Node ditemukan
        }
        temp = next(temp);
    }
    return Nil; // Node tidak ditemukan
}

boolean FSearch(address L, address P) {
    address temp = L;
    while (temp != Nil) {
        if (temp == P) {
            return true; // Node ditemukan
        }
        temp = next(temp);
    }
    return false; // Node tidak ditemukan
}

address searchPrec(address L, infotype info) {
    address temp = L;
    while (temp != Nil && next(temp) != Nil) {
        if (strcmp(info(next(temp)), info) == 0) {
            return temp; // Node ditemukan
        }
        temp = next(temp);
    }
    return Nil; // Node tidak ditemukan
}

// Process
int countNode(address L) {
    int count = 0;
    while (L != Nil) {
        count++;
        L = next(L);
    }
    return count;
}

void printList(address L) {
    address p = L;
    while (p != Nil) {
        printf("%s -> ", info(p));
        p = next(p);
    }
    printf("Nil\n");
}

// For integer (adjusted for strings)
infotype Max(address L) {
    if (L == Nil) return NULL;
    infotype max = info(L);
    address temp = next(L);
    while (temp != Nil) {
        if (strcmp(info(temp), max) > 0) {
            max = info(temp);
        }
        temp = next(temp);
    }
    return max;
}

address addressMax(address L) {
    if (L == Nil) return Nil;
    address maxNode = L;
    infotype max = info(L);
    address temp = next(L);
    while (temp != Nil) {
        if (strcmp(info(temp), max) > 0) {
            max = info(temp);
            maxNode = temp;
        }
        temp = next(temp);
    }
    return maxNode;
}

infotype Min(address L) {
    if (L == Nil) return NULL;
    infotype min = info(L);
    address temp = next(L);
    while (temp != Nil) {
        if (strcmp(info(temp), min) < 0) {
            min = info(temp);
        }
        temp = next(temp);
    }
    return min;
}

address addressMin(address L) {
    if (L == Nil) return Nil;
    address minNode = L;
    infotype min = info(L);
    address temp = next(L);
    while (temp != Nil) {
        if (strcmp(info(temp), min) < 0) {
            min = info(temp);
            minNode = temp;
        }
        temp = next(temp);
    }
    return minNode;
}

infotype Average(address L) {
    if (L == Nil) return NULL;
    int sum = 0, count = 0;
    address temp = L;
    while (temp != Nil) {
        sum += atoi(info(temp)); // Convert string to integer
        count++;
        temp = next(temp);
    }
    if (count == 0) return NULL; // Avoid division by zero
    int avg = sum / count;
    char *result = (char *)malloc(20 * sizeof(char));
    sprintf(result, "%d", avg); // Convert integer to string
    return result;
}

// Double Linked List functions
void createDList(dAddress *L) {
    *L = Nil;
}

dAddress createDNode(infotype info) {
    dAddress p = (dAddress)malloc(sizeof(struct DNode));
    if (p != Nil) {
        p->info = strdup(info);
        p->stok = 0;
        p->next = Nil;
        p->queueHead = Nil;
    }
    return p;
}

void deAlokasiDList(dAddress *L) {
    dAddress temp;
    while (*L != Nil) {
        temp = *L;
        *L = (*L)->next;
        // Deallocate the borrower queue for this book
        DeAlokasi(&temp->queueHead);
        free(temp->info);
        free(temp);
    }
    *L = Nil;
}

void insertAtFirstDList(dAddress *L, dAddress newP) {
    if (newP == Nil) return;

    newP->next = *L;
    *L = newP;
}

void insertAtLastDList(dAddress *L, dAddress newP) {
    if (newP == Nil) return;

    newP->next = Nil;
    if (*L == Nil) {
        *L = newP;
    } else {
        dAddress last = *L;
        while (last->next != Nil) {
            last = last->next;
        }
        last->next = newP;
    }
}

void deleteFirstDList(dAddress *L, infotype *info) {
    if (*L == Nil) return;

    dAddress temp = *L;
    *info = temp->info;
    *L = temp->next;
    // Deallocate the borrower queue for this book
    DeAlokasi(&temp->queueHead);
    free(temp->info);
    free(temp);
}

void deleteLastDList(dAddress *L) {
    if (*L == Nil) return;

    if ((*L)->next == Nil) {
        // Deallocate the borrower queue for this book
        DeAlokasi(&(*L)->queueHead);
        free((*L)->info);
        free(*L);
        *L = Nil;
        return;
    }

    dAddress last = *L;
    dAddress prev = Nil;
    while (last->next != Nil) {
        prev = last;
        last = last->next;
    }
    prev->next = Nil;
    // Deallocate the borrower queue for this book
    DeAlokasi(&last->queueHead);
    free(last->info);
    free(last);
}

void deleteValueDList(dAddress *L, infotype info) {
    if (*L == Nil) return;

    if (strcmp((*L)->info, info) == 0) {
        infotype tempInfo;
        deleteFirstDList(L, &tempInfo);
        return;
    }

    dAddress current = *L;
    dAddress prev = Nil;
    while (current != Nil && strcmp(current->info, info) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == Nil) return;

    prev->next = current->next;
    // Deallocate the borrower queue for this book
    DeAlokasi(&current->queueHead);
    free(current->info);
    free(current);
}

dAddress searchDNode(dAddress L, infotype info) {
    dAddress temp = L;
    while (temp != Nil) {
        if (strcmp(temp->info, info) == 0) {
            return temp; // Node ditemukan
        }
        temp = temp->next;
    }
    return Nil; // Node tidak ditemukan
}