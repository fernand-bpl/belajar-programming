#include <iostream>

using namespace std;
int main(int argc, char** argv){
    int n = 4; // number of processes
    int p[4] = {1,2,3,4}; // process IDs
    int at[4] = {0,1,2,3}; // arrival times 
    int bt[4] = {6,8,7,3}; // burst times

    int rt[4]; 
    for(int i=0;i<n;i++) rt[i] = bt[i];

    int ct[4], tat[4], wt[4];
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

    for(int i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        cout << "p" << p[i] 
                << " ct=" << ct[i]
                << " tat=" << tat[i]
                << " wt=" << wt[i] << endl;
    }
    return 0;
}