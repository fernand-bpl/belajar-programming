#include <iostream>
#include <string>
#include <iomanip>
#include <limits> // untuk std::numeric_limits

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

void tampilData(Mahasiswa mhs) {
    cout << "\n===== Data Mahasiswa Tersimpan =====" << endl;
    cout << left << setw(15) << "Nama" << ": " << mhs.nama << endl;
    cout << left << setw(15) << "NIM"  << ": " << mhs.nim << endl;
    cout << left << setw(15) << "IPK"  << ": " << mhs.ipk << endl;
    cout << fixed << setprecision(2) << mhs.ipk << endl;
    cout << "====================================" << endl;
}

int main() {
    const int JUMLAH = 2;     
    Mahasiswa mhs[JUMLAH];

    for(int i = 0; i < JUMLAH; i++) {
        cout << "===== Input Data Mahasiswa " << (i + 1) << " =====" << endl;
        cout << "Input Nama: ";
        getline(cin, mhs[i].nama);
        cout << "Input NIM: ";
        cin >> mhs[i].nim;
        cout << "Input IPK: ";
        cin >> mhs[i].ipk;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for(int i = 0; i < JUMLAH; i++) {
        tampilData(mhs[i]);
    }

    return 0;
}
