#include <iostream>
using namespace std;

const int MAX = 100;

string plat[MAX], jenis[MAX];
int jamMasuk[MAX];
int jumlah = 0;

void kendaraanMasuk() {
    if (jenis >= MAX) {
        cout << "Parkiran Penuh!";
        return;
    }

    cout << "\n========== Kendaraan Masuk ==========\n";
    cout << "Plat Nomor: ";
    cin.ignore();
    cin >> plat[jumlah];
    cout << "Jenis (motor/mobil): ";
    cin >> jenis[jumlah];
    cout << "Jam Masuk: ";
    cin >> jamMasuk[jumlah];
    
    jumlah++;
    cout << "Kendaraan Berhasil Masuk!";
    
}
