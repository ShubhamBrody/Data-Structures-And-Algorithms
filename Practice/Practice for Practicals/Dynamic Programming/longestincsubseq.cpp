#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> V(n);
    for(int &v : V)
    cin >> v;

    vector<int> a;
    a.push_back(V[0]);

    for(int i = 1; i < n; i++){
        if(V[i] > a.back())
        {
            a.push_back(V[i]);
        }
        else
        {
            int idx = lower_bound(a.begin(), a.end(), V[i])-a.begin();
            a[idx] = V[i];
        }
    }

    cout << a.size();

}