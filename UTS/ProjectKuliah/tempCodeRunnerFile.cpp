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