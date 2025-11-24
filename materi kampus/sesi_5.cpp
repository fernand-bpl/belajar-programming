#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int batas;
    cout<<"masukan batas array = ";
    cin>>batas;
    int arr[batas];
    int x;
    for(int i=0; i<batas; i++){
        cout<<"masukan elemen ke-"<<i<<" = ";
        cin>>arr[i];
    }

    cout<<"Masukan elemen yang ingin di cari: ";
    cin>>x;

    int low = 0, high = batas - 1;
    int pos;
    bool found = false;

    while (low <= high && x >= arr[low] && x <= arr[high]){
        if(arr[low] == arr[high]){
            if(arr[low] == x){
                cout<<"Elemen ditemukan pada index ke-"<<low<<endl;
            }
            else{
                cout<<"Elemen tidak ditemukan."<<endl;
            }
            found = true;
            break;
        }
        pos = low + (((x - arr[low]) * (high - low)) / (arr[high] - arr[low]));
        
        if(arr[pos] == x){
            cout<<"Elemen ditemukan pada index ke-"<<pos<<endl;
            found = true;
            break;
        }
        else if(arr[pos] < x){
            low = pos + 1;
        }
        else{
            high = pos - 1;
        }
    }

    if (!found){
        cout<<"Elemen tidak ditemukan."<<endl;
    }
    return 0;
}