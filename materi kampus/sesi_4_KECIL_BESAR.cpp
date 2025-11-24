#include <iostream>
using namespace std;    
int main(){

    int n;
    cout << "Masukan jumlah elemen array: ";
    cin >> n;
    int num[n];

    int x,f,low,high,mid;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    

    cout<<"          Binary Search          "<<endl;
    cout<<"================================="<<endl;

    cout<<"Masukan Nilai yang ingin dicari: ";
    cin>>x;

    f = 0;

    low = 0;
    high = n - 1;

    while(low <= high){
        mid = (low + high)/2;

        if(x == num[mid]){
            cout<<"data ditemukan, pada index ke-"<<mid;
            f = 1;
            break;
        }
        
        else if(x < num[mid]){
        high = mid - 1;
    }
        else if(x > num[mid]){
        low = mid + 1;
    }
    }
    if(f == 0){
        cout<<"data tidak ditemukan!";
    }
    return 0;
}