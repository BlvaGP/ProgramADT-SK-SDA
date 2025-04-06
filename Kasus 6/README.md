# PROGRAM PENYIMPANAN DATA KOTA DAN PENDUDUKNYA
Folder ini berisi program yang memiliki fungsi utama untuk menyimpan data kota beserta data para penduduk yang tinggal di kota tersebut, program ini memiliki kemiripan yang cukup tinggi dengan program yang berada
di kasus 5. Perbedaan yang terdapat di dalam program penyimpanan data kota dan penduduk di kasus 6 ini terletak pada sturktur data KOTA dan beberapa modul yang digunakan oleh struktur data KOTA.

---

## STRUKTUR DATA
Terdapat dua struktur data yang digunakan sebagaimana telah disampaikan di deskripsi program:
- **List/Node dinamis** berbentuk record dengan dua subvariabel yaitu, info bertipe pointer dari karakter untuk menyimpan data nama penduduk dan next bertipe pointer dari tipe data record node yang berfungsi untuk menunjuk sebuah list warga
- **List/Node dinamis** berbentuk record dengan tiga subvariabel yaitu, namaKota bertipe pointer dari karakater untuk menyimpan nama kota, listWarga yang bertipe pointer dari tipe data node untuk menunjuk sebuah list yang berisikan data penduduk, serta next yang bertipe pointer dari tipe data record kota yang berfungsi untuk menunjuk sebuah list kota 

---

## ALGORITMA
Program ini menggunakan teknik penulisan program yang modular (Modular Programming) dengan membagi file program bahasa C menjadi 4 buah file header (.h) dan 4 buah file body (.c) yaitu:
- **convention.h**  : file header untuk membuat pengalisan
- **LinkedList.h**  : file header yang berisikan struktur data list, dan header untuk modul-modul logika utama program
- **LinkedList.c**  : file body yang berisikan algoritma dari modul-modul logika utama program
- **kota.h**        : file header yang berisikan struktur data list, dan header untuk modul-modul logika manipulasi data kota dan penduduknya
- **kota.c**        : file body yang berisikan algoritma modul-modul untuk manipulasi data kota dan penduduk yang memanggil modul-modul LinkedList
- **case6.h**       : file header yang berisikan modul-modul untuk penanganan input pengguna
- **case6.c**       : file body yang berisikan algoritma modul-modul penanganan input pengguna
- **main.c**        : file body yang berisikan algoritma utama yang menyatukan seluruh logika program yang telah di buat di dalam ke-7 file sebelummnya

---

## ALUR PROGRAM 
Dari sudut pandang user sebagai pengguna program, algoritma program ini berjalan sebagai berikut :
1. User memasuki 4 menu utama dengan 4 pilihan yaitu :
   - Menambahkan data kota beserta penduduknya
   - Menghapus data (didalamnya terdapat beberapa pilihan)
   - Menampilkan data (didalamnya terdapat beberapa pilihan)
   - Keluar dari program
2. Jika user memilih menu pertama yaitu menambahkan data kota, user akan diminta untuk memasukan nama kota yang akan disimpan lalu user akan diminta untuk memasukan satu nama penduduk yang tinggal di kota tersebut. setelah menyimpan satu nama penduduk user akan di beri pilihan apakah ingin menambahkan data penduduk lain yang menempati kota tersebut atau tidak.
   Jika user memilih untuk berhenti menambahkan data penduduk di kota sebelumnya user akan diberikan pilihan apakah ingin menambahkan kota lainnya atau tidak, jika user memilih untuk menambahkan kota lainnya maka seperti yang sudah dilakukan sebelumnya user akan diminta untuk memasukan data warga untuk kota tersebut. program ini akan terus berulang sampai user memilih untuk tidak menambahkan kota lainnya.
3. Jika user memilih menu kedua yaitu menghapus data, user akan mendapatkan beberapa pilihan lagi diantaranya :
   - menghapus seluruh data (pilihan ini akan menghapus seluruh data kota beserta data penduduk yang tinggal di setiap kota)
   - menghapus data suatu kota (pilihan ini akan menghapus data suatu kota beserta data penduduk yang tinggal di kota tersebut)
   - menghapus data penduduk (pilihan ini akan menghapus data penduduk yang terdapat di suatu kota, tetapi tidak menghapus data kotanya)
   - menghapus data suatu penduduk (pilihan ini membutuhkan input nama dan kota asal penduduk dari untuk dihapus data nya dari kota tertentu).
4. Jika user memilih menu ketiga yaitu menampilkan data, user akan mendapatkan beberapa pilihan lagi diantaranya :
   - menampilkan seluruh data (pilihan ini akan menampilkan data dari seluruh kota dan penduduk yang tersimpan di dalam program)
   - menampilkan data suatu kota (pilihan ini membutuhkan input nama kota yang isinya ditampilkan, lalu perintah ini akan menampilkan data dari salah satu kota yang dipilih beserta isi dari data penduduknya)
   - menampilkan data suatu warga (pilihan ini membutuhkan input nama penduduk dan nama kota yang ia tinggali untuk menampilkan data dari seorang penduduk)
5. Jika user memilih menu keempat yaitu keluar, program akan membersihkan/menghapus seluruh data yang tersimpan lalu program akan berhenti berjalan

---

## KENDALA 
Dalam pembuatan program ini saya mendapati kendala ketika ingin merubah rancangan dari suatu array statis yang memiliki sebuah pointer untuk
menunjuk sebuah list yang bersifat dinamis, menjadi sebuah list dinamis yang memiliki beberapa subvar diantaranya sebuah pointer karakter untuk menyimpan nama kota, lalu sebuah pointer untuk menunjuk node warga, serta sebuah pointer untuk menunjuk ke node kota yang berikutnya.
Dan juga saya mendapati beberapa kendala dalam menyesuaikan modul-modul yang terdapat di file kota dan file case5 agar sesuai dengan sturktur data list dinamis yang baru, sehingga program dapat berjalan dengan baik.

---

## LESSON LEARNED
Dengan menyelesaikan program ini, saya menjadi semakin paham metode reuse(penggunaan ulang algoritma yang sudah dibuat) modul yang telah saya buat dari tugas-tugas sebelumnya. 
program ini juga meningkatkan pengetahuan saya dalam konsep pointer tentang bagaimana suatu list itu dapat memiliki dua buah pointer dimana agar dapat bekerja dengan baik, yang dimana hal ini dapat di katakan sebagai double likedlist.
