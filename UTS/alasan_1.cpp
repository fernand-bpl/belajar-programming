=>menggunakan linear search
=>kenapa tidak menggunakan binary search dan interpolation search
    "JENIS SEARCH"      "BISA DIPAKAI UNTUK HURUF"      "SYARAT"                "KETERANGAN"
    linear search       bisa                            tidak perlu urut        sangat cocok
    binary search       bisa                            harus diurutkan dulu    bisa kalau data sort 
    interpolation s     tidak disarankan                data numerik&terurut    tidak cocok

=>contoh codingan jika memakai binary search
--->[contoh data belum di urutkan]
#include <iostream>
using namespace std;

int main() {
    string arr[] = {"u", "a", "k"};  // data acak, tidak urut
    int n = 3;

    string cari = "u";
    int low = 0, high = n - 1;
    bool ditemukan = false;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == cari) {
            cout << "Elemen ditemukan pada indeks ke-" << mid << endl;
            ditemukan = true;
            break;
        } else if (arr[mid] < cari) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!ditemukan)
        cout << "Elemen tidak ditemukan.\n";

    return 0;
}

--->[contoh data sudah di urutkan]
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string arr[] = {"a", "k", "u"};  // sudah diurutkan
    int n = 3;

    string cari = "u";
    int low = 0, high = n - 1;
    bool ditemukan = false;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == cari) {
            cout << "Elemen ditemukan pada indeks ke-" << mid << endl;
            ditemukan = true;
            break;
        } else if (arr[mid] < cari) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!ditemukan)
        cout << "Elemen tidak ditemukan.\n";

    return 0;
}





=>penjelasaan jawaban soal 1

#include <iostream>
using namespace std;

int main() {
    int n;//menampung jumlah elemen Array yang di inputkan oleh user
    cout << "Masukkan jumlah elemen: ";
    cin >> n;//membaca input dari user dan memasukannya ke dalam var n

    string arr[n];//menyimpan semua elemen yang di inputkan oleh user

    cout << "\nSilahkan Inputkan Elemen-elemen Array \n";// pake 
    for (int i = 0; i < n; i++) {//for mengulangi proses sebanyak n kali
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

