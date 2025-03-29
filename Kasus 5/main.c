#include "case5.h"

#define MAX_CITIES 20

int main() {
    kota arrayKota[MAX_CITIES] = {{"", Nil}};  
    int size;                     
    int input;

	printf("Masukkan jumlah kota (maksimal %d): ", MAX_CITIES);
	scanf("%d", &size);

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
                addData(arrayKota, size);
                break;
            case 2:
                delete(arrayKota, size); 
                break;
            case 3:
                tampil(arrayKota, size);  
                break;
            case 4:
                deleteSeluruhKota(arrayKota, size); 
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