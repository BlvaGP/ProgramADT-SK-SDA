# PROGRAM PENYIMPANAN DATA KOTA DAN PENDUDUKNYA
Folder ini berisi program yang memiliki fungsi utama untuk menyimpan data kota beserta data para penduduk yang tinggal di kota tersebut, isi dari data kota disimpan dalam 
bentuk array statis dengan dua subvar yaitu string untuk menyimpan nama kota dan pointer untuk menunjuk sebuah Node/List dinamis yang berisikan data penduduk yang tinggal di kota tersebut.

---

## STRUKTUR DATA
Terdapat dua struktur data yang digunakan sebgaaimana telah disampaikan di deskripsi program:
- **List/Node dinamis** berbentuk record dengan dua subvariabel yaitu, info bertipe pointer dari karakter untuk menyimpan data nama penduduk dan next bertipe pointer dari tipe data record node
- **Array statis** berbentuk record dengan dua subvariabel yaitu, namaKota bertipe karakter dengan jumlah maksimal kata 50 untuk menyimpan nama kota dan listWarga yang bertipe pointer dari tipe data node untuk menunjuk sebuah list yang berisikan data penduduk

---

## ALGORITMA
Program ini menggunakan teknik penulisan program yang modular (Modular Programming) dengan membagi file program bahasa C menjadi 4 buah file header (.h) dan 4 buah file body (.c) yaitu:
- **convention.h**  : file header untuk membuat pengalisan
- **LinkedList.h**  : file header yang berisikan struktur data list, dan header untuk modul-modul logika utama program
- **LinkedList.c**  : file body yang berisikan algoritma dari modul-modul logika utama program
- **kota.h**        : file header yang berisikan struktur data array, dan header untuk modul-modul logika manipulasi data kota dan penduduknya
- **kota.c**        : file body yang berisikan algoritma modul-modul untuk manipulasi data kota dan penduduk yang memanggil modul-modul LinkedList
- **case5.h**       : file header yang berisikan modul-modul untuk penanganan input pengguna
- **case5.c**       : file body yang berisikan algoritma modul-modul penanganan input pengguna
- **main.c**        : file body yang berisikan algoritma utama yang menyatukan seluruh logika program yang telah di buat di dalam ke-7 file sebelummnya

---

## ALUR PROGRAM 
Dari sudut pandang user sebagai pengguna program, algoritma program ini berjalan sebagai berikut :
1. User diminta untuk memasukan data dari jumlah kota yang akan disimpan
2. User memasuki 4 menu utama dengan 4 pilihan yaitu :
   - Menambahkan data kota beserta penduduknya
   - Menghapus data (didalamnya terdapat beberapa pilihan)
   - Menampilkan data (didalamnya terdapat beberapa pilihan)
   - Keluar dari program
4. Jika user memilih menu pertama yaitu menambahkan data kota, user akan diminta untuk memasukan nama kota yang akan disimpan lalu user akan diminta untuk memasukan satu nama penduduk yang tinggal di kota tersebut. setelah menyimpan satu nama penduduk user akan di beri pilihan apakah ingin menambahkan data penduduk lain yang menempati kota tersebut atau lanjut menambahkan data dari nama kota yang lainnya. program ini berulang terus menurus sampai jumlah kota yang ditentukan di awal program.
5. Jika user memilih menu kedua yaitu menghapus data, user akan mendapatkan beberapa pilihan lagi diantaranya :
   - menghapus seluruh data (pilihan ini akan menghapus seluruh data kota beserta data penduduk yang tinggal di setiap kota)
   - menghapus data suatu kota (pilihan ini akan menghapus data suatu kota beserta data penduduk yang tinggal di kota tersebut)
   - menghapus data penduduk (pilihan ini akan menghapus data penduduk yang terdapat di suatu kota, tetapi tidak menghapus data kotanya)
   - menghapus data suatu penduduk (pilihan ini membutuhkan input nama dan kota asal penduduk dari untuk dihapus data nya dari kota tertentu).
6. Jika user memilih menu ketiga yaitu menampilkan data, user akan mendapatkan beberapa pilihan lagi diantaranya :
   - menampilkan seluruh data (pilihan ini akan menampilkan data dari seluruh kota dan penduduk yang tersimpan di dalam program)
   - menampilkan data suatu kota (pilihan ini membutuhkan input nama kota yang isinya ditampilkan, lalu perintah ini akan menampilkan data dari salah satu kota yang dipilih beserta isi dari data penduduknya)
   - menampilkan data suatu warga (pilihan ini membutuhkan input nama penduduk dan nama kota yang ia tinggali untuk menampilkan data dari seorang penduduk)
7. Jika user memilih menu keempat yaitu keluar, program akan membersihkan/menghapus seluruh data yang tersimpan lalu program akan berhenti berjalan

---

## KENDALA 
Dalam pembuatan program ini saya mendapati kendala ketika ingin merancang suatu array statis yang memiliki sebuah pointer untuk menunjuk sebuah list yang bersifat dinamis.

---

## LESSON LEARNED
Dengan menyelesaikan program ini, saya menjadi semakin paham metode reuse(penggunaan ulang algoritma yang sudah dibuat) modul yang telah saya buat dari tugas-tugas sebelumnya. program ini juga meningkatkan pengetahuan saya dalam konsep pointer serta bagaimana suatu array statis ketika dipanggil oleh sebuah modul dia akan otomatis bersifat sebagai sebuah pointer.
