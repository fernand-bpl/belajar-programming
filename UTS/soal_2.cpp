#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int arr[n];
    cout << "\nSilahkan Inputkan Elemen-elemen Array \n";
    for (int y = 0; y < n; y++) {
        cout << "Inputkan Elemen Array indeks ke-" << y << " : ";
        cin >> arr[y];
    }

    cout << "==========================================\n";
    cout << "Elemen-elemen Array Sebelum diurutkan:\n";
    for (int y = 0; y < n; y++) {
        cout << arr[y] << " ";
    }
    cout << "\n==========================================\n";
    cout << "\n";

    //Proses Insertion Sort (Ascending)
    for (int y = 1; y < n; y++) {
        int key = arr[y];
        int z = y - 1;

        while (z >= 0 && arr[z] > key) {
            arr[z + 1] = arr[z];
            z = z - 1;
        }
        arr[z + 1] = key;

        cout << "Hasil pengurutan step-" << y + 1 << " : ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil pengurutan (Ascending): ";
    for (int y = 0; y < n; y++) {
        cout << arr[y] << " ";
    }
    cout << "\n==========================================\n";

    //Pencarian Data dengan Binary Search 
    int cari;
    cout << "\nInputkan Data yang Ingin Dicari : ";
    cin >> cari;

    int low = 0, high = n - 1, mid;
    int f = 0; 

    while (low <= high) {
        mid = (low + high) / 2;

        if (cari == arr[mid]) {
            cout << "Angka ditemukan pada indeks ke-" << mid << " : " << arr[mid] << endl;
            f = 1;
            break;
        }
        else if (cari < arr[mid]) {
            high = mid - 1; 
        }
        else {
            low = mid + 1; 
        }
    }

    if (f == 0) {
        cout << "Data tidak ditemukan!" << endl;
    }
    return 0;
}