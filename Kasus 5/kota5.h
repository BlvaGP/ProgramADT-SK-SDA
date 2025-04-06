#ifndef KOTA5_H
#define KOTA5_H
#include "LinkedList.h"

typedef struct Kota {
    char namaKota[50];
    address listWarga;
} kota;

void entryNamaKota(kota * K);
void entryNamaWarga(char * namaWarga);
void createWarga(kota * K, char * namaWarga);
void deleteSeluruhKota(kota * K, int size);
void deleteKota(kota * K, int size, char * namaKota);
void deleteSeluruhWarga(kota * K);
void deleteWargaByName(kota * K, char * namaWarga);
void tampilkanSeluruhData(kota * K, int size);
void tampilkanDataSuatuKota(kota * K);
void tampilkanDataWargaByName(kota * K, char * namaWarga);

#endif