#ifndef KASUS_H
#define KASUS_H
#include "LinkedList.h"
#include "queue.h"

#define MAX_BOOKS 100 

typedef struct QueueNode {
    address book;           
    Queue queue;            
    struct QueueNode *next; 
} QueueNode;

typedef struct LibrarySingle {
    address bookList;       
    QueueNode *queueList;   
} LibrarySingle;

typedef struct LibraryDouble {
    dAddress bookList;    
} LibraryDouble;

typedef struct Book {
    infotype info;        
    int stok;             
    address queueHead;    
} Book;

typedef struct LibraryArray {
    Book bookList[MAX_BOOKS]; 
    int size;                 
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
void cancelLastActivitySingle(LibrarySingle *lib, infotype borrowerName);
void singleLinked(LibrarySingle *lib);

void createLibraryDouble(LibraryDouble *lib);
void deAlokasiLibraryDouble(LibraryDouble *lib);
void insertBookDouble(LibraryDouble *lib, infotype title, int stok);
dAddress findBookDouble(LibraryDouble *lib, infotype title);
void requestBookDouble(LibraryDouble *lib, infotype bookTitle, infotype borrowerName, int level);
void processBorrowingDouble(LibraryDouble *lib, infotype bookTitle);
void returnBookDouble(LibraryDouble *lib, infotype bookTitle, infotype borrowerName);
void printHistoryDouble(infotype borrowerName);
void cancelLastActivityDouble(LibraryDouble *lib, infotype borrowerName);
void doubleLinked(LibraryDouble *lib);

void createLibraryArray(LibraryArray *lib);
void deAlokasiLibraryArray(LibraryArray *lib);
void insertBookArray(LibraryArray *lib, infotype title, int stok);
Book* findBookArray(LibraryArray *lib, infotype title);
void requestBookArray(LibraryArray *lib, infotype bookTitle, infotype borrowerName, int level);
void processBorrowingArray(LibraryArray *lib, infotype bookTitle);
void returnBookArray(LibraryArray *lib, infotype bookTitle, infotype borrowerName);
void printHistoryArray(infotype borrowerName);
void cancelLastActivityArray(LibraryArray *lib, infotype borrowerName);
void array(LibraryArray *lib);

#endif