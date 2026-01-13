#include <iostream>
using namespace std;
int faktorial(int n) {
    int hasil = 1;
    for (int i = 1; i <= n; i++) {
        hasil *= i;
    }
    return hasil;
}

int main () {
    cout << "Program Iteratif\n";
    cout << "================\n";
    int n;
    cout << "Masukkan bilangan: ";
    cin >> n;

    cout << "Faktorial (iteratif) = "
        << faktorial(n) << endl;
}