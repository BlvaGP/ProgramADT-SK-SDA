//file LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "convention.h" 

typedef struct Item {
    char *nama;
    char *kategori;
    int jumlah;
    float harga;
    float total;
    char *aksi;
} item;

typedef struct Node {
    item info;
    struct Node *next;
} node;

typedef node* address;

item createItem(char* nama, char* kategori, int jumlah, float harga, float total, char* aksi);
char* setNama(char *nama);
char* setKategori(char *nama);
int setJumlah(int jumlah);      
int setHarga(float harga);  
float setTotal(float total, int jumlah, float harga);
char* setAksi(char *aksi);

boolean isEmpty(address p);
address createNode(item info);
void insertAtFirst(address *L, address newP);
void insertAtLast(address *L, address newP);
void deleteFirst(address *L, item *info);
void deleteValue(address *L, item info);
int NbElmt (address L);
void DeAlokasi (address *L);

#endif