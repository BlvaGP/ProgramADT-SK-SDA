#include "case5.h"

void addData(addressKota * K) {
    char namaKota[50];
    char namaWarga[50];
    char choice;
    boolean lagik = true;
    
    while (lagik) {
        printf("Masukkan nama kota: ");
        entryNamaKota(namaKota);
        addressKota kotaBaru = createKota(K, namaKota);
        if (kotaBaru == Nil) {
            printf("Gagal menambahkan kota.\n");
            continue;
        }
        boolean lagiw = true;
        while (lagiw) {
            printf("Masukkan nama warga: ");
            entryNamaWarga(namaWarga);  
            createWarga(kotaBaru, namaWarga);

            printf("Apakah Anda ingin menambah data warga lagi? (y/n): ");
            scanf(" %c", &choice);  
            if (choice == 'n' || choice == 'N') {
                lagiw = false;
            }
        }
        printf("Apakah Anda ingin menambah kota lagi? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N') {
            lagik = false;
        }
    }
}

void delete(addressKota * K) {
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
            deleteSeluruhKota(K);
            printf("Seluruh data kota dan warga telah dihapus.\n");
            break;
        case 2:
            printf("Masukkan nama kota yang ingin dihapus: ");
            scanf("%s", namaKota);
            deleteKota(K, namaKota);
            printf("Kota %s telah dihapus.\n", namaKota);
            break;
        case 3:
            printf("Masukkan nama kota: ");
            scanf("%s", namaKota);
            addressKota kotaDitemukan = findKota(*K, namaKota);
            if (kotaDitemukan) {
                deleteSeluruhWarga(kotaDitemukan);
                printf("Seluruh warga di kota %s telah dihapus.\n", namaKota);
            } else {
                printf("Kota %s tidak ditemukan.\n", namaKota);
            }
            break;
        case 4:
            printf("Masukkan nama kota: ");
            scanf("%s", namaKota);
            printf("Masukkan nama warga yang ingin dihapus: ");
            scanf("%s", namaWarga);
            kotaDitemukan = findKota(*K, namaKota);
            if (kotaDitemukan) {
                deleteWargaByName(kotaDitemukan, namaWarga);
                printf("Warga %s di kota %s telah dihapus.\n", namaWarga, namaKota);
            } else {
                printf("Kota %s tidak ditemukan.\n", namaKota);
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

void tampil(addressKota * K) {
    int input;
    char namaKota[50];
    char namaWarga[50];
    addressKota kotaDitemukan;

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
            tampilkanSeluruhData(*K);
            break;
        case 2:
            printf("\nMasukkan nama kota: ");
            scanf("%s", namaKota);
            kotaDitemukan = findKota(*K, namaKota);
            if (kotaDitemukan) {
                printf("\n");
                tampilkanDataSuatuKota(kotaDitemukan);
            } else {
                printf("Kota %s tidak ditemukan\n", namaKota);
            }
            break;
        case 3:
            printf("\nMasukkan nama warga: ");
            scanf("%s", namaWarga);
            printf("\nMasukkan nama kota: ");
            scanf("%s", namaKota);
            kotaDitemukan = findKota(*K, namaKota);
            if (kotaDitemukan) {
                printf("\n");
                tampilkanDataWargaByName(kotaDitemukan, namaWarga);
            } else {
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