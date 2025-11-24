#include <iostream>
using namespace std;
int main() {
    int data[] = {64, 25, 12, 22, 11, 1};
    int n = sizeof(data) / sizeof(data[0]);
    int temp;

    cout<<"nilai n = "<<n<<endl;
    
    //menampilkan data
    cout<<"Data sebelum di urutkan: ";
    for(int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    //algoritma sorting (bubble sort)
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(data[j] > data[j+1]){
                //proses pertukaran
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
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