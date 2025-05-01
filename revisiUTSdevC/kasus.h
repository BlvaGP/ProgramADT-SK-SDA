#ifndef KASUS_H
#define KASUS_H
#include "LinkedList.h"
#include "queue.h"

#define MAX_BOOKS 100 // Maximum number of books in the static array

typedef struct QueueNode {
    address book;           // Pointer to the book 
    Queue queue;            // The queue for this book
    struct QueueNode *next; // Pointer to the next queue node
} QueueNode;

typedef struct LibrarySingle {
    address bookList;       // Single linked list of books 
    QueueNode *queueList;   // Linked list of queues (one per book)
} LibrarySingle;

typedef struct LibraryDouble {
    dAddress bookList;    // Single linked list of books with queueHead
} LibraryDouble;

// Define Book structure for Array Static case
typedef struct Book {
    infotype info;        // Book title
    int stok;             // Stock of the book
    address queueHead;    // Pointer to the queue of borrowers
} Book;

typedef struct LibraryArray {
    Book bookList[MAX_BOOKS]; // Static array of Book structures (not pointers)
    int size;                 // Current number of books
} LibraryArray;

void createLibrarySingle(LibrarySingle *lib);
void deAlokasiLibrarySingle(LibrarySingle *lib);
void insertBookSingle(LibrarySingle *lib, infotype title, int stok);
address findBookSingle(LibrarySingle *lib, infotype title);
QueueNode* findQueueNodeSingle(LibrarySingle *lib, address book);
void requestBookSingle(LibrarySingle *lib, infotype bookTitle, infotype borrowerName, int level);
void processBorrowingSingle(LibrarySingle *lib, infotype bookTitle);
void returnBookSingle(LibrarySingle *lib, infotype bookTitle, infotype borrowerName);
void printHistorySingle(infotype borrowerName);
void singleLinked(LibrarySingle *lib);

void createLibraryDouble(LibraryDouble *lib);
void deAlokasiLibraryDouble(LibraryDouble *lib);
void insertBookDouble(LibraryDouble *lib, infotype title, int stok);
dAddress findBookDouble(LibraryDouble *lib, infotype title);
void requestBookDouble(LibraryDouble *lib, infotype bookTitle, infotype borrowerName, int level);
void processBorrowingDouble(LibraryDouble *lib, infotype bookTitle);
void returnBookDouble(LibraryDouble *lib, infotype bookTitle, infotype borrowerName);
void printHistoryDouble(infotype borrowerName);
void doubleLinked(LibraryDouble *lib);

void createLibraryArray(LibraryArray *lib);
void deAlokasiLibraryArray(LibraryArray *lib);
void insertBookArray(LibraryArray *lib, infotype title, int stok);
Book* findBookArray(LibraryArray *lib, infotype title);
void requestBookArray(LibraryArray *lib, infotype bookTitle, infotype borrowerName, int level);
void processBorrowingArray(LibraryArray *lib, infotype bookTitle);
void returnBookArray(LibraryArray *lib, infotype bookTitle, infotype borrowerName);
void printHistoryArray(infotype borrowerName);
void array(LibraryArray *lib);

#endif