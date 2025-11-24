#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    string arr[n];

    cout << "\nSilahkan Inputkan Elemen-elemen Array \n";
    for (int i = 0; i < n; i++) {
        cout << "Inputkan Elemen Array indeks ke-" << i << " : ";
        cin >> arr[i];
    }

    cout << "=========================================\n";
    cout << "Elemen-elemen Array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n=========================================\n";

    string cari;
    cout << "Masukkan elemen yang ingin dicari: ";
    cin >> cari;

    bool ditemukan = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == cari) {
            cout << "\nElemen ditemukan pada indeks ke-" << i << " \n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nElemen tidak ditemukan dalam array.\n";
    }

    return 0;
}
