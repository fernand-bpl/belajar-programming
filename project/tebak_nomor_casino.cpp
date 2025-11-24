#include <iostream>
#include <string> // Diperlukan untuk menggunakan string
#include <cstdlib> // Diperlukan untuk menggunakan angka acak
#include <ctime>
using namespace std;

void tampilkanAturan();
int main()
{
    string namaPemain;
    int saldo; // Menyimpan saldo pemain
    int jumlahTaruhan;
    int tebakan;
    int dadu; // Menyimpan angka acak
    char pilihan;
    srand(time(0)); // "Menginisialisasi" generator angka acak
        cout << "\n\t\t========SELAMAT DATANG DI DUNIA KASINO FERNANDO=======\n\n";
        cout << "\n\nSiapa Nama Anda: ";
    getline(cin, namaPemain);
        cout << "\n\nMasukkan saldo awal untuk bermain: $";
        cin >> saldo;
    do

    {
        system("cls");
        tampilkanAturan();
            cout << "\n\nSaldo Anda saat ini adalah $ " << saldo << "\n";
        // Dapatkan jumlah taruhan pemain
        do
        {
                cout << "Hey, " << namaPemain<<", masukkan jumlah taruhan Anda : $";
                cin >> jumlahTaruhan;
            if(jumlahTaruhan > saldo)
                cout << "Saldo taruhan tidak boleh melebihi saldo saat ini!\n"
                        <<"\nMasukkan jumlah taruhan kembali\n ";
        }while(jumlahTaruhan > saldo);
       // Dapatkan tebakan pemain
        do
        {
                cout << "Tebak angka taruhan antara 1 & 10 :";
                cin >> tebakan;
            if(tebakan <= 0 || tebakan > 10)
                cout << "\nAngka harus antara 1 hingga 10\n"
                    <<"Masukkan angka kembali:\n ";
        }while(tebakan <= 0 || tebakan > 10);
        dadu = rand()%10 + 1;
        if(dadu == tebakan)
        {
            cout << "\n\nAnda beruntung!! Anda memenangkan Rp." << jumlahTaruhan * 10;
            saldo = saldo + jumlahTaruhan * 10;
        }

        else
        {
            cout << "Oops, semoga beruntung lain kali !! Anda kehilangan $ "<< jumlahTaruhan <<"\n";
            saldo = saldo - jumlahTaruhan;
        }
            cout << "\nAngka pemenang adalah : " << dadu <<"\n";
            cout << "\n"<<namaPemain<<", Saldo Anda sekarang adalah $ " << saldo << "\n";

        if(saldo == 0)
        {
            cout << "Anda tidak memiliki uang untuk bermain ";
            break;
        }
            cout << "\n\n-->Apakah Anda ingin bermain lagi (y/n)? ";
            cin >> pilihan;
    }while(pilihan =='Y'|| pilihan=='y');
    cout << "\n\n\n";
    cout << "\n\nTerima kasih telah bermain. Saldo Anda sekarang adalah $ " << saldo << "\n\n";
    return 0;
}

void tampilkanAturan()
{
    system("cls");
    cout << "\t\t======ATURAN TEBAK ANGKA DI KASINO FERNANDO!======\n";
    cout << "\t1. Pilih angka antara 1 hingga 10\n";
    cout << "\t2. Pemenang akan mendapatkan 10 kali lipat dari uang taruhan\n";
    cout << "\t3. Jika tebakan salah, Anda kehilangan jumlah yang Anda pertaruhkan\n\n";
}