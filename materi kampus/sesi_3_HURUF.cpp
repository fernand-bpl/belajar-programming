#include <iostream>
using namespace std;    
int main(){
    string A [10]={"Fernand","Fernand1","Fernand2","Fernand3","Fernand4","Fernand5","Fernand6","Fernand7","Fernand8","Fernand9"};
    int f=0, temp;
    string data;

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