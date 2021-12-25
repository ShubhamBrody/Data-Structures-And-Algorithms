#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> J(n);
    int maxt = -1;

    for(int i = 0; i < n; i++){
        int p, t;
        cin >> p >> t;
        J[i] = {p, t};
        if(maxt < t)
        maxt = t;
    }
    vector<bool> T(maxt+1, false);
    sort(J.begin(), J.end());
    reverse(J.begin(), J.end());
    int maxP = 0;
    for(int i = 0; i < n; i++){
        int k = J[i].second;
        while((k > 0) && T[k]){
            k--;
        }
        if(k > 0)
        {
            T[k] = true;
            maxP += J[i].first;
        }
    }
    cout << maxP;
}