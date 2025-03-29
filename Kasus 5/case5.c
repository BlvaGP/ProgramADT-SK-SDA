#include "case5.h"

void addData(kota * K, int size) {
    char namaWarga[50];
    char choice;
    
    for (int i = 0; i < size; i++) {
        if (strcmp(K[i].namaKota, "") == 0) {
            printf("Masukkan nama kota ke-%d: ", i + 1);
            entryNamaKota(&K[i]);

            boolean lagi = true;
            while (lagi) {
                printf("Masukkan nama warga: ");
                entryNamaWarga(namaWarga);  
                createWarga(&K[i], namaWarga);

                printf("Apakah Anda ingin menambah data warga lagi? (y/n): ");
                scanf(" %c", &choice);  
                if (choice == 'n' || choice == 'N') {
                    lagi = false;
                }
            }
        } else {
            printf("Slot kota ke-%d sudah terisi: %s\n", i + 1, namaKota(&K[i]));
        }
    }
}

void delete(kota * K, int size) {
    int input;
    char namaKota[50];
    char namaWarga[50];

    printf("=== HAPUS DATA ===\n");
    printf("1. Hapus Seluruh Data\n");
    printf("2. Hapus Suatu Kota\n");
    printf("3. Hapus Data Seluruh Warga di Kota Tertentu\n");
    printf("4. Hapus Data Suatu Warga di Kota Tertentu\n");
    printf("5. Kembali\n");
    printf("Pilih opsi: ");
    scanf("%d", &input);

    switch (input) {
        case 1:
            deleteSeluruhKota(K, size);
            printf("Seluruh data kota dan warga telah dihapus.\n");
            break;
        case 2:
            printf("Masukkan nama kota yang ingin dihapus: ");
            scanf("%s", namaKota);
            deleteKota(K, size, namaKota);
            printf("Kota %s telah dihapus.\n", namaKota);
            break;
        case 3:
            printf("Masukkan nama kota: ");
            scanf("%s", namaKota);
            for (int i = 0; i < size; i++) {
                if (strcmp(namaKota(&K[i]), namaKota) == 0) {
                    deleteSeluruhWarga(&K[i]);
                    printf("Seluruh warga di kota %s telah dihapus.\n", namaKota);
                    break;
                }
                if (i == size - 1) {
                    printf("Kota %s tidak ditemukan.\n", namaKota);
                }
            }
            break;
        case 4:
            printf("Masukkan nama kota: ");
            scanf("%s", namaKota);
            printf("Masukkan nama warga yang ingin dihapus: ");
            scanf("%s", namaWarga);
            for (int i = 0; i < size; i++) {
                if (strcmp(namaKota(&K[i]), namaKota) == 0) {
                    deleteWargaByName(&K[i], namaWarga);
                    printf("Warga %s di kota %s telah dihapus.\n", namaWarga, namaKota);
                    break;
                }
                if (i == size - 1) {
                    printf("Kota %s tidak ditemukan.\n", namaKota);
                }
            }
            break;
        case 5:
            printf("Kembali ke menu utama.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
    }
}

void tampil(kota * K, int size) {
    int input;
    char namaKota[50];
    char namaWarga[50];
    boolean found;

    printf("\n=== TAMPILKAN DATA ===\n");
    printf("1. Tampilkan Seluruh Data\n");
    printf("2. Tampilkan Data Suatu Kota\n");
    printf("3. Cari Data Warga\n");
    printf("4. Kembali\n");
    printf("Pilih opsi: ");
    scanf("%d", &input);

    switch (input) {
        case 1:
            printf("\n");
            tampilkanSeluruhData(K, size);
            break;
        case 2:
            printf("\nMasukkan nama kota: ");
            scanf("%s", namaKota);
            found = false;
            
            for (int i = 0; i < size; i++) {
                if (strcmp(K[i].namaKota, namaKota) == 0) {
                    printf("\n");
                    tampilkanDataSuatuKota(&K[i]);
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                printf("Kota %s tidak ditemukan\n", namaKota);
            }
            break;
        case 3:
            printf("\nMasukkan nama warga: ");
            scanf("%s", namaWarga);
            printf("\nMasukkan nama kota: ");
            scanf("%s", namaKota);
            found = false;
            
            for (int i = 0; i < size; i++) {
                if (strcmp(K[i].namaKota, namaKota) == 0) {
                    printf("\n");
                    tampilkanDataWargaByName(&K[i], namaWarga);
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                printf("Kota %s tidak ditemukan\n", namaKota);
            }
            break;
        case 4:
            printf("Kembali ke menu utama.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
    }
}