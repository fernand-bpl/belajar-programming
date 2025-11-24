#include <iostream>
using namespace std;    
int main(){
    int A [10]={100,10,90,20,80,30,70,40,60,50};
    int data, f=0, temp;

    cout<<"Data yang ingin dicari: ";
    cin>>data;

    for(int i=0; i<10; i++){
        if(data == A[i]){
            f = 1;
            temp = i;
        }
    }

    if (f == 0){
        cout<<"Data tidak ditemukan"<<endl;
    }
    else if(f == 1){
        cout<<"Data ditemukan pada index ke-"<<temp<<endl;
    }

    return 0;


}