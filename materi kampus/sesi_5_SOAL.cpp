#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int arr[10] = {44,42,35,33,31,27,26,19,14,10};
    int x;

    cout<<"Masukan elemen yang ingin di cari: ";
    cin>>x;

    int low = 0, high = 10 - 1;
    int pos;
    bool found = false;

    while (low <= high && x <= arr[low] && x >= arr[high]){
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
        pos = low + (((arr[low] - x) * (high - low)) / (arr[low] - arr[high]));
        
        if(arr[pos] == x){
            cout<<"Elemen ditemukan pada index ke-"<<pos<<endl;
            found = true;
            break;
        }
        else if(arr[pos] > x){
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