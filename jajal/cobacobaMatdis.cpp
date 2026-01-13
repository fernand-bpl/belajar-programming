#include <iostream>
using namespace std;

const int MAX = 100;

string plat[MAX], jenis[MAX];
int jamMasuk[MAX];
int jumlah = 0;

void kendaraanMasuk() {
    if (jumlah >= MAX) {
        cout << "Parkiran Penuh!!";
        return;
    }

    cout << "\n========== Kendaraan Masuk ==========\n";
    cout << "Plat Nomor: ";
    cin.ignore();
    getline(cin, plat[jumlah]);
    cout << "Jenis (motor/mobil): ";
    cin >> jenis[jumlah];
    cout << "Jam Masuk (0-23): ";
    cin >> jamMasuk[jumlah];

    jumlah++;
    cout << "Kendaraan Berhasil Masuk!!\n";
}

void kendaraanKeluar() {
    string cariPlat;
    int jamKeluar;

    cout << "\n========== Kendaraan Keluar ==========\n";
    cout << "Masukkan Plat Nomor: ";
    cin.ignore();
    getline(cin, cariPLat);

    for (int i = 0; i < jumlah; i++) {
        if (plat[i] == cariPlat) {
            cout << "Jam Keluar (0-23): ";
            cin >> jamKeluar;

            int lamaParkir;
            lamaParkir = jamKeluar - jamMasuk[i];
            if (lamaParkir < 1)
                lamaParkir = 1;

            int biaya;
            if (jenis[i] == "motor")
                biaya = lamaParkir * 2000;
            else
                biaya = lamaParkir * 5000;

            cout << "Lama parkir: " << lamaParkir << " Jam\n";
            cout << "Biaya parkir: Rp" << biaya << endl;

            for ()
        }
    }



}