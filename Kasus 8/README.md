# PROGRAM NON-BINARY TREE
Folder ini berisikan program yang mengimplementasikan menu untuk proses-proses yang bisa dilakukan oleh non-binary tree seperti proses traversal PreOrder, InOrder, PostOrder, LevelOrder, proses menampilkan
detail node pada non-binary tree, pencarian suatu node pada non-binary tree, menghitung jumlah leaf pada non-binary tree, pencarian level suatu node pada non-binary tree, menentukan kedalaman suatu 
non-binary tree, dan membandingkan 2 node pada non-binary tree.

---

## STRUKTUR DATA
Pada program ini struktur data array statis di gunakan untuk membuat non-binary tree, dimana saya melakukan pengindeksan terhadap setiap node yang terdapat di dalam non-binary tree.

---

## ALGORITMA
Program ini menggunakan teknik penulisan program yang modular (Modular Programming) dengan membagi file program bahasa C menjadi 3 buah file header (.h) dan 3 buah file body (.c) yaitu:
- **convention.h :** file header untuk membuat definisi penulisan yang lebih readable dan orisinal.
- **nbtrees.h :** file header yang berisikan struktur data Isi_Tree bertipe nbtree statis dan struktur data queue bertipe statis, serta header untuk modul-modul logika proses tree seperti create tree, traversal, search, dan function lainnya.
- **nbtrees.c :** file body yang berisikan algoritma dari modul-modul logika proses tree seperti create tree, traversal, search, dan function lainnya.
- **case8.h :** file header yang berisikan modul addData(untuk menginisialisasikan setiap node kedalam tree), searchNode(untuk mencari suatu node dalam non-binary tree), searchNodeLevel(mencari level dari suatu node dalam non-binary tree),
dan compareNode(untuk membandingkan dua buah node dalam non-binary tree untuk menentukan node mana yang memiliki nilai lebih besar).
- **case8.c :** file body yang berisikan algoritma modul-modul addData, searchNode, searchNodeLevel, dan compareNode.
- **main.c :** file body yang berisikan algoritma menu dari program non-binary tree dengan 11 pilihan.

---

## ALUR PROGRAM 
Dari sudut pandang user sebagai pengguna program, algoritma dari program ini akan berjalan sebagai berikut :
User akan memasuki menu dengan 11 pilihan diantaranya : pilihan 1 Traversal PreOrder, pilihan 2 Traversal InOrder, pilihan 3 Traversal PostOrder, pilihan 4 Traversal LevelOrder, pilihan 5 menampilkan seluruh node pada tree beserta detail info-firstson-nextbrother-parent, pilihan 6 Mencari sebuah node, pilihan 7 menghitung jumlah leaf, pilihan 8 mencari level dari suatu node, pilihan 9 menentukan kedalaman suatu 
non-binary tree, pilihan 10 membandingkan 2 node dan mencari node dengan nilai terbesar, dan pilihan 11 untuk keluar dari program.

---

## KENDALA 
Dalam program ini saya kesulitan untuk membuat algoritma dari ke empat traversal PreOrder, InOrder, PostOrder, LevelOrder agar menghasilkan output yang tepat.

---

## LESSON LEARNED
Dari program ini saya belajar banyak hal terkait materi tree khususnya non-binary tree dimulai dari bagaimana suatu tree di inisialisasikan dan bagaimana proses dari suatu traversal.

