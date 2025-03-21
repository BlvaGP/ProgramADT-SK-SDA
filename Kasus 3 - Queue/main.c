#include "queue.h"

int main() {
    Queue q1, q2;
    createQueue(&q1);
    createQueue(&q2);
    int n;
    int antrian = 1;
    while (1) {
        printf("SELAMAT DATANG DI PINJAMAN ONLINE\n");
        printf("TENTUKAN PILIHAN ANDA:\n");
        printf("1. Ambil Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("4. Exit\n");

        scanf("%d", &n);
        switch (n)
        {
        case 1:
            rekomendasiAntrian(&q1, &q2, antrian);
            antrian++;
            break;
        case 2:
            infotype processed;
            urutanProses(&q1, &q2, &processed);
            break;
        case 3:
            printf("\n--- ANTRIAN 1 ---\n");
            printQueue(&q1);
            printf("\n--- ANTRIAN 2 ---\n");
            printQueue(&q2);
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }    
}