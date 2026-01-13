#include <iostream>
using namespace std;
int faktorialRekursif(int n) {
    if (n == 0)
        return 1;
    else
        return n * faktorialRekursif(n - 1);
}
int main () {

    cout << "Program Rekursif\n";
    cout << "================\n";
    int n;
    cout << "Masukkan bilangan: ";
    cin >> n;

    cout << "Faktorial (rekursif) = "
        << faktorialRekursif(n) << endl;
}