#include "kasus.h"

// Single Linked List Implementation
void createLibrarySingle(LibrarySingle *lib) {
    createList(&lib->bookList);
    lib->queueList = Nil;
}

void insertBookSingle(LibrarySingle *lib, infotype title, int stok) {
    address newBook = createNode(title);
    newBook->stok = stok;
    insertAtLast(&lib->bookList, newBook);

    QueueNode *newQueueNode = (QueueNode*)malloc(sizeof(QueueNode));
    newQueueNode->book = newBook;
    createQueue(&newQueueNode->queue);
    newQueueNode->next = lib->queueList;
    lib->queueList = newQueueNode;
}

address findBookSingle(LibrarySingle *lib, infotype title) {
    return searchNode(lib->bookList, title);
}

QueueNode* findQueueNodeSingle(LibrarySingle *lib, address book) {
    QueueNode *qNode = lib->queueList;
    while (qNode != NULL) {
        if (qNode->book == book) {
            return qNode;
        }
        qNode = qNode->next;
    }
    return NULL;
}

void requestBookSingle(LibrarySingle *lib, infotype bookTitle, infotype borrowerName, int level) {
    address book = findBookSingle(lib, bookTitle);
    if (book == Nil) {
        printf("Buku %s tidak ditemukan.\n", bookTitle);
        return;
    }

    QueueNode *qNode = findQueueNodeSingle(lib, book);
    if (qNode == NULL) {
        printf("Antrian untuk buku %s tidak di temukan.\n", bookTitle);
        return;
    }

    Queue *Q = &qNode->queue;
    // Create new activity stack for the borrower
    Stack *activityStack = (Stack*)malloc(sizeof(Stack));
    if (activityStack == NULL) return;
    createStack(activityStack);
    enqueue(Q, borrowerName, level, book, 1);

    char activity[100];
    sprintf(activity, "Meminjam buku %s", book->info);
    push(activityStack, activity);

    // Add to global history
    addToHistory(&globalHistory, borrowerName, level, activityStack);

    printf("%s telah masuk antrian untuk %s.\n", borrowerName, bookTitle);
}

void processBorrowingSingle(LibrarySingle *lib, infotype bookTitle) {
    address book = findBookSingle(lib, bookTitle);
    if (book == Nil) {
        printf("Buku %s tidak ditemukan.\n", bookTitle);
        return;
    }

    QueueNode *qNode = findQueueNodeSingle(lib, book);
    if (qNode == NULL) {
        printf("Antrian untuk buku %s tidak di temukan.\n", bookTitle);
        return;
    }

    Queue *Q = &qNode->queue;
    if (Q->head == Nil) {
        printf("Tidak ada peminjam untuk %s.\n", bookTitle);
        return;
    }

    int borrowerCount = 0;
    address current = Q->head;
    while (current != Nil && next(current) != book) {
        borrowerCount++;
        current = next(current);
    }

    if (book->stok >= borrowerCount) {
        while (Q->head != Nil && next(Q->head) != book) {
            infotype borrower;
            char activity[100];
            sprintf(activity, "Meminjam buku %s", bookTitle);
            HistoryNode *historyNode = findHistory(&globalHistory, Q->head->info);
            if (historyNode != NULL) {
                push(historyNode->activityStack, activity);
            }

            dequeueSingle(Q, &borrower, book);
            printf("%s telah meminjam %s.\n", borrower, bookTitle);
            free(borrower); 
            book->stok--;
        }
    } else if (book->stok > 0) {
        for (int i = 0; i < book->stok && Q->head != Nil && next(Q->head) != book; i++) {
            infotype borrower;
            char activity[100];
            sprintf(activity, "Meminjam buku %s", bookTitle);
            HistoryNode *historyNode = findHistory(&globalHistory, Q->head->info);
            if (historyNode != NULL) {
                push(historyNode->activityStack, activity);
            }

            dequeueSingle(Q, &borrower, book);
            printf("%s telah meminjam %s.\n", borrower, bookTitle);
            free(borrower); 
            book->stok--;
        }
        if (Q->head != Nil && next(Q->head) != book) {
            printf("Peminjam yang tersisa harus menunggu %s karena (stok habis).\n", bookTitle);
        }
    } else {
        printf("Tidak ada stok tersedia untuk %s.\n", bookTitle);
    }
}

void returnBookSingle(LibrarySingle *lib, infotype bookTitle, infotype borrowerName) {
    address book = findBookSingle(lib, bookTitle);
    if (book == Nil) {
        printf("Buku %s tidak ditemukan.\n", bookTitle);
        return;
    }

    QueueNode *qNode = findQueueNodeSingle(lib, book);
    if (qNode == NULL) {
        printf("Antrian untuk buku %s tidak di temukan.\n", bookTitle);
        return;
    }

    book->stok++;
    printf("%s mengembalikan %s. Stock: %d\n", borrowerName, bookTitle, book->stok);

    // Add return activity to global history
    HistoryNode *historyNode = findHistory(&globalHistory, borrowerName);
    if (historyNode != NULL) {
        char activity[100];
        sprintf(activity, "Mengembalikan buku %s", bookTitle);
        push(historyNode->activityStack, activity);
    }
}

void deAlokasiLibrarySingle(LibrarySingle *lib) {
    // Deallocate book list
    address currentBook = lib->bookList;
    while (currentBook != Nil) {
        address tempBook = currentBook;
        currentBook = next(currentBook);
        free(info(tempBook));
        free(tempBook);
    }
    lib->bookList = Nil;

    // Deallocate queue list
    QueueNode *currentQueue = lib->queueList;
    while (currentQueue != NULL) {
        QueueNode *tempQueue = currentQueue;
        currentQueue = currentQueue->next;
        // Deallocate queue nodes
        address currentNode = tempQueue->queue.head;
        while (currentNode != Nil && currentNode != tempQueue->book) {
            address tempNode = currentNode;
            currentNode = next(currentNode);
            free(tempNode->info);
            free(tempNode);
        }
        free(tempQueue);
    }
    lib->queueList = NULL;
}

void printHistorySingle(infotype borrowerName) {
    HistoryNode *historyNode = findHistory(&globalHistory, borrowerName);
    if (historyNode != NULL) {
        const char *levelStr;
        switch (historyNode->level) {
            case 1: levelStr = "Umum"; break;
            case 2: levelStr = "Mahasiswa"; break;
            case 3: levelStr = "Dosen"; break;
            default: levelStr = "Tidak Diketahui"; break;
        }
        printf("History pendatang %s (level: %s):\n", borrowerName, levelStr);
        printStack(historyNode->activityStack);
    } else {
        printf("Tidak ada riwayat aktivitas yang ditemukan untuk %s.\n", borrowerName);
    }
}

void singleLinked(LibrarySingle *lib) {
    int choice;
    char bookTitle[50], borrowerName[50];
    do {
        printf("============SINGLE LINKED============\n");
        printf("1. Tambah Buku\n");
        printf("2. Buat Antrian\n");
        printf("3. Proses Peminjaman\n");
        printf("4. Proses Pengembalian\n");
        printf("5. Tampilkan Riwayat Kegiatan\n");
        printf("6. Kembali ke menu utama\n");
        printf("Tentukan pilihan anda: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                int stok;
                printf("Masukkan judul buku: ");
                scanf("%[^\n]", bookTitle);
                getchar();
                printf("Masukkan stok buku: ");
                scanf("%d", &stok);
                getchar();
                insertBookSingle(lib, bookTitle, stok);
                printf("Book %s with stock %d added.\n", bookTitle, stok);
                break;
            }
            case 2: {
                int level;
                printf("Masukkan judul buku: ");
                scanf("%[^\n]", bookTitle);
                getchar();
                printf("Masukkan nama peminjam: ");
                scanf("%[^\n]", borrowerName);
                getchar();
                printf("Masukkan level prioritas (1=Umum, 2=Mahasiswa, 3=Dosen): ");
                scanf("%d", &level);
                getchar();
                requestBookSingle(lib, bookTitle, borrowerName, level);
                break;
            }
            case 3: {
                printf("Masukkan judul buku: ");
                scanf("%[^\n]", bookTitle);
                getchar();
                processBorrowingSingle(lib, bookTitle);
                break;
            }
            case 4: {
                printf("Masukkan judul buku: ");
                scanf("%[^\n]", bookTitle);
                getchar();
                printf("Masukkan nama peminjam: ");
                scanf("%[^\n]", borrowerName);
                getchar();
                returnBookSingle(lib, bookTitle, borrowerName);
                break;
            }
            case 5: {
                printf("Masukkan nama peminjam: ");
                scanf("%[^\n]", borrowerName);
                getchar();
                printHistorySingle(borrowerName);
                break;
            }
            case 6:
                printf("Kembali ke menu utama.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 6);
}

// Double Linked List Implementation
void createLibraryDouble(LibraryDouble *lib) {
    createDList(&lib->bookList);
}

void deAlokasiLibraryDouble(LibraryDouble *lib) {
    deAlokasiDList(&lib->bookList);
}

void insertBookDouble(LibraryDouble *lib, infotype title, int stok) {
    dAddress newBook = createDNode(title);
    newBook->stok = stok;
    newBook->queueHead = Nil;
    insertAtLastDList(&lib->bookList, newBook);
}

dAddress findBookDouble(LibraryDouble *lib, infotype title) {
    return searchDNode(lib->bookList, title);
}

void requestBookDouble(LibraryDouble *lib, infotype bookTitle, infotype borrowerName, int level) {
    dAddress book = findBookDouble(lib, bookTitle);
    if (book == Nil) {
        printf("Buku %s tidak ditemukan.\n", bookTitle);
        return;
    }

    Queue Q;
    createQueue(&Q);
    Q.head = book->queueHead;
    Q.tail = book->queueHead;
    while (Q.tail != Nil && next(Q.tail) != Nil) {
        Q.tail = next(Q.tail);
    }

    enqueue(&Q, borrowerName, level, Nil, 0);

    address borrower = Q.tail;
    char activity[100];
    sprintf(activity, "Meminjam buku %s", book->info);
    push(borrower->activityStack, activity);

    book->queueHead = Q.head;

    // Add to global history
    addToHistory(&globalHistory, borrowerName, level, borrower->activityStack);

    printf("%s telah masuk antrian untuk %s.\n", borrowerName, bookTitle);
}

void processBorrowingDouble(LibraryDouble *lib, infotype bookTitle) {
    dAddress book = findBookDouble(lib, bookTitle);
    if (book == Nil) {
        printf("Buku %s tidak ditemukan.\n", bookTitle);
        return;
    }

    Queue Q;
    createQueue(&Q);
    Q.head = book->queueHead;
    Q.tail = book->queueHead;
    while (Q.tail != Nil && next(Q.tail) != Nil) {
        Q.tail = next(Q.tail);
    }

    if (Q.head == Nil) {
        printf("Tidak ada peminjam untuk %s.\n", bookTitle);
        return;
    }

    int borrowerCount = 0;
    address current = Q.head;
    while (current != Nil) {
        borrowerCount++;
        current = next(current);
    }

    if (book->stok >= borrowerCount) {
        while (Q.head != Nil) {
            address borrowerNode = Q.head;
            infotype borrower;
            char activity[100];
            sprintf(activity, "Meminjam buku %s", bookTitle);
            push(borrowerNode->activityStack, activity);

            dequeue(&Q, &borrower);
            printf("%s telah meminjam %s.\n", borrower, bookTitle);
            free(borrower); 
            book->stok--;
        }
        book->queueHead = Q.head;
    } else if (book->stok > 0) {
        for (int i = 0; i < book->stok && Q.head != Nil; i++) {
            address borrowerNode = Q.head;
            infotype borrower;
            char activity[100];
            sprintf(activity, "Meminjam buku %s", bookTitle);
            push(borrowerNode->activityStack, activity);

            dequeue(&Q, &borrower);
            printf("%s telah meminjam %s.\n", borrower, bookTitle);
            free(borrower); 
            book->stok--;
        }
        book->queueHead = Q.head;
        if (Q.head != Nil) {
            printf("Peminjam yang tersisa harus menunggu %s karena (stok habis).\n", bookTitle);
        }
    } else {
        printf("Tidak ada stok tersedia untuk %s.\n", bookTitle);
    }
}

void returnBookDouble(LibraryDouble *lib, infotype bookTitle, infotype borrowerName) {
    dAddress book = findBookDouble(lib, bookTitle);
    if (book == Nil) {
        printf("Buku %s tidak ditemukan.\n", bookTitle);
        return;
    }

    Queue Q;
    createQueue(&Q);
    Q.head = book->queueHead;
    Q.tail = book->queueHead;
    while (Q.tail != Nil && next(Q.tail) != Nil) {
        Q.tail = next(Q.tail);
    }

    book->stok++;
    printf("%s mengembalikan %s. Stock: %d\n", borrowerName, bookTitle, book->stok);

    // Add return activity to global history
    HistoryNode *historyNode = findHistory(&globalHistory, borrowerName);
    if (historyNode != NULL) {
        char activity[100];
        sprintf(activity, "Mengembalikan buku %s", bookTitle);
        push(historyNode->activityStack, activity);
        
        if (Q.head != Nil) {
            historyNode->level = Q.head->level;
        }
    }

    book->queueHead = Q.head;
}

void printHistoryDouble(infotype borrowerName) {
    HistoryNode *historyNode = findHistory(&globalHistory, borrowerName);
    if (historyNode != NULL) {
        const char *levelStr;
        switch (historyNode->level) {
            case 1: levelStr = "Umum"; break;
            case 2: levelStr = "Mahasiswa"; break;
            case 3: levelStr = "Dosen"; break;
            default: levelStr = "Tidak Diketahui"; break;
        }
        printf("History pendatang %s (level: %s):\n", borrowerName, levelStr);
        printStack(historyNode->activityStack);
    } else {
        printf("Tidak ada riwayat aktivitas yang ditemukan untuk %s.\n", borrowerName);
    }
}

void doubleLinked(LibraryDouble *lib) {
    int choice;
    char bookTitle[50], borrowerName[50];
    do {
        printf("============DOUBLE LINKED============\n");
        printf("1. Tambah Buku\n");
        printf("2. Buat Antrian\n");
        printf("3. Proses Peminjaman\n");
        printf("4. Proses Pengembalian\n");
        printf("5. Tampilkan Riwayat Kegiatan\n");
        printf("6. Kembali ke menu utama\n");
        printf("Tentukan pilihan anda: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                int stok;
                printf("Masukkan judul buku: ");
                scanf("%[^\n]", bookTitle);
                getchar();
                printf("Masukkan stok buku: ");
                scanf("%d", &stok);
                getchar();
                insertBookDouble(lib, bookTitle, stok);
                printf("Book %s with stock %d added.\n", bookTitle, stok);
                break;
            }
            case 2: {
                int level;
                printf("Masukkan judul buku: ");
                scanf("%[^\n]", bookTitle);
                getchar();
                printf("Masukkan nama peminjam: ");
                scanf("%[^\n]", borrowerName);
                getchar();
                printf("Masukkan level prioritas (1=Umum, 2=Mahasiswa, 3=Dosen): ");
                scanf("%d", &level);
                getchar();
                requestBookDouble(lib, bookTitle, borrowerName, level);
                break;
            }
            case 3: {
                printf("Masukkan judul buku: ");
                scanf("%[^\n]", bookTitle);
                getchar();
                processBorrowingDouble(lib, bookTitle);
                break;
            }
            case 4: {
                printf("Masukkan judul buku: ");
                scanf("%[^\n]", bookTitle);
                getchar();
                printf("Masukkan nama peminjam: ");
                scanf("%[^\n]", borrowerName);
                getchar();
                returnBookDouble(lib, bookTitle, borrowerName);
                break;
            }
            case 5: {
                printf("Masukkan nama peminjam: ");
                scanf("%[^\n]", borrowerName);
                getchar();
                printHistoryDouble(borrowerName);
                break;
            }
            case 6:
                printf("Kembali ke menu utama.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 6);
}

// Array Static Implementation
void createLibraryArray(LibraryArray *lib) {
    for (int i = 0; i < MAX_BOOKS; i++) {
        lib->bookList[i].info = NULL;
        lib->bookList[i].stok = 0;
        lib->bookList[i].queueHead = Nil;
    }
    lib->size = 0;
}

void deAlokasiLibraryArray(LibraryArray *lib) {
    for (int i = 0; i < lib->size; i++) {
        // Deallocate the info string
        if (lib->bookList[i].info != NULL) {
            free(lib->bookList[i].info);
            lib->bookList[i].info = NULL;
        }
        // Deallocate the borrower queue
        DeAlokasi(&lib->bookList[i].queueHead);
        lib->bookList[i].stok = 0;
    }
    lib->size = 0;
}

void insertBookArray(LibraryArray *lib, infotype title, int stok) {
    if (lib->size >= MAX_BOOKS) {
        printf("Perpustakaan sudah penuh, tidak bisa menambah buku lagi.\n");
        return;
    }

    // Allocate memory for the title string
    lib->bookList[lib->size].info = (char*)malloc(strlen(title) + 1);
    strcpy(lib->bookList[lib->size].info, title);
    lib->bookList[lib->size].stok = stok;
    lib->bookList[lib->size].queueHead = Nil;
    lib->size++;
}

Book* findBookArray(LibraryArray *lib, infotype title) {
    for (int i = 0; i < lib->size; i++) {
        if (lib->bookList[i].info != NULL && strcmp(lib->bookList[i].info, title) == 0) {
            return &lib->bookList[i];
        }
    }
    return NULL;
}

void requestBookArray(LibraryArray *lib, infotype bookTitle, infotype borrowerName, int level) {
    Book *book = findBookArray(lib, bookTitle);
    if (book == NULL) {
        printf("Buku %s tidak ditemukan.\n", bookTitle);
        return;
    }

    Queue Q;
    createQueue(&Q);
    Q.head = book->queueHead;
    Q.tail = book->queueHead;
    while (Q.tail != Nil && next(Q.tail) != Nil) {
        Q.tail = next(Q.tail);
    }

    enqueue(&Q, borrowerName, level, Nil, 0);

    address borrower = Q.tail;
    char activity[100];
    sprintf(activity, "Meminjam buku %s", book->info);
    push(borrower->activityStack, activity);

    book->queueHead = Q.head;

    // Add to global history
    addToHistory(&globalHistory, borrowerName, level, borrower->activityStack);

    printf("%s telah masuk antrian untuk %s.\n", borrowerName, bookTitle);
}

void processBorrowingArray(LibraryArray *lib, infotype bookTitle) {
    Book *book = findBookArray(lib, bookTitle);
    if (book == NULL) {
        printf("Buku %s tidak ditemukan.\n", bookTitle);
        return;
    }

    Queue Q;
    createQueue(&Q);
    Q.head = book->queueHead;
    Q.tail = book->queueHead;
    while (Q.tail != Nil && next(Q.tail) != Nil) {
        Q.tail = next(Q.tail);
    }

    if (Q.head == Nil) {
        printf("Tidak ada peminjam untuk %s.\n", bookTitle);
        return;
    }

    int borrowerCount = 0;
    address current = Q.head;
    while (current != Nil) {
        borrowerCount++;
        current = next(current);
    }

    if (book->stok >= borrowerCount) {
        while (Q.head != Nil) {
            address borrowerNode = Q.head;
            infotype borrower;
            char activity[100];
            sprintf(activity, "Meminjam %s", bookTitle);
            push(borrowerNode->activityStack, activity);

            dequeue(&Q, &borrower);
            printf("%s telah meminjam %s.\n", borrower, bookTitle);
            free(borrower); 
            book->stok--;
        }
        book->queueHead = Q.head;
    } else if (book->stok > 0) {
        for (int i = 0; i < book->stok && Q.head != Nil; i++) {
            address borrowerNode = Q.head;
            infotype borrower;
            char activity[100];
            sprintf(activity, "Meminjam %s", bookTitle);
            push(borrowerNode->activityStack, activity);

            dequeue(&Q, &borrower);
            printf("%s telah meminjam %s.\n", borrower, bookTitle);
            free(borrower); 
            book->stok--;
        }
        book->queueHead = Q.head;
        if (Q.head != Nil) {
            printf("Peminjam yang tersisa harus menunggu %s karena (stok habis).\n", bookTitle);
        }
    } else {
        printf("Tidak ada stok tersedia untuk %s.\n", bookTitle);
    }
}

void returnBookArray(LibraryArray *lib, infotype bookTitle, infotype borrowerName) {
    Book *book = findBookArray(lib, bookTitle);
    if (book == NULL) {
        printf("Buku %s tidak ditemukan.\n", bookTitle);
        return;
    }

    Queue Q;
    createQueue(&Q);
    Q.head = book->queueHead;
    Q.tail = book->queueHead;
    while (Q.tail != Nil && next(Q.tail) != Nil) {
        Q.tail = next(Q.tail);
    }

    book->stok++;
    printf("%s mengembalikan %s. Stock: %d\n", borrowerName, bookTitle, book->stok);

    // Add return activity to global history
    HistoryNode *historyNode = findHistory(&globalHistory, borrowerName);
    if (historyNode != NULL) {
        char activity[100];
        sprintf(activity, "Mengembalikan buku %s", bookTitle);
        push(historyNode->activityStack, activity);
        
        if (Q.head != Nil) {
            historyNode->level = Q.head->level;
        }
    }

    book->queueHead = Q.head;
}

void printHistoryArray(infotype borrowerName) {
    HistoryNode *historyNode = findHistory(&globalHistory, borrowerName);
    if (historyNode != NULL) {
        const char *levelStr;
        switch (historyNode->level) {
            case 1: levelStr = "Umum"; break;
            case 2: levelStr = "Mahasiswa"; break;
            case 3: levelStr = "Dosen"; break;
            default: levelStr = "Tidak Diketahui"; break;
        }
        printf("History pendatang %s (level: %s):\n", borrowerName, levelStr);
        printStack(historyNode->activityStack);
    } else {
        printf("Tidak ada riwayat aktivitas yang ditemukan untuk %s.\n", borrowerName);
    }
}

void array(LibraryArray *lib) {
    int choice;
    char bookTitle[50], borrowerName[50];
    do {
        printf("============ARRAY STATIC============\n");
        printf("1. Tambah Buku\n");
        printf("2. Buat Antrian\n");
        printf("3. Proses Peminjaman\n");
        printf("4. Proses Pengembalian\n");
        printf("5. Tampilkan Riwayat Kegiatan\n");
        printf("6. Kembali ke menu utama\n");
        printf("Tentukan pilihan anda: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                int stok;
                printf("Masukkan judul buku: ");
                scanf("%[^\n]", bookTitle);
                getchar();
                printf("Masukkan stok buku: ");
                scanf("%d", &stok);
                getchar();
                insertBookArray(lib, bookTitle, stok);
                printf("Book %s with stock %d added.\n", bookTitle, stok);
                break;
            }
            case 2: {
                int level;
                printf("Masukkan judul buku: ");
                scanf("%[^\n]", bookTitle);
                getchar();
                printf("Masukkan nama peminjam: ");
                scanf("%[^\n]", borrowerName);
                getchar();
                printf("Masukkan level prioritas (1=Umum, 2=Mahasiswa, 3=Dosen): ");
                scanf("%d", &level);
                getchar();
                requestBookArray(lib, bookTitle, borrowerName, level);
                break;
            }
            case 3: {
                printf("Masukkan judul buku: ");
                scanf("%[^\n]", bookTitle);
                getchar();
                processBorrowingArray(lib, bookTitle);
                break;
            }
            case 4: {
                printf("Masukkan judul buku: ");
                scanf("%[^\n]", bookTitle);
                getchar();
                printf("Masukkan nama peminjam: ");
                scanf("%[^\n]", borrowerName);
                getchar();
                returnBookArray(lib, bookTitle, borrowerName);
                break;
            }
            case 5: {
                printf("Masukkan nama peminjam: ");
                scanf("%[^\n]", borrowerName);
                getchar();
                printHistoryArray(borrowerName);
                break;
            }
            case 6:
                printf("Kembali ke menu utama.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 6);
}