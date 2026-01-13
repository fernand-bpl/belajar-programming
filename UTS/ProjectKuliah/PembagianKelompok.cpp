#include <iostream>
using namespace std;

const int MAX = 100;

string plat[MAX], jenis[MAX];
int jamMasuk[MAX];
int jumlah = 0;

void kendaraanMasuk() {
    if (jumlah >= MAX) {
        cout << "Parkiran penuh!\n";
        return;
    }

    cout << "\n=== Kendaraan Masuk ===\n";
    cout << "Plat Nomor: ";
    cin.ignore();
    getline(cin, plat[jumlah]);
    cout << "Jenis (motor/mobil): ";
    cin >> jenis[jumlah];
    cout << "Jam Masuk (0-23): ";
    cin >> jamMasuk[jumlah];

    jumlah++;
    cout << "Kendaraan berhasil masuk!\n";
}

void kendaraanKeluar() {
    string cariPlat;
    int jamKeluar;

    cout << "\n=== Kendaraan Keluar ===\n";
    cout << "Masukkan plat nomor: ";
    cin.ignore();
    getline(cin, cariPlat);

    for (int i = 0; i < jumlah; i++) {
        if (plat[i] == cariPlat) {
            cout << "Jam Keluar (0-23): ";
            cin >> jamKeluar;

            int lamaParkir = jamKeluar - jamMasuk[i];
            if (lamaParkir < 1)
                lamaParkir = 1;

            int biaya;
            if (jenis[i] == "motor")
                biaya = lamaParkir * 2000;
            else
                biaya = lamaParkir * 5000;

            cout << "Lama parkir : " << lamaParkir << " jam\n";
            cout << "Biaya parkir: Rp" << biaya << endl;

            // Hapus data (geser array)
            for (int j = i; j < jumlah - 1; j++) {
                plat[j] = plat[j + 1];
                jenis[j] = jenis[j + 1];
                jamMasuk[j] = jamMasuk[j + 1];
            }

            jumlah--;
            return;
        }
    }
    cout << "Kendaraan tidak ditemukan!\n";
}

int main() {
    int pilihan;

    do {
        cout << "\n=== SISTEM PARKIR ===\n";
        cout << "1. Kendaraan Masuk\n";
        cout << "2. Kendaraan Keluar\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: kendaraanMasuk(); break;
            case 2: kendaraanKeluar(); break;
            case 3: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan salah!\n";
        }

    } while (pilihan != 3);

    return 0;
}