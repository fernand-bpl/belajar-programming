#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    string arr[n];

    cout << "\nSilahkan Inputkan Elemen-elemen Array \n";
    for (int z = 0; z < n; z++) {
        cout << "Inputkan Elemen Array indeks ke-" << z << " : ";
        cin >> arr[z];
    }

    cout << "=========================================\n";
    cout << "Elemen-elemen Array:\n";
    for (int z = 0; z < n; z++) {
        cout << arr[z] << " ";
    }
    cout << "\n=========================================\n";

    string cari;
    cout << "Masukkan elemen yang ingin dicari: ";
    cin >> cari;

    int f = 0; 

    for (int z = 0; z < n; z++) {
        if (arr[z] == cari) {
            cout << "\nElemen ditemukan pada indeks ke-" << z << endl;
            f = 1; 
            break;
        }
    }

    if (f == 0) { 
        cout << "\nElemen tidak ditemukan dalam array.\n";
    }

    return 0;
}