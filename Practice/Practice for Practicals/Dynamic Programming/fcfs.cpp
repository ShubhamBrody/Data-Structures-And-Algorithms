#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> bt(20), wt(20), tat(20), p(0);
    int n;
    cin >> n;
    n = n%21;

    for(int i = 0 ; i < n; i++) {
        cin >> bt[i];
    }

    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(bt[j] < bt[min])
            min = j;
        }
    }
}