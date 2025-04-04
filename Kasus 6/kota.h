#ifndef KOTA_H
#define KOTA_H
#include "LinkedList.h"

typedef struct Kota {
    infotype namaKota;
    address listWarga;
    struct Kota *next;
} kota;

typedef kota *addressKota;

void insertKotaAtLast(addressKota *L, addressKota newP);
void DeAlokasiKota (addressKota *L);
void initKota(addressKota * K);
addressKota createKota(addressKota *K, infotype namaKota);
void entryNamaKota(char * namaKota);
void entryNamaWarga(char * namaWarga);
void createWarga(kota * K, char * namaWarga);
addressKota findKota(addressKota K, char namaKota[]);
void deleteSeluruhKota(addressKota * K);
void deleteKota(addressKota * K, char * namaKota);
void deleteSeluruhWarga(kota * K);
void deleteWargaByName(kota * K, char * namaWarga);
void tampilkanSeluruhData(addressKota K);
void tampilkanDataSuatuKota(kota * K);
void tampilkanDataWargaByName(kota * K, char * namaWarga);

#endif