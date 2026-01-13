// Sorting berdasarkan jam mulai (Bubble Sort)
void bubbleSortJam() {
    Dokter temp;  // variabel sementara untuk proses pertukaran
    /*
    "temp"= Variabel temp dipakai sebagai wadah sementara untuk melakukan pertukaran (swap) 
    dua elemen Dokter. Karena jadwal menyimpan struct, kita swap seluruh struct (nama, spesialis, jam, menit) dengan memakai temp.*/
    // algoritma bubble sort
    for (int i = 0; i < jumlah - 1; i++) {
        /*
        -Ini adalah putaran luar.
        -Tugasnya: menentukan berapa kali proses pengurutan dijalankan.
        -arena bubble sort perlu beberapa kali “menggeser” data, putaran ini mengulang proses sorting itu berkali-kali sampai urut.
        Analoginya:
        Bayangin kamu mengurutkan kartu. Kamu cek berulang-ulang dari awal ke akhir 
        sampai semuanya beres.*/
        for (int j = 0; j < jumlah - i - 1; j++) {
            /*=>Ini adalah putaran yang benar-benar membandingkan dua data di sebelah-sebelah.
            -j itu posisi yang diperiksa.
            -Di sini kamu membandingkan jadwal[j] dengan jadwal[j+1]
            -Kalau waktu mulai di jadwal[j] lebih besar daripada jadwal[j+1], maka posisinya ditukar.
            =>Sederhananya:
            -Kamu cek 2 data yang berdampingan.
            -Kalau urutannya salah, kamu tukar.
            =>Kenapa batasnya jumlah - i - 1
            Ini bagian yang biasanya bikin bingung. Gini simplenya:
            -Setelah beberapa putaran, data di posisi belakang sudah pasti benar.
            -Jadi tidak perlu diperiksa lagi.
            -Supaya tidak membuang waktu, jangkauan loop j makin lama makin pendek.
            Contoh:
            -Putaran 1 → elemen terbesar pindah ke paling belakang
            -Putaran 2 → elemen terbesar kedua pindah ke posisi kedua dari belakang
            dst.
            =>Kesimpulan
            -i = berapa kali proses diulang
            -j = posisi data yang diperiksa
            -temp = alat bantu untuk menukar 2 data*/
            
            // Bandingkan jam terlebih dahulu
            if (jadwal[j].jamMulai > jadwal[j + 1].jamMulai ||
            (jadwal[j].jamMulai == jadwal[j + 1].jamMulai &&
                jadwal[j].menitMulai > jadwal[j + 1].menitMulai)) {
                    /*
                    =>jadwal[j].jamMulai > jadwal[j+1].jamMulai
                    artinya: jam mulai pada entri j lebih besar (lebih sore) daripada jam pada entri sebelahnya. 
                    Contoh: 10 > 9 → berarti 10:xx lebih terlambat dari 09:xx.
                    ATAU (operator ||)
                    =>(jadwal[j].jamMulai == jadwal[j+1].jamMulai && jadwal[j].menitMulai > jadwal[j+1].menitMulai)
                    artinya: kalau jam mulai sama, periksa menit. Jika menit pada j lebih besar (lebih terlambat), maka kondisi terpenuhi.
                    Contoh: jam sama 09 == 09, lalu 30 > 15 → berarti 09:30 lebih terlambat dari 09:15.
                    =>Jadi urutan pengecekan secara ringkas:
                    -cek jam dulu, jika jam j lebih besar → swap.
                    -kalau jam sama → cek menit, kalau menit j lebih besar → swap.
                    -kalau jam dan menit j tidak lebih besar → jangan swap.
                    
                    Penjelasan operator yang dipakai:
                    -> : lebih besar (untuk angka).
                    -== : sama persis (sama).
                    -&& : AND — kedua kondisi di sisi kiri dan kanan harus benar.
                    -|| : OR — salah satu kondisi (kiri/kanan) cukup benar.
                    Perintah if ( A || (B && C) ) artinya: kalau A benar atau (B dan C benar), maka jalankan blok if.
                    
                    Langkahnya:
                    -Simpan jadwal[j] ke temp (agar tidak hilang).
                    -Masukkan isi jadwal[j+1] ke jadwal[j].
                    -Ambil isi temp (yang menyimpan jadwal awal j) dan masukkan ke jadwal[j+1].
                    Hasil: posisi jadwal[j] dan jadwal[j+1] tertukar sepenuhnya (nama, spesialis, jam, menit semuanya pindah).
                    Catatan: ini menyalin seluruh struct, jadi seluruh informasi dokter ikut ditukar.
                    */

                // proses pertukaran 
                temp = jadwal[j]; // temp adalah variabel tipe Dokter untuk menampung satu entri sementara.
                jadwal[j] = jadwal[j + 1];
                jadwal[j + 1] = temp;
                /*
                Langkahnya:
                -Simpan jadwal[j] ke temp (agar tidak hilang).
                -Masukkan isi jadwal[j+1] ke jadwal[j].
                -Ambil isi temp (yang menyimpan jadwal awal j) dan masukkan ke jadwal[j+1].
                Hasil: posisi jadwal[j] dan jadwal[j+1] tertukar sepenuhnya (nama, spesialis, jam, menit semuanya pindah).
                Catatan: ini menyalin seluruh struct, jadi seluruh informasi dokter ikut ditukar.

                Langkahnya:
                -Simpan jadwal[j] ke temp (agar tidak hilang).
                -Masukkan isi jadwal[j+1] ke jadwal[j].
                -Ambil isi temp (yang menyimpan jadwal awal j) dan masukkan ke jadwal[j+1].
                Hasil: posisi jadwal[j] dan jadwal[j+1] tertukar sepenuhnya (nama, spesialis, jam, menit semuanya pindah).
                Catatan: ini menyalin seluruh struct, jadi seluruh informasi dokter ikut ditukar.
                
                ====Contoh nyata langkah demi langkah====
                =>Misal:
                -jadwal[j] = 10:30
                -jadwal[j+1] = 09:15
                =>Cek kondisi:
                -10 > 9 → benar, jadi if terpenuhi → lakukan swap.
                =>Setelah swap:
                -jadwal[j] = 09:15
                -jadwal[j+1] = 10:30
                =>Contoh jam sama:
                -jadwal[j] = 09:45
                -jadwal[j+1] = 09:30
                =>Cek:
                -09 > 09 → salah
                -09 == 09 → benar, lalu cek 45 > 30 → benar ⇒ swap
                Hasil: 09:30 di depan, 09:45 di belakang.*/
            }
        }
    }

    cout << "Jadwal berhasil diurutkan berdasarkan jam!\n";
}

=================================================== Penjelasan Tambahan ===================================================
=-=-=-=-=-=-=-=-=-=-= Apa yang terjadi jika tidak memakai temp(data sementara) saat swap? =-=-=-=-=-=-=-=-=-=-=
Karena kalau langsung ditukar tanpa variabel sementara, data akan hilang.
|||||||Contoh salah (tanpa temp):|||||||
jadwal[j] = jadwal[j + 1]; 
jadwal[j + 1] = jadwal[j]; // SALAH
|||||||Masalahnya:|||||||
1)Setelah baris pertama:
jadwal[j] diisi dengan jadwal[j+1].
2)Di baris kedua:
jadwal[j + 1] mau diisi dengan jadwal[j],
tapi jadwal[j] sudah berubah!
Harusnya jadwal[j] itu nilai lama, tapi nilainya sudah tertimpa.
Akibatnya kedua elemen jadi duplikat dan data asli hilang.

|||||||Ilustrasi simpelnya:|||||||
misal:
A = 5
B = 10
Kamu mau menukar A dan B tanpa variabel temp:
A = B;  // A sekarang 10
B = A;  // B juga jadi 10 -> nilai 5 hilang
Jadi nilai lama tidak bisa diselamatkan.

|||||||Ilustrasi versi benarnya|||||||
misal:
A = 5
B = 10
Dengan variabel temp:
temp = A; // temp = 5
A = B;    // A = 10
B = temp; // B = 5
Sekarang A dan B sudah tertukar dengan benar.


|||||||Apakah bisa tanpa variabel sementara?|||||||
Secara teori bisa, tetapi:
1)Harus menggunakan teknik swap khusus, seperti XOR swap (hanya untuk integer, tidak bisa untuk struct seperti Dokter).
2)Atau pakai std::swap dari library <algorithm>.
#include <algorithm>
Contoh kalau pakai std::swap:
std::swap(jadwal[j], jadwal[j+1]);
Ini tetap menggunakan variabel sementara di belakang layar, cuma kamu tidak melihatnya.
|||||||Kesimpulan:|||||||
➡ Untuk struct seperti Dokter, tidak bisa melakukan swap aman tanpa variabel sementara.


=-=-=-=-=-=-=-=-=-=-= penjelasan for (int i = 0; i < jumlah - 1; i++) =-=-=-=-=-=-=-=-=-=-=
||||||| Kenapa i dimulai dari 0 |||||||
Konvensi umum: indeks mulai dari 0. i kita pakai sebagai penghitung pass — bukan indeks elemen tertentu yang sedang dibandingkan. 
Nilai i bukan untuk mengakses elemen, melainkan untuk menghitung berapa kali kita sudah melakukan pass.

||||||| Kenapa kondisi i < jumlah - 1 (bukan i < jumlah)? |||||||
Karena setelah melakukan jumlah - 1 pass, seluruh array pasti sudah terurut. Alasan logisnya:
-Setelah setiap pass, elemen terbesar yang belum terurut akan "menggelembung" ke posisi
terakhir dari bagian yang belum terurut. 
-Jadi setelah jumlah - 1 pass, hanya tersisa satu elemen yang belum diperiksa
dan otomatis sudah di tempat yang benar.

||||||| Contoh sederhana |||||||
Misal ada 4 elemen: [A, B, C, D]
- Pass 1: elemen terbesar pindah ke posisi D
- Pass 2: elemen terbesar kedua pindah ke posisi C
- Pass 3: elemen terbesar ketiga pindah ke posisi B
Setelah 3 pass (jumlah - 1), elemen A otomatis di posisi yang benar.

||||||| Kesimpulan |||||||
➡ i < jumlah - 1 memastikan kita melakukan cukup pass untuk mengurutkan seluruh array tanpa
melakukan pass yang tidak perlu.

||||||| Penjelasan i++ |||||||
i mewakili pass ke berapa di Bubble Sort.
Setiap i++:
- menandakan bahwa satu pass sorting telah selesai,
- dan kita maju ke pass berikutnya. 
Karena Bubble Sort harus melakukan beberapa pass untuk memastikan daftar benar-benar terurut.

||||||| Apa yang terjadi jika tidak memakai i++ |||||||
Tanpa i++, nilai i tidak berubah—tetap 0 selamanya.
Akibatnya:
- kondisi i < jumlah - 1 akan selalu true,
(misalnya 0 < 4-1 → true)
- loop berjalan tanpa henti,
- program menjadi infinite loop (loop tak berujung).
Bubble Sort tidak akan pernah selesai.
Contoh cara kerja i++ (misal jumlah=4):
iterasi     =    1   2   3   4 
nilai i     =    0   1   2   3
kondisi i<3 =    T   T   T   F
Jadi i++ memastikan loop berhenti pada waktu yang tepat. (i++ == i += 1)


=-=-=-=-=-=-=-=-=-=-= penjelasan for (int j = 0; j < jumlah - i - 1; j++) =-=-=-=-=-=-=-=-=-=-=
|||||||Arti jadwal[j] dan jadwal[j + 1]|||||||
-jadwal[j] → data dokter sekarang
- jadwal[j + 1] → data dokter di sebelah kanannya
Bubble sort selalu membandingkan dua data yang bersebelahan.

|||||||Penjelasan kondisi if per bagian|||||||
=>Bagian 1
---jadwal[j].jamMulai > jadwal[j + 1].jamMulai---
Artinya:
Jika jam mulai dokter ke-j lebih besar dari dokter ke-(j+1)
Contoh:
- Dokter A mulai 10:00
- Dokter B mulai 08:00
Karena 10 > 8 → salah urutan, harus ditukar
=>Bagian 2 (pengecekan lanjutan)
(jadwal[j].jamMulai == jadwal[j + 1].jamMulai &&
jadwal[j].menitMulai > jadwal[j + 1].menitMulai)
Artinya:
- Jam mulai sama
- Tapi menit dokter ke-j lebih besar
Kalau dua kondisi ini benar → tetap harus ditukar

|||||||Kenapa harus pakai 2 tingkat pengecekan?|||||||
Karena waktu itu HH:MM, bukan cuma jam saja.
Urutannya:
- Bandingkan jam
- Kalau jam sama → bandingkan menit


|||||||Contoh kasus nyata dalam program|||||||
Misalkan isi array jadwal seperti ini:
INDEX   NAMA DOKTER     JAM MULAI
0       Dr. Andi        08:30
1       Dr. Budi        08:15
Nilai variabel saat j = 0
jadwal[0].jamMulai     = 8
jadwal[0].menitMulai  = 30

jadwal[1].jamMulai    = 8
jadwal[1].menitMulai = 15
Evaluasi kondisi:
8 > 8 (salah)
8 == 8 {benar}
dan
30 > 15 (benar)
Kondisi if bernilai TRUE
Akibatnya:
Dokter Andi dan Budi ditukar, karena Budi lebih pagi.

|||||||kesimpulan sederhana|||||||
kode if ini artinya:
Jika jadwal dokter sekarang lebih lambat dari dokter berikutnya,
maka tukar posisinya


=-=-=-=-=-=-=-=-=-=-= penjelasan temp =  jadwal[j];                  =-=-=-=-=-=-=-=-=-=-=
                                        jadwal[j] = jadwal[j + 1];
                                        jadwal[j + 1] = temp; 
|||||||Tujuan kode ini|||||||
Kode ini berfungsi untuk:
- menukar posisi dua jadwal dokter
karena urutannya salah (dokter yang lebih lambat ada di depan).
Dalam bubble sort:
- jadwal[j] = data kiri
- jadwal[j+1] = data kanan
Kalau kiri lebih lambat, maka ditukar.

|||||||Kenapa harus pakai temp?|||||||
Karena:
- Kalau langsung menimpa data → data lama bisa hilang
- temp dipakai sebagai penyimpanan sementara
Analoginya ada di penjelasan di atas tentang variabel temp.

|||||||Isi data dalam program (contoh nyata)|||||||
Sebelum ditukar
INDEX       NAMA DOKTER         SPESIALIS       JAM MULAI
0           Dr. Andi            Umum            09:30
1           Dr. Budi            Gigi            08:45
Karena:
09:30 lebih lambat dari 08:45
- posisi salah, harus ditukar
Nilai variabel saat itu:
jadwal[j]     = jadwal[0]  // Dr. Andi (09:30)
jadwal[j + 1] = jadwal[1]  // Dr. Budi (08:45)

|||||||Baris 1: temp = jadwal[j];|||||||
Artinya:
- Simpan data jadwal[j] ke variabel sementara
Isi temp sekarang:
temp.nama        = "Dr. Andi"
temp.spesialis   = "Umum"
temp.jamMulai    = 9
temp.menitMulai = 30
temp.jamSelesai = ...
temp menyimpan 1 data dokter secara lengkap

|||||||Baris 2: jadwal[j] = jadwal[j + 1];|||||||
Artinya:
- Isi jadwal kiri diganti dengan jadwal kanan
=>sekarang jadwal[0] = jadwal[1];
Isi jadwal[0] berubah jadi:
INDEX       NAMA DOKTER     JAM
0           Dr. Budi        08:45
Data Dr. Andi sementara hilang dari array,
tapi masih aman di temp.

|||||||Baris 3: jadwal[j + 1] = temp;|||||||
Artinya:
- Isi posisi kanan diisi dengan data lama yang disimpan di temp
Sekarang:
jadwal[1] = temp;  // Dr. Andi
Isi array setelah pertukaran:
INDEX       NAMA DOKTER           JAM MULAI
0           Dr. Budi              08:45
1           Dr. Andi              09:30

|||||||Visual alur singkat|||||||
sebelum swap:
[j]     = Dr. Andi (09:30)
[j + 1] = Dr. Budi (08:45)
proses swap:
temp ← Dr. Andi
jadwal[j] ← Dr. Budi
jadwal[j + 1] ← temp
sesudah swap:
[j]     = Dr. Budi (08:45)
[j + 1] = Dr. Andi (09:30)

|||||||Kesimpulan|||||||
Kode ini artinya:
"Kalau urutan jadwal salah, simpan dulu data kiri ke temp,
geser data kanan ke kiri,
lalu taruh data lama ke kanan"