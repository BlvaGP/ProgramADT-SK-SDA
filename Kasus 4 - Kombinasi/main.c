//file main.c
#include "case.h"

int main() {
    Queue cart;
    Stack history;
    createQueue(&cart);
    createStack(&history);
    int input;

    while (1) {
        printf("=== Wishlist Belanja Online ===\n");
        printf("1. Tambah Barang ke Keranjang\n");
        printf("2. Proses Pembelian (Checkout)\n");
        printf("3. Batalkan Perubahan Terakhir (Undo)\n");
        printf("4. Hapus Barang dari Wishlist\n");
        printf("5. Tampilkan Keranjang\n");
        printf("6. Tampilkan Riwayat Perubahan\n");
        printf("7. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            addItem(&cart);
            break;
        case 2:
            buyItem(&cart, &history);
            break;
        case 3:
            undoItem(&cart, &history);
            break;
        case 4:
            deleteItem(&cart, &history);
            break;
        case 5:
            printCart(&cart);
            break;
        case 6:
            printChangesHistory(&history);
            break;
        case 7:
            DeAlokasi(&cart.head);
            DeAlokasi(&history.list);
            exit(0);
            break;
        default:
            break;
        }
    }
    
}