#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Dokter {
    string nama;
    string spesialis;
    int jamMulai, menitMulai;
    int jamSelesai, menitSelesai;
};

const int MAX = 50; 
Dokter jadwal[MAX]; 
int jumlah = 0;

// Tambah jadwal dokter
void tambahJadwal() {
    if (jumlah >= MAX) {
        cout << "Jadwal penuh!\n";
        return;
    }

    cout << "\n=== Tambah Jadwal Dokter ===\n";
    cin.ignore();

    cout << "Nama Dokter  : ";
    getline(cin, jadwal[jumlah].nama);

    cout << "Spesialis    : ";
    getline(cin, jadwal[jumlah].spesialis);

    cout << "Jam Mulai (HH MM): ";
    cin >> jadwal[jumlah].jamMulai >> jadwal[jumlah].menitMulai;

    cout << "Jam Selesai (HH MM): ";
    cin >> jadwal[jumlah].jamSelesai >> jadwal[jumlah].menitSelesai;

    jumlah++;

    cout << "Jadwal berhasil ditambahkan!\n";
}

// Tampilkan seluruh jadwal dokter
void tampilkanJadwal() {
    if (jumlah == 0) {
        cout << "Belum ada jadwal dokter!\n";
        return;
    }

    cout << "\n============ Daftar Jadwal Dokter ============\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << jadwal[i].nama
            << " | Spesialis: " << jadwal[i].spesialis
            << " | ";

        // Format HH:MM
        cout << setw(2) << setfill('0') << jadwal[i].jamMulai << ":"
            << setw(2) << setfill('0') << jadwal[i].menitMulai << " - "
            << setw(2) << setfill('0') << jadwal[i].jamSelesai << ":"
            << setw(2) << setfill('0') << jadwal[i].menitSelesai << endl;
    }
}

// Sorting berdasarkan jam mulai (Bubble Sort)
void bubbleSortJam() {
    Dokter temp;  // variabel sementara untuk proses pertukaran

    // algoritma bubble sort
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {

            // Bandingkan jam terlebih dahulu
            if (jadwal[j].jamMulai > jadwal[j + 1].jamMulai ||
            (jadwal[j].jamMulai == jadwal[j + 1].jamMulai &&
                jadwal[j].menitMulai > jadwal[j + 1].menitMulai)) {

                // proses pertukaran 
                temp = jadwal[j]; 
                jadwal[j] = jadwal[j + 1];
                jadwal[j + 1] = temp;
            }
        }
    }

    cout << "Jadwal berhasil diurutkan berdasarkan jam!\n";
}

// Program utama
int main() {
    int pilihan;

    do {
        cout << "\n============ MENU PENJADWALAN DOKTER ============\n";
        cout << "1. Tambah Jadwal Dokter\n";
        cout << "2. Tampilkan Jadwal Dokter\n";
        cout << "3. Urutkan Jadwal Dokter Berdasarkan Jam\n";
        cout << "4. Kembali\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahJadwal(); break;
            case 2: tampilkanJadwal(); break;
            case 3: bubbleSortJam(); break;
            case 4: cout << "Program selesai...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 4);

    return 0;
}