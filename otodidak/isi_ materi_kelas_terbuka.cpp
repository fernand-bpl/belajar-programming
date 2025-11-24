==============================Materi Pertemuan Ke 8==============================
------------------------------Deklarasi Variabel dan Input Output------------------------------
#include <iostream> 
using namespace std;
int main(){
    int a;
    a = 10;
    cout << a << "\n";

    int b;
    cout << "Masukkan nilai b: ";
    cin >> b;
    cout << "Nilai b adalah: ";
    cout << b << "\n";
    return 0;
}

==============================Materi Pertemuan Ke 9==============================
------------------------------Tipe Data Fundamental------------------------------
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

====================Materi Pertemuan Ke-10====================
--------------------Aritmatika--------------------
#include <iostream>
using namespace std;
int main() {
    int a = 6;
    int b = 4;
    
    int hasil;
    
    // operatornya +, - *, /, %
    
    // penjumlahan
    hasil = a + b;
        cout << a << " + " << b << " = " << hasil << endl;
    
    // pengurangan
    hasil = a - b;
        cout << a << " - " << b << " = " << hasil << endl;
    
    // perkalian
    hasil = a * b;
        cout << a << " x " << b << " = " << hasil << endl;
    
    // pembagian
    hasil = a / b;
        cout << a << " / " << b << " = " << hasil << endl;// jika mau hasilnya 1.5 maka ganti jadi "float a = 6 dan float = hasil" tetapi modulus jadi tidak bisa di run
    
     // modulus
    hasil = a % b;
        cout << a << " % " << b << " = " << hasil << endl;
    
    //urutan eksekusi
    hasil = (a + b) * a;
    cout << hasil << endl;
    return 0;
}

====================Materi Pertemuan Ke-11====================
--------------------Komparasi Untuk Boolean--------------------
#include <iostream>
using namespace std;
int main() {
    int a = 2;
    int b = 2;

    bool hasil1, hasil2;

// komparasi, relation expression

// sebanding ==
    hasil1 = (a == b);
   //tidak sebanding !=
    hasil2 = (a != b);

// kurang dari
    hasil1 = (a < b);
   // lebih dari
    hasil2 = (a > b);

    // kurang dari sama dengan
    hasil1 = (a <= b);
   // lebih dari sama dengan
    hasil2 = (a >= b);

    cout << hasil1 << endl;
    cout << hasil2 << endl;
    return 0;
}

====================Materi Pertemuan Ke-12====================
--------------------Operator Logika and Or dan Not--------------------
#include <iostream>
using namespace std;
int main() {
    int a = 3;
    int b = 2;

    bool hasil;
    //operatoe logika : not, and, or

    //NOT
    hasil = !(a == 3);

    //AND = kedua kondisi harus true
    cout << "====AND====\n";
    hasil = (a == 3) && (b == 2);//true and true = true
        cout << hasil << endl;
    hasil = (a == 4) && (b == 2);//false and true = false
        cout << hasil << endl;
    hasil = (a == 3) && (b == 3);//true and false = false
        cout << hasil << endl;
    hasil = (a == 4) && (b == 4);//false and false = false
        cout << hasil << endl;

    //OR = salah satu kondisi harus true
    cout << "====OR====\n";
    hasil = (a == 3) || (b == 2);//true and true = true
        cout << hasil << endl;
    hasil = (a == 4) || (b == 2);//false and true = true
        cout << hasil << endl;
    hasil = (a == 3) || (b == 3);//true and false = true
        cout << hasil << endl;
    hasil = (a == 4) || (b == 4);//false and false = false
        cout << hasil << endl;

    return 0;
}

====================Materi Pertemuan Ke-13====================
--------------------If Statement--------------------
#include <iostream>
using namespace std;
int main() {
    int a;
    cout << "masukan angka: ";
    cin >> a;

    // if statement
    // kondisi dlam bentuk boolean

    if (a < 3) {
        cout << "halo" << endl;
    }

    cout << "end" << endl;

    return 0;
}

====================Materi Pertemuan Ke-14====================
--------------------If Else--------------------
#include <iostream>
using namespace std;
int main() {
    int a;
    cout << "masukan angka: ";
    cin >> a;

    if (a == 5) {
        cout << "nilai ini adalah 5" << endl;
    } 
    else if (a == 3) {a
        cout << "nilai ini adalah 3" << endl;
    }
    else if (a == 1) {
        cout << "nilai ini adalah 1" << endl;
    }
    else {
        cout << "nilai ini bukan 3, 5, atau 1" << endl;
    }

    cout << "end" << endl;
    return 0;
}

====================Materi Pertemuan Ke-15====================
--------------------Switch Case--------------------
#include <iostream>
using namespace std;
int main() {
    int a;
    cout << "masukan nilai= ";
    cin >> a;

    switch(a) {
        case 1:
            cout << "a adalah 1" << endl;
            break;
        case 2:
            cout << "a adalah 2" << endl;
        case 3:
            cout << "a adalah 3" << endl;
        case 4:
            cout << "a adalah 4" << endl;
        case 5:
            cout << "a adalah 5" << endl;
        default:
            cout << "nilai a diluar jangkauan" << endl;
    }

    cout << "selesai" << endl;

    return 0;
}

====================Materi Pertemuan Ke-16====================
--------------------Latihan Membuat Kalkulator--------------------
#include <iostream>
using namespace std;
int main() {
    float a, b, hasil;
    char aritmatika;

    cout << "selamat datang di kalkulator sederhana" << endl;

    // memasukan input dari user
    cout << "masukan angka pertama: ";
    cin >> a;
    cout << "masukan operator (+, -, *, /): ";
    cin >> aritmatika;
    cout << "masukan angka kedua: ";
    cin >> b;

    cout << "\nhasil perhitungan: " ;
    cout << a << aritmatika << b;

    if (aritmatika == '+') {
        hasil = a + b;
    }
    else if (aritmatika == '-') {
        hasil = a - b;
    }
    else if (aritmatika == '/') {
        hasil = a / b;
    }
    else if (aritmatika == '*') {
        hasil = a * b;
    }
    else {
        cout << "operator yang anda masukan salah" << endl;
    }

    cout << " = " << hasil << endl;
    return 0;
}
--------------------Menggunakan Switch--------------------
#include <iostream>
using namespace std;
int main() {
    float a, b, hasil;
    char aritmatika;

    cout << "selamat datang di kalkulator sederhana" << endl;

    // memasukan input dari user
    cout << "masukan angka pertama: ";
    cin >> a;
    cout << "masukan operator (+, -, *, /): ";
    cin >> aritmatika;
    cout << "masukan angka kedua: ";
    cin >> b;

    cout << "\nhasil perhitungan: " ;
    cout << a << " " << aritmatika << " " << b;

    switch (aritmatika) {
    case '+':
        hasil = a + b;
        break;
    case '-':
        hasil = a - b;
        break;
    case '/':
        hasil = a / b;  
        break;
    case '*': 
        hasil = a * b;
        break;
    default:
        cout << "operator yang anda masukan salah" << endl;
    }
    

    cout << " = " << hasil << endl;
    return 0;
}

====================Materi Pertemuan Ke-17====================
--------------------Operator Assigment--------------------
#include <iostream>
using namespace std;
int main() {
    // assigment
    int a = 10;
    cout << "nilai awal dari a adalah: " << a << endl; 

    // assigment operator
    // variabel = variabel operator nilai
    //   a.     =      a      -      3
    // variabel operator= nilai
    //   a         +=       3
    a += 3;
    cout << "ditambah 3 menjadi: " << a << endl;
    a -= 3;
    cout << "dikurangi 3 menjadi: " << a << endl;
    a /= 3;
    cout << "dibagi 3 menjadi: " << a << endl;\
    a %= 3;
    cout << "dimodulo 3 menjadi: " << a << endl;
    
    return 0;
}
====================Materi Pertemuan Ke-18====================
--------------------Increment dan Decrement--------------------
#include <iostream>
using namespace std;
int main() {
    // increment dan decrement
    // preincrement dan postincrement
    
    int a = 10;
    int b = 10;
    
    // postincrement
    cout << a << endl;
    cout << a++ << endl;
    cout << a << endl << endl;

    // preincrement
    cout << b << endl;
    cout << ++b << endl;
    cout << b << endl;

    // dicrement
    cout << a << endl;
    cout << a-- << endl;
    cout << a << endl << endl;

    // predecrement
    cout << b << endl;
    cout << --b << endl;
    cout << b << endl;
    
    return 0;
}

====================Materi Pertemuan Ke-19====================
--------------------m--------------------


====================Materi Pertemuan Ke-20====================
--------------------m--------------------


====================Materi Pertemuan Ke-21====================
--------------------m--------------------


====================Materi Pertemuan Ke-22====================
--------------------m--------------------
