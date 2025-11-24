#include <iostream>
using namespace std;    
int main(){

    int num [] = {15, 29, 30, 32, 43, 75, 98};
    int x,f,low,high,mid;

    cout<<"          Binary Search          "<<endl;
    cout<<"================================="<<endl;

    cout<<"Masukan Nilai yang ingin dicari";
    cin>>x;

    f = 0;

    low = 0;
    high = 6;

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