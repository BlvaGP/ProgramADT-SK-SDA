# PROGRAM PERPUSTAKAAN
Folder ini berisikan program yang mengimplementasikan kegiatan-kegiatan yang biasa di lakukan di perpustakaan. pada folder ini program mengimplementasikan fitur-fitur untuk pengunjung perpustakaan seperti logika ketika mengantri untuk meminjam suatu buku, logika proses peminjaman buku dalam sebuah antrian, logika proses pengembalian buku, logika untuk penampilkan riwayat kegiatan seorang pengunjung, logika pembatalan/proses undo kegiatan seseorang. Pada Program ini saya menggunakan tiga jenis struktur data linear yang berbeda, diantaranya yaitu Single Linked List, Double Linked List, dan Array Statis.

---

## STRUKTUR DATA
Terdapat 3 Struktur Data yang digunakan pada program ini:
- **Single Linked List**: Pada SLL, saya memiliki dua buah Struktur Data dengan tipe yang sama yaitu booklist yang bertipe struct Node untuk menyimpan data buku secara dinamis, lalu terdapat struktur data QueueNode yang di dalamnya mengimplementasikan struct Node untuk menyimpan data antrian secara dinamis juga, kedua struktur data ini dibungkus agar dapat saling berinteraksi di dalam struktur data LibrarySingle.
- **Double Linked List**: Pada Double Linked List atau yang sebenarnya ialah Dual Linked List (karena tidak menggunakan pointer previuos), saya memiliki satu buah struktur data yaitu LibraryDouble yang didalam nya mengimplementasikan struct DNode, dimana pada DNode ini terdapat dua buah pointer yang mana pointer pertama di gunakan untuk menunjuk node buku selanjutnya dan pointer yang kedua digunakan untuk menunjuk antrian para peminjam buku.
- **Array Statis**: Pada Array Statis, saya memiliki satu buah Struktur Data yaitu LibraryArray yang di dalamnya mengimplementasikan struct Book dengan deklarasi maksimal jumlah array untuk menetapkan maksimal jumlah buku yang tersedia di perpustakaan tersebut. Pada struct Book terdapat pointer untuk menunjuk antrian para peminjam buku.

---

## ALGORITMA
Program ini menggunakan teknik penulisan program yang modular (Modular Programming) dengan membagi file program bahasa C menjadi 5 buah file header (.h) dan 5 buah file body (.c) yaitu:
- **convention.h :** file header untuk membuat definisi penulisan yang lebih readable dan orisinal.
- **LinkedList.h :** file header yang berisikan struktur data Node dan DNode, serta header untuk modul-modul logika utama program yang nantinya akan direuse.
- **LinkedList.c :** file body yang berisikan algoritma dari modul-modul logika utama program.
- **queue.h :** file header yang berisikan struktur data Queue untuk membuat antrian peminjam, dan header untuk modul-modul proses penanganan Queue seperti enqueue dan dequeue.
- **queue.c :** file body yang berisikan algoritma modul-modul untuk proses penanganan Queue seperti enqueue dan dequeue.
- **stack.h :** file header yang berisikan struktur data Stack untuk membuat History aktivitas para pengunjung perpustakaan, dan header untuk modul-modul proses penanganan Stack seperti push dan pop.
- **stack.c :** file body yang berisikan algoritma modul-modul untuk proses penanganan Stack seperti push dan pop.
- **kasus.h :** file header yang berisikan struktur data penggabung list buku dan antriannya seperti LibrarySingle, LibraryDouble, LibraryArray, serta terdapat header untuk modul-modul proses yang terdapat di perpustakaan seperti proses mengantri untuk sebuah buku, proses meminjam buku, proses pengembalian buku, proses menampilkan aktivitas pemijam, dan proses membatalkan suatu aktivitas. selain dari itu terdapat juga header dari untuk menu struktur data yang di gunakan perpustakaan misalnya SingleList, DoubleList, dan ArrayList.
- **kasus.c :** file body yang berisikan algoritma modul-modul yang terdapat di file header kasus.h
- **main.c :** file body yang berisikan algoritma menu utama yang akan di kunjungi user untuk memilih struktur data apa yang akan di gunakan.

---

## ALUR PROGRAM 
Dari sudut pandang user sebagai pengguna program, algoritma dari program ini akan berjalan sebagai berikut :
1. User akan memasuki menu utama dengan 4 pilihan dengan 3 diantaranya untuk memilih struktur data apa yang ingin digunakan yaitu Single Linked List, Double Linked List, Array List, dan pilihan terakhir untuk keluar dari program.
2. Jika user memilih antara pilihan nomor 1 sampai 3 maka user akan memasuki menu ke dua yaitu program utama perpustakaan yang di dalamnya terdapat 7 pilihan yaitu Menambahkan buku, Mengantri untuk suatu buku, melakukan proses peminjaman suatu buku, melakukan proses pengembalian suatu buku, menampilkan riwayat kegiatan salah satu pengunjung, melakukan pembatalan aktivitas terakhir salah satu pengunjung, dan kembali ke menu utama. Perbedaan dari menu pilihan nomor 1 sampai 3 di menu utama ialah struktur data yang di gunakan yang mana jika memilih nomor 1 program akan menggunakan struktur data LibrarySingle, jika memilih nomor 2 program akan menggunakan struktur LibraryDouble, dan Jika memilih nomor 3 program akan menggunakan struktur LibraryArray.
3. Jika user memilih pilihan nomor 4 pada menu utama maka program akan melakukan dealokasi untuk seluruh memori yang telah di pesan ketika memakai struktur data yang dinamis pada Single Linked List, Double Linked List, dan antrian peminjam pada Array List, lalu program akan terhenti.

---

## KENDALA 
Dalam program ini saya kesulitan untuk menghubungkan antrian peminjam agar menunjuk pada sebuah node buku pada struktur data Single Linked List, serta berbagai error yang terdapat pada modul-modul yang di buat.

---

## LESSON LEARNED
Dari program ini saya menyadari bahwa single linked list yang sederhana ternyata sulit di implementasikan ketika terdapat beberapa ketentuan khusus.


