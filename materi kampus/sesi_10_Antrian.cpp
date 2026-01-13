#include <iostream>
using namespace std;
int main () {
    const int max = 10; // ukuran maksimum queue
    int queue[max]; // array untuk menyimpan elemen queue
    int front = 0; // selalu 0 karena kita akan menggeser elemen saat dequeue
    int rear = 0; // indeks untuk menambahkan elemen baru
    int pilihan, nilai;

    do {
        cout << "\n======================================\n";
        cout << "               Menu QUEUE                 ";
        cout << "\n======================================\n";
        cout << "|" << "1. Enqueue (Tambah data)            |\n";
        cout << "|" << "2. Dequeue (Hapus data)             |\n";
        cout << "|" << "3. Peek (Lihat data depan)          |\n";
        cout << "|" << "4. Tampilkan Isi queue              |\n";
        cout << "|" << "5. Keluar                           |\n";
        cout << "|" << "6. Mengembalikan isi queue          |\n";
        cout << "======================================\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: // enqueue (Tambah Data)
                if (rear == max) {
                    cout << "Queue penuh! Tidak bisa enqueue.\n";
                } else {
                    cout << "Masukan Nilai: ";
                    cin >> nilai;
                    queue[rear] = nilai;
                    rear++;
                    cout << "Data " << nilai << " Berhasil di Tambahkan\n";
                }
                break;

            case 2: // dequeue (Hapus Data)
                if (rear == 0) {
                    cout << "Queue Kosong, tidak bisa dequeue\n";
                } else {
                    cout << "Data yang di-dequeue: " << queue[0] << endl;
                    
                    // geser semua elemen ke kiri
                    for (int i = 1; i < rear; i++) {
                        queue[i - 1] = queue[i];
                    }
                    rear--;
                }
                break;

            case 3: // peek
                if (rear == 0) {
                    cout << "Queue Kosong\n";
                } else {
                    cout << "Elemen terdepan: " << queue[0] << endl;
                }
                break;

            case 4: // tampilkan isi queue
                if (rear == 0) {
                    cout << "Queue Kosong!\n";
                } else {
                    cout << "Isi queue dari depan ke belakang: \n";
                    for (int i = 0; i < rear; i++) {
                        cout << queue[i] << " ";
                    }
                    cout << endl;
                }
                break;
            
            case 5: // Keluar
                cout << "Keluar dari program...\n";
                break;

            case 6: // Mengembalikan isi queue
                if (rear == 0) {
                    cout << "Queue Kosong! Tidak bisa dibalik.\n"; 
                }
                else {
                    int temp [max];
                    int t = 0;

                    // membalik queue ke temp
                    for (int i = rear - 1; i >= 0; i--) {
                        temp[t] = queue[i];
                        t++;
                    }

                    // mengembalikan dari temp ke queue
                    for (int i = 0; i < t; i++) {
                        queue[i] = temp[i];
                    }
                    cout << "Isi queue berhasil dibalik.\n";
                }
                break;

            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
                break;
        }

    } while (pilihan != 5);

    return 0;
}