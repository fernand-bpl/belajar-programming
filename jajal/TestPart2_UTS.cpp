#include <iostream>
using namespace std;
int main(){
    int n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    char arr[n];

    cout<<"==============================="<<endl;
    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> arr[i];
    }
    int key, j;

    cout<<"Batasan Jumlah Array: "<<n<<endl;
    cout<<"========================="<<endl;
    cout<<"Data sebelum di urutkan: "<<endl;
    

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"=========================="<<endl;

    //proses insertion sort
    for(int i=1; i<n; i++){
        key = arr[i];
        j = i - 1;
        

        //geser elemen yang lebih besar ke kanan
        while(j >= 0 && arr[j] < key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        
        cout<<"Step "<<i<<": ";
        for(int k=0; k<n; k++){ 
            cout<<arr[k]<<" ";
        }           
        cout<<endl;

    }
    cout<<endl;
    cout<<"Data setelah di urutkan (Ascending): "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    bool ditemukan = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == cari) {
            cout << "\nElemen ditemukan pada indeks ke-" << i << " \n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nElemen tidak ditemukan dalam array.\n";
    }

    


    return 0;
}