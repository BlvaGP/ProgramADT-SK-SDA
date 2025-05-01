#include "kasus.h"

int main() {
    LibrarySingle libSingle;
    LibraryDouble libDouble;
    LibraryArray libArray;
    int choice;

    // Initialize libraries
    createLibrarySingle(&libSingle);
    createLibraryDouble(&libDouble);
    createLibraryArray(&libArray);
    createHistory(&globalHistory);

    do {
        printf("==========SISTEM ANTRIAN PEMINJAMAN BUKU==========\n");
        printf("1. Single Linked List\n");
        printf("2. Double Linked List\n");
        printf("3. Array\n");
        printf("4. Keluar\n");
        printf("Tentukan pilihan anda: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                singleLinked(&libSingle);
                break;
            case 2:
                doubleLinked(&libDouble);
                break;
            case 3:
                array(&libArray);
                break;
            case 4:
                // Deallocate all resources
                deAlokasiLibrarySingle(&libSingle);
                deAlokasiLibraryDouble(&libDouble);
                deAlokasiLibraryArray(&libArray);
                deallocateHistory(&globalHistory);
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 4);

    return 0;
}