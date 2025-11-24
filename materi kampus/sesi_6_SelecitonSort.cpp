#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;
    int data[n]; // membuat array dengan ukuran sesuai input

    cout << "Masukkan elemen data: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> data[i];
    }
    int temp, minIndex;

    cout<<"nilai n = "<<n<<endl;
    
    //menampilkan data
    cout<<"Data sebelum di urutkan: ";
    for(int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    //algoritma sorting (selection sort)
    for(int i = 0; i < n-1; i++){
        minIndex = i;
        for(int j = i+1; j < n; j++){
            if(data[j] < data[minIndex]){
                minIndex = j;
            }
        }
        temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
        
        cout<<endl<<"Step "<<i+1<<": ";
        for(int k = 0; k < n; k++) {
            cout << data[k] << " ";
        }
        cout << endl;
    }

    //menampilkan data setelah di urutkan
    cout<<endl<<"Data setelah di urutkan: ";
    for(int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout<<endl;

    return 0;
}