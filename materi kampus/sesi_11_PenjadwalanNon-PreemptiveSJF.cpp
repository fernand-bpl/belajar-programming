#include <iostream>

using namespace std;
int main(int argc, char** argv){
    int n =4;
    int p[4] = {1,2,3,4};
    int at[4] = {0,1,2,3};
    int bt[4] = {6,8,7,3};

    int done[4] = {0,0,0,0};
    int ct[4], tat[4], wt[4];

    int t=0;
    int completed = 0;

    while(completed < n){
        int idx = -1;
        int mn= 9999;

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

    for(int i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        cout << "p" << p[i] 
                << " ct: " << ct[i]
                << " tat: " << tat[i]
                << " wt= " << wt[i] << endl;
    }
    return 0;
}