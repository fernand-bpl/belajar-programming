#include <iostream> // menyediakan objek input/output seperti cin, cout.
#include <string> // menyediakan tipe std::string.
#include <iomanip> // menyediakan manipulators untuk formatting output, contohnya setw() dan setfill().
using namespace std; // biar kamu tidak perlu menulis std:: di depan cout, string, dll.

struct Dokter {
    string nama;
    string spesialis;
    int jamMulai, menitMulai;
    int jamSelesai, menitSelesai;
};

const int MAX = 50; 
/*-MAX adalah konstanta integer bernilai 50.
-Const berarti nilainya tidak bisa diubah selama program berjalan.

Kenapa Lebih Baik Pakai const bukan int?
Karena:
-Ukuran array tidak sengaja berubah ➝ terhindar
-Compiler lebih aman dan kompatibel
-Sesuai standar C++
-Program lebih mudah dibaca: “Oh angka ini tidak boleh diubah.”*/
Dokter jadwal[MAX]; 
/*-Membuat array berukuran MAX (50 elemen).
-Jadwal = kotak panjang berisi 50 slot,
-Setiap slot berisi 1 kartu data dokter.*/
int jumlah = 0;
/*-Jadi jumlah selalu menunjukkan berapa dokter yang sudah terisi serta index berikutnya yang kosong.
-Jumlah dimulai dari 0.*/

/*nama ketiga variabel di atas adalah global variables
Variabel global adalah variabel yang dideklarasikan di luar fungsi mana pun, termasuk di luar main().
-Cocok digunakan untuk data yang dipakai banyak fungsi, seperti array jadwal, counter, konfigurasi, dll.
-Digunakan untuk menyimpan data yang perlu dipakai oleh banyak fungsi dalam program.*/

// Tambah jadwal dokter
void tambahJadwal() {
    if (jumlah >= MAX) {
        /*-jumlah= Berapa banyak data dokter yang sudah tersimpan
        -MAX= Kapasitas maksimal array (50 data)*/
        cout << "Jadwal penuh!\n";
        return;
        /*KENAPA PAKAI RETURN:
        Artinya keluar dari fungsi dan menghentikan proses penambahan.
        Jika tidak ada return, program akan tetap berjalan dan akan mencoba menulis data baru ke:
        jadwal[50]
        Padahal index array hanya sampai:
        jadwal[0] sampai jadwal[49]
        Itu akan menyebabkan crash, error, atau data acak (undefined behavior).*/
    }

    cout << "\n=== Tambah Jadwal Dokter ===\n";
    cin.ignore();
    /*Sebelum masuk ke tambahJadwal(), program Anda melakukan input angka: cin >> pilihan;
    Setelah user mengetik angka, misalnya: 1⏎
    Maka "cin >> pilihan" hanya mengambil angka “1”, tetapi tidak mengambil karakter Enter (⏎).
    Karakter Enter ini berubah menjadi newline ('\n') dan masih tertinggal di buffer input.

    Akibatnya, ketika getline() dipanggil: getline(cin, jadwal[jumlah].nama);
    "getline" melihat ada '\n' yang tertinggal, menganggap itu adalah akhir input, dan langsung berhenti.
    Hasilnya: nama menjadi string kosong tanpa user mengetik apa pun.*/

    cout << "Nama Dokter  : ";
    getline(cin, jadwal[jumlah].nama);
    /*"getline" adalah fungsi input dalam C++ yang digunakan untuk membaca 
    satu baris penuh teks yang diketik user, termasuk spasi.
    "jadwal[jumlah.nama]" menyimpannya ke member "nama" dari elemen array jadwal pada indeks jumlah.*/

    cout << "Spesialis    : ";
    getline(cin, jadwal[jumlah].spesialis);

    cout << "Jam Mulai (HH MM): ";
    cin >> jadwal[jumlah].jamMulai >> jadwal[jumlah].menitMulai;
    /*=>Membaca dua nilai integer dari input standar (cin) dan menyimpannya ke:
    -jadwal[jumlah].jamMulai (angka jam)
    -jadwal[jumlah].menitMulai (angka menit)
    =>Cara baca: cin >> melewati whitespace (spasi/newline) dan membaca sampai token 
    berikutnya yang bukan angka. Jadi user bisa mengetik 8 30 atau 08 30 lalu Enter.
    =>Tipe data: kedua field adalah int, sehingga input non-angka (huruf) akan membuat cin 
    gagal (state fail) dan nilai variabel tidak berubah, perlu penanganan error.*/

    cout << "Jam Selesai (HH MM): ";
    cin >> jadwal[jumlah].jamSelesai >> jadwal[jumlah].menitSelesai;

    jumlah++;
    /*=>Dalam konteks programmu:
    -jumlah menyimpan jumlah data dokter yang sudah ada di array jadwal[].
    -Setiap kali pengguna menambah satu jadwal baru, data jadwal disimpan di indeks:
    "jadwal[jumlah]"
    -Setelah data pada indeks tersebut selesai diisi, kita harus memindahkan indeks ke elemen berikutnya, supaya:
    ✔ Data berikutnya tidak menimpa data lama
    ✔ Program tahu bahwa jumlah data bertambah satu
    Artinya, tanpa jumlah++, program akan terus mengisi di indeks yang sama, sehingga data sebelumnya tertimpa.
    =>KESIMPULANNYA:
    -jumlah++ = menandai bahwa satu jadwal baru telah berhasil ditambahkan, dan mempersiapkan indeks berikutnya untuk input selanjutnya.
    =>TANPA jumlah++:
    -Input 1:
    jadwal[0] = Dokter A
    -Input 2:
    jadwal[0] = Dokter B (dokter A hilang)
    -Input 3:
    jadwal[0] = Dokter C (dokter B hilang)*/

    cout << "Jadwal berhasil ditambahkan!\n";
}

// Tampilkan seluruh jadwal dokter
void tampilkanJadwal() {
    if (jumlah == 0) { /*
        -jumlah adalah variabel global yang menyimpan berapa banyak jadwal dokter yang sudah terisi.
        -Kondisi jumlah == 0 berarti belum ada data sama sekali (array kosong/ belum ada input).*/
        cout << "Belum ada jadwal dokter!\n";
        return; /*
        -return; menghentikan fungsi lebih awal (early exit).
        -Dengan jumlah == 0, return mencegah bagian tampil dieksekusi.
        -return meningkatkan kejelasan dan keamanan pemeliharaan, jadi lebih baik dipertahankan.*/
    }

    cout << "\n============ Daftar Jadwal Dokter ============\n";
    for (int i = 0; i < jumlah; i++) {
        /*
        =>"int i"= inisialisasi penghitung i mulai dari 0.
        i dipakai sebagai indeks untuk mengakses elemen array jadwal.
        =>"i < jumlah"= kondisi loop: selama i lebih kecil dari jumlah, blok di dalam loop dijalankan.
        -jumlah adalah variabel global yang menyimpan berapa banyak entri jadwal yang terisi.
        -Ini membuat loop berjalan tepat sebanyak entri yang ada (0..jumlah-1).
        =>"i++"= Jika jumlah = 3, i akan bernilai 0,1,2 — jadi akan mengakses jadwal[0], jadwal[1], jadwal[2].*/
        cout << i + 1 << ". " << jadwal[i].nama
        /*
        =>"i + 1"=Ini menampilkan nomor urut yang ramah manusia (1-based). Array pakai 0-based index, tapi untuk tampil kita biasanya mulai dari 1.
        Contoh: jika i = 0 → tampil 1, jika i = 1 → tampil 2, dst.
        =>"<< jadwal[i].nama"= Mengambil elemen i dari array jadwal (tipe Dokter) lalu mengakses field nama (tipe string), menulis nama dokter ke console.*/
            << " | Spesialis: " << jadwal[i].spesialis
            // =>"<< " | Spesialis: " << jadwal[i].spesialis"= Menambahkan separator | lalu label Spesialis: lalu isi field spesialis dari jadwal[i].
            << " | ";

        // Format HH:MM
        cout << setw(2) << setfill('0') << jadwal[i].jamMulai << ":"
            << setw(2) << setfill('0') << jadwal[i].menitMulai << " - "
            << setw(2) << setfill('0') << jadwal[i].jamSelesai << ":"
            << setw(2) << setfill('0') << jadwal[i].menitSelesai << endl;
            /*
            bagian itu bertanggung jawab memformat tampilan jam/menit supaya selalu muncul dalam 
            bentuk HH:MM (dua digit untuk jam, dua digit untuk menit), mis. 09:05 bukan 9:5.
            -setw(2) → atur lebar minimal 2 karakter untuk nilai berikutnya.
            -setfill('0') → gunakan karakter '0' untuk mengisi bila kurang lebar; sifatnya bertahan sampai diubah.
            -(2) berarti dua posisi karakter; ('0') berarti pakai karakter nol sebagai pengisi.*/
    }
}

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

// Program utama
int main() {
    int pilihan; // variabel untuk menyimpan pilihan menu yang dimasukkan user.

    do {
        cout << "\n============ MENU PENJADWALAN DOKTER ============\n";
        cout << "1. Tambah Jadwal Dokter\n";
        cout << "2. Tampilkan Jadwal Dokter\n";
        cout << "3. Urutkan Jadwal Dokter Berdasarkan Jam\n";
        cout << "4. Kembali\n";
        cout << "Pilih menu: ";
        cin >> pilihan; 
        /*
        -do { ... } artinya program akan menjalankan isi menu setidaknya satu kali, meskipun user belum memilih apapun.
        -Program menampilkan menu pilihan untuk user.
        -User memasukkan angka (1–4) ke variabel pilihan.*/

        switch (pilihan) {
            case 1: tambahJadwal(); break;
            case 2: tampilkanJadwal(); break;
            case 3: bubbleSortJam(); break;
            case 4: cout << "Program selesai...\n"; break;
            /*Kalau tidak ada break, maka:
            -Program cek case 2 → cocok
            MENJALANKAN tampilkanJadwal()
            -Lalu langsung lanjut ke case 3
            MENJALANKAN bubbleSortJam()
            -Lanjut lagi ke case 4
            MENAMPILKAN "Program selesai..."
            -Lanjut terus sampai selesai
            Padahal user hanya memilih 2*/
            default: cout << "Pilihan tidak valid!\n"; // Jika user masukin angka selain 1–4, muncul pesan "Pilihan tidak valid!".
        }

    } while (pilihan != 4);
    /*Artinya:
    -Program akan terus mengulang menu
    -kecuali user memilih angka 4
    -Jika pilihan == 4 → perulangan berhenti → program ditutup*/

    return 0;
}