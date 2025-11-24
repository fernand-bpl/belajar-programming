#include <iostream>//insertion sort descending
using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    // Proses Insertion Sort Descending
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) { // < untuk descending
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // key dimasukkan ke posisi yang tepat

        cout << "Step " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil pengurutan (descending): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
