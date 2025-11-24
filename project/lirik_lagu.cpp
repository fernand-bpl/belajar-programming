#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;

void animate_text(const string& text, double delay, const string& color) {
    cout<<color; //set warna
    for (char c : text) {
        cout<< c <<flush;
        this_thread::sleep_for(chrono::duration<double>(delay));
    }
    cout<<"\033[0m"<<endl; //reset warna
}

int main() {
    vector<string> lyrics = {
        
        "Tante...",
        "Sudah terbiasa terjadi tante...",
        "Tenang datang cuma kalo butuh saja",
        "Coba kalau lagi susah",
        "Mereka semua menghilaaaaaaaaaaaaaaaaaaaaaaaaang",
        "Tante...",
    };

    vector<string> colors = {
        "\033[31m", // Merah
        "\033[32m", // Hijau
        "\033[33m", // Kuning
        "\033[34m", // Biru 
        "\033[35m", // Magenta
        "\033[36m"  // Cyan
    };

    vector<double> speeds = {0.08, 0.09, 0.08,0.08, 0.09, 0.08};
        vector<double> delays = {0.3, 1.5, 1.0, 0.5, 1.3, 0.3};

    for (int i = 0; i < lyrics.size(); ++i) {
    this_thread::sleep_for(chrono::duration<double>(delays[i])); // jeda sebelum animasi
    animate_text(lyrics[i], speeds[i], colors[i % colors.size()]);
    }

    return 0;
}
    