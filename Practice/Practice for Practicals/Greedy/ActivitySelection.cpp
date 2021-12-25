#include<bits/stdc++.h>
using namespace std;
#define pb push_back
struct cmp{
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return p1.first < p2.first;
    }
};

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> V;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        V.pb({a, b});
    }

    // for(int i = 0; i < n; i++){
    //     cout << V[i].first << " " << V[i].second << endl;
    // }

    sort(V.begin(), V.end());
    // reverse(V.begin(), V.end());

    cout << endl;

    for(int i = 0; i < n; i++){
        cout << V[i].first << " " << V[i].second << endl;
    }

    int maxt, count = 0, k = 0;
    vector<bool> vis(n, false);

    while(k<n)
    {
        count++;
        maxt = -1;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i] && V[i].first >= maxt)
            {
                vis[i] = true;
                k++;
                maxt = max(V[i].second, maxt);
            }
        }
    }

    cout << "The count of processes is : " << count;
}