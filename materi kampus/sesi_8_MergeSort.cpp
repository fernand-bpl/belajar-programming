#include <iostream>
using namespace std;
int main () {
    int a[] = {12, 5, 30, 7, 20, 2, 99, 43, 32, 10};
    int n = sizeof(a) / sizeof(a[0]);

    int z = 1;
    int temp[n]; /*array sementara untuk penyimpanan data
                ubah menjadi char temp[n] untuk menjadikan input huruf
                */

    // tampilkan data sebelum diurutkan
    cout << "================================" << endl;
    cout << "Data sebelum diurutkan: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    // proses pengurutan dengan merge sort
    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2*size) {
            int mid = left + size - 1;
            int right = left + 2*size - 1;
            
            if (mid >= n) {
                mid = n - 1;
            }
            if (right >= n) {
                right = n - 1;
            }

            int i = left; // data sebelah kiri
            int j = mid + 1; // data bagian tengah
            int k = left; // data temp atau penyimpanan semantara

            while (i <= mid && j <= right) {
                if (a[i] < a[j]) { // ubah < menjadi > untuk urutan terbesar ke yang terkecil
                    temp[k++] = a[i++];
                }
                else {
                    temp[k++] = a[j++];
                }
            }
            
            while (i <= mid) {
                temp[k++] = a[i++];
            }
            while (j <= right) {
                temp[k++] = a[j++];
            }

            // salin hasil merge ke array asli
            for (int p = left; p <= right; p++) {
                a[p] = temp[p];
            }
            
        }
    // step merge sort
    cout<<endl<<"Step ke-" << z << ": ";
    for(int i = 0; i < n; i++) {
    cout << a[i] << " ";
    }
    cout<<endl;
    z = z + 1;
    }

    
    // tampilan data sesudah diurutkan
    cout << endl << "================================" << endl;
    cout << "Data sesudah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}