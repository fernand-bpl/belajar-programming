/*Latihan menggabungkan SJF Non-Preempretive dan SJF Preempretive 
dengan menggunakan switch case*/
#include <iostream>
using namespace std;
int main(){
    int pilihan;

    do {
        cout << "\n=== MENU PENJADWALAN CPU ===\n";
        cout << "1. Preemptive\n";
        cout << "2. Non-Preemptive\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if(pilihan == 3){
            cout << "Selesai.\n";
            break;
        }

        int n = 4;
        int p[4]  = {2,1,3,2};
        int at[4] = {0,2,4,5};
        int bt[4] = {7,4,1,4};

        int ct[4], tat[4], wt[4];

        switch(pilihan){
        // 1. SRTF (PREEMPTIVE)
        case 1: {
            int rt[4];
            for(int i=0;i<n;i++) rt[i] = bt[i];
            int t = 0, completed = 0;

            while(completed < n){
                int idx = -1;
                int mn = 9999;

                for(int i=0;i<n;i++){
                    if(at[i] <= t && rt[i] > 0 && rt[i] < mn){
                        mn = rt[i];
                        idx = i;
                    }
                }
                if(idx == -1){
                    t++;
                    continue;
                }

                rt[idx]--;
                t++;

                if(rt[idx] == 0){
                    ct[idx] = t;
                    completed++;
                }
            }
            break;
        }

        // 2. SJF NON-PREEMPTIVE
        case 2: {
            int done[4] = {0,0,0,0};
            int t = 0, completed = 0;

            while(completed < n){
                int idx = -1;
                int mn = 9999;

                for(int i=0;i<n;i++){
                    if(at[i] <= t && done[i] == 0 && bt[i] < mn){
                        mn = bt[i];
                        idx = i;
                    }
                }
                if(idx == -1){
                    t++;
                    continue;
                }

                t += bt[idx];
                ct[idx] = t;

                done[idx] = 1;
                completed++;
            }
            break;
        }
        case 3:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            continue;
        }

        // HITUNG TAT & WT (SAMA UNTUK SEMUA)
        cout << "\n=== HASIL PERHITUNGAN ===\n";
        for(int i=0;i<n;i++){
            tat[i] = ct[i] - at[i];
            wt[i]  = tat[i] - bt[i];

            cout << "p" << p[i]
                << " | CT=" << ct[i]
                << " | TAT=" << tat[i]
                << " | WT=" << wt[i] << endl;
        }

    } while(pilihan != 3);

    return 0;
}
