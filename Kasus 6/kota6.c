#include "kota6.h"

void insertKotaAtLast(addressKota *L, addressKota newP) {
    if (newP == Nil) return;
    next(newP) = Nil;
    
    if (*L == Nil) {
        *L = newP;
    } else {
        addressKota last = *L;
        while (next(last) != Nil)
        {
            last = next(last);
        }
        next(last) = newP;
        next(newP) = Nil;
    }
}

void DeAlokasiKota (addressKota *L) {
    addressKota temp;
    while (*L != Nil)
    {
        temp = *L;
        *L = next(*L);
        free(namaKota(temp));
        free(temp);
    }  
    *L = Nil; 
}

void initKota(addressKota * K) {
    *K = Nil;
}

addressKota createKota(addressKota *K, infotype namaKota) {
    addressKota newNode = (addressKota)createNode(namaKota);
    if (newNode != Nil) {
        namaKota(newNode) = strdup(namaKota);
        listWarga(newNode) = Nil;
        next(newNode) = Nil;
        insertKotaAtLast(K, newNode);
        return newNode;
    }
    return Nil;
}

void entryNamaKota(char * namaKota) {
    scanf("%s", namaKota); 
}

void entryNamaWarga(char * namaWarga) {
    scanf("%s", namaWarga);
}

void createWarga(kota * K, char * namaWarga) {
    address newNode = createNode(namaWarga);
    insertAtLast(&(listWarga(K)), newNode);
}

addressKota findKota(addressKota K, char namaKota[]) {
    while (K != Nil) {
        if (strcmp(namaKota(K), namaKota) == 0) {
            return K; 
        }
        K = next(K); 
    }
    return Nil; 
}

void deleteSeluruhKota(addressKota * K) {    
    addressKota temp = *K;

    while (temp != Nil) {
        deleteSeluruhWarga(temp);  
        temp = next(temp);
    }

    DeAlokasiKota(K);
}

void deleteKota(addressKota * K, char * namaKota) {
    addressKota temp = *K, prev = Nil;

    while (temp != Nil && strcmp(namaKota(temp), namaKota) != 0) {
        prev = temp;
        temp = next(temp);
    }

    if (temp != Nil) {
        if (prev == Nil) {
            *K = next(temp);
        } else {
            next(prev) = next(temp);
        }
        deleteSeluruhWarga(temp);
        free(namaKota(temp));
        free(temp);
    }
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

void tampilkanSeluruhData(addressKota K) {
    if (K == Nil) {
        printf("Tidak ada data kota yang tersimpan\n");
        return;
    }

    while (K != Nil) {
        tampilkanDataSuatuKota(K);
        printf("\n");
        K = next(K);
    }
}