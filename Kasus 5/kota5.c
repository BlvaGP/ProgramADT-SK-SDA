#include "kota5.h"

void entryNamaKota(kota * K) {
    scanf("%s", namaKota(K)); 
}

void entryNamaWarga(char * namaWarga) {
    scanf("%s", namaWarga);
}

void createWarga(kota * K, char * namaWarga) {
    address newNode = createNode(namaWarga);
    insertAtLast(&(listWarga(K)), newNode);
}

void deleteSeluruhKota(kota * K, int size) {
    for (int i = 0 ; i < size ; i++) {
        if (strcmp(K[i].namaKota, "") != 0) {
            deleteSeluruhWarga(&K[i]);
            strcpy(K[i].namaKota, "");
        }
    }
}

void deleteKota(kota * K, int size, char * namaKota) {
    for (int i = 0; i < size; i++) {
        if (strcmp(K[i].namaKota, namaKota) == 0) {
            deleteSeluruhWarga(&K[i]);
            strcpy(K[i].namaKota, "");
            return;
        }
    }
    printf("Kota %s tidak ditemukan\n", namaKota);
}

void deleteSeluruhWarga(kota * K) {
    DeAlokasi(&listWarga(K));
}

void deleteWargaByName(kota * K, char * namaWarga) {
    deleteValue(&listWarga(K), namaWarga);
}

void tampilkanDataSuatuKota(kota * K) {
    address temp = listWarga(K);
    
    printf("Data Warga Kota %s:\n", namaKota(K));
    if (temp == Nil) {
        printf("Tidak ada warga yang terdaftar\n");
        return;
    }
    
    while (temp != Nil) {
        printf("%s Asal[%s]\n", info(temp), namaKota(K));
        temp = next(temp);
    }
}

void tampilkanDataWargaByName(kota * K, char * namaWarga) {
    address temp = listWarga(K);
    boolean found = false;
    
    while (temp != Nil) {
        if (strcmp(info(temp), namaWarga) == 0) {
            printf("%s Asal[%s]\n", info(temp), namaKota(K));
            found = true;
        }
        temp = next(temp);
    }
    
    if (!found) {
        printf("Warga %s tidak ditemukan di kota %s\n", namaWarga, namaKota(K));
    }
}

void tampilkanSeluruhData(kota * K, int size) {
    boolean ada = false;
    
    for (int i = 0; i < size; i++) {
        if (strcmp(K[i].namaKota, "") != 0) {
            tampilkanDataSuatuKota(&K[i]);
            printf("\n");
            ada = true;
        }
    }
    
    if (!ada) {
        printf("Tidak ada data kota yang tersimpan\n");
    }
}