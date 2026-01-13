#include <iostream>
using namespace std;

int main () {
    const int max = 10;
    int stack[max];
    int top = -1;
    int pilihan;
    int nilai;

    do {
        cout << "\n======================================\n";
        cout << "          Menu Tumpukan (Stack)          ";
        cout << "\n======================================\n";
        cout << "|" << "1. Push (Tambah Data)               |\n";
        cout << "|" << "2. Pop (Hapus Data)                 |\n";
        cout << "|" << "3. Peek (Lihat Data Teratas         |\n";
        cout << "|" << "4. Tampilkan Isi Stack              |\n";
        cout << "|" << "5. Keluar                           |\n";
        cout << "======================================\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: // Tambah Data (Push)
                if (top == max - 1) {
                    cout << "Stack Penuh, tidak bisa di Push\n";
                } else {
                    cout << "Masukan Nilai: ";
                    cin >> nilai;
                    top++;
                    stack[top] = nilai;
                    cout << "Data " << nilai << " Berhasil di Tambahkan\n";
                }
                break;

            case 2: // Hapus Data (Pop)
                if (top == -1) {
                    cout << "Stack Kosong, tidak ada data yang bisa dihapus\n";
                } else {
                    cout << "Data yang diPop adalah: " << stack[top] << endl;
                    top--;
                }
                break;

            case 3: // Lihat Data Teratas (Peek)
                if (top == -1) {
                    cout << "Stack Kosong\n";
                } else {
                    cout << "Data Teratas adalah: " << stack[top] << endl;
                }
                break;

            case 4: // Tampilkan Keseluruhan Isi Stack
                if (top == -1) {
                    cout << "Stack Kosong\n";
                } else {
                    cout << "Isi Stack dari atas ke Bawah: \n";
                    for (int p = top; p >= 0; p--) {
                        cout << stack[p] << " ";
                    }
                    cout << endl;
                }
                break;

            case 5: // Keluar
                cout << "Keluar dari program...\n";
                break;

            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
                break;
        }


    } while (pilihan != 5);

    return 0;
}