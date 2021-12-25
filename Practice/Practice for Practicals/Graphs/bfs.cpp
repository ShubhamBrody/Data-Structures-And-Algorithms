#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for(int i = 0; i < m ;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    queue<int> q;
    vector<bool> v(n, false);
    q.push(0);
    v[0] = true;
    while(!q.empty()){
        int node = q.front(); q.pop();
        cout << node << endl;
        for(int nn : g[node]){
            if(!v[nn])
            {
                q.push(nn);
                v[nn] = true;
            }
        }
    }
}