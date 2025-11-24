#include <iostream>
using namespace std;
int main() {
    int A;

    cout<<"Progres Dasar Penjumlahan"<<endl;
    cout<<"========================="<<endl;

    cout<<"Masukkan Nilai A = ";
    cin>>A;

    if (A <= 100 && A >= 88){
        cout<<"Nilai anda adalah A dengan Nilai angka = "<<A<<endl;
    }
    else if (A <= 79 && A >= 65){
        cout<<"NIlai anda adalah B dengan Nilai angka = "<<A<<endl;
    }
    else if (A <= 64 && A >= 50){
        cout<<"NIlai anda adalah C dengan Nilai angka = "<<A<<endl;
    }
    else if (A <= 49 && A >= 30){
        cout<<"NIlai anda adalah D dengan Nilai angka = "<<A<<endl;
    }
    else if (A <= 29 && A >= 0){
        cout<<"NIlai anda adalah E dengan Nilai angka = "<<A<<endl;
    }
    else{
        cout<<"Erorr"<<endl;
    }

    return 0;

}