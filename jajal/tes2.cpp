#include <iostream>
#include <limits>
using namespace std;    
int main(){
    //=====BILANGAN BULAT=====
    int a = 1;// 4 byte atau 32 bit
    long b = 6;
    short c = 9; //2 byte atau 16 bit
    
    //=====BILANGAN DESIMAL=====
    float d = 1.0;
    double e = 2.5;

    //=====CHARACTER=====
    char f = 'A'; //character 1-bite
    //STRING BUKAN TIPE DATA FUNDAMENTAL DI C++ TAPI SERING DIGUNAKAN
    //string nama = "Fernand";

    //=====BOOLEAN=====
    bool g = true; // true/false 



    //kalau ingin mengeta hui ukuran tipe data
    //sizeof(nama_tipe_data)   
    cout << a << "\n"; 
    cout << sizeof(a) << " byte" << "\n";
    /*
    nilai ram yang dibutuhkan oleh variabel a adalah 4 byte pada umumnya
    1 byte = 8 bit
    */
    cout << numeric_limits<unsigned int>::max() << "\n"; // untuk mengetahui nilai maksimum dari tipe data int
    cout << numeric_limits<unsigned int>::min() << "\n"; // untuk mengetahui nilai minimum dari

    return 0;
}