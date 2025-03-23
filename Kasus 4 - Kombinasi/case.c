//file case.c
#include "case.h"

void addItem(Queue *cart) {
    char nama[50], kategori[50];
    char *aksi;
    int jumlah;
    float harga, total;

    printf("Nama barang: ");
    scanf(" %[^\n]s", nama);
    printf("Kategori: ");
    scanf(" %[^\n]s", kategori);
    printf("Jumlah: ");
    scanf("%d", &jumlah);
    printf("Harga: ");
    scanf("%f", &harga);

    item newItem = createItem(nama, kategori, jumlah, harga, total, "ditambahkan");
    enqueue(cart, newItem);
    printf("Barang %s ditambahkan ke keranjang!\n", nama);
}

void buyItem(Queue *cart, Stack *history) {
    if (countQueue(cart) > 0) {
        item bought;
        dequeue(cart, &bought);
        free(bought.aksi);
        bought.aksi = setAksi("dibeli");
        push(history, bought);
        printf("Barang %s dibeli, dengan Total harga: %.2f\n", bought.nama, bought.total);
    } else {
        printf("Keranjang kosong\n");
    }
}

void undoItem(Queue *cart, Stack *history) {
    if (history->list != Nil) {
        item undone;
        pop(history, &undone);
        free(undone.aksi);
        undone.aksi = setAksi("ditambahkan kembali");
        enqueue(cart, undone);
        printf("Perubahan terakhir dibatalkan: %s kembali ke keranjang\n", undone.nama);
    } else {
        printf("Riwayat kosong\n");
    }
}

void deleteItem(Queue *cart, Stack *history) {
    char nama[50];
    printf("Nama barang yang ingin dihapus: ");
    scanf(" %[^\n]s", nama);

    item toDelete = createItem(nama, "", 0, 0, 0, "dihapus");
    deleteFromCart(cart, toDelete);
    push(history, toDelete);
    printf("Barang %s dihapus dari keranjang\n", nama);
}