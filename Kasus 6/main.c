#include "case5.h"

int main() {
    int input;
    addressKota cities;
    initKota(&cities);

    while (1) {
        printf("=== DATA KOTA DAN PENDUDUKNYA ===\n");
        printf("1. Tambah Data\n");
        printf("2. Hapus Data\n");
        printf("3. Tampilkan Data\n");
        printf("4. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                addData(&cities);
                break;
            case 2:
                delete(&cities); 
                break;
            case 3:
                tampil(&cities);  
                break;
            case 4:
                deleteSeluruhKota(&cities); 
                printf("Program selesai.\n");
                exit(0);
                break;
            default:
                printf("Pilihan tidak valid, coba lagi.\n");
                break;
        }
    }
    return 0;
}