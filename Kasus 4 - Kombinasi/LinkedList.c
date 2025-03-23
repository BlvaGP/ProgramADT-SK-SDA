//file LinkedList.c
#include "LinkedList.h"

//construktor item
item createItem(char* nama, char* kategori, int jumlah, float harga, float total, char* aksi) {
    item n;
    n.nama = setNama(nama);
    n.kategori = setKategori(kategori);
    n.jumlah = setJumlah(jumlah);
    n.harga = setHarga(harga);
    n.total = setTotal(total, jumlah, harga);
    n.aksi = setAksi(aksi);
    return n;
}

char* setNama(char *nama) { 
    char *newNama = strdup(nama);  
    if (newNama == NULL) {
        printf("Gagal mengalokasikan memori untuk nama.\n");
        return NULL;
    }
    return newNama;
}

char* setKategori(char *nama) {
    char *newKategori = strdup(nama);  
    if (newKategori == NULL) {
        printf("Gagal mengalokasikan memori untuk kategori.\n");
        return NULL;
    }
    return newKategori;
}

int setJumlah(int jumlah) {
    return jumlah;
}

int setHarga(float harga) {
    return harga;
}

float setTotal(float total, int jumlah, float harga) {
    return total = (float)jumlah * harga;
}

char* setAksi(char *aksi) {
    char *newAksi = strdup(aksi);
    if (newAksi == NULL) {
        printf("Gagal mengalokasikan memori untuk aksi.\n");
        return NULL;
    }
    return newAksi;
}

boolean isEmpty(address p) {
    return (p == Nil);
}

//createNode
address createNode(item info) {
    address p = (address)malloc(sizeof(node));
    if (p != Nil) {
        info(p) = info;
        next(p) = Nil;
    }
    return p;
}

//insert
void insertAtFirst(address *L, address newP) {
    if (newP != Nil){
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
        while (next(last) != Nil)
        {
            last = next(last);
        }
        next(last) = newP;
    }
}

//delete
void deleteFirst(address *L, item *info) { 
    if (*L == Nil) return;

    address temp = *L;
    *info = info(temp);  // Simpan nilai sebelum dihapus
    *L = next(*L);
    free(temp);
}

void deleteValue(address *L, item info) { //menghapus node yang dipilih berdasarkan value
    if (*L == Nil) return;

    if (strcmp(info(*L).nama, info.nama) == 0) {
        deleteFirst(L, &info);
        return;
    }

    address prev = *L, temp = next(*L);
    while (temp != Nil && strcmp(info(temp).nama, info.nama) != 0) 
    {
        prev = temp;
        temp = next(temp);
    }
    
    if (temp != Nil) {
        next(prev) = next(temp);
        free(temp);
    }
}

int NbElmt (address L) {
    address p = L;
    int count = 0;
    while (p != Nil) {
        count++;
        p = next(p);
    }
    return count;
}

void DeAlokasi (address *L) {
    address temp;
    while (*L != Nil)
    {
        temp = *L;
        *L = next(*L);
        free(info(temp).nama);
        free(info(temp).kategori);
        free(info(temp).aksi);
        free(temp);
    }   
}