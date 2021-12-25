#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> T(n);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        T[i] = {a, b};
    }

    sort(T.begin(), T.end());
    int count = 0;
    int maxt;
    vector<bool> V(n, false);
    int k = 0;

    while(k != T.size())
    {
        maxt = -1;
        for(int i = 0; i < n; i++){
            if(!V[i] && T[i].first >= maxt)
            {
                V[i] = true;
                k++;
                maxt = max(T[i].second, maxt);
            }
        }
        count++;
    }

    cout << count;
}