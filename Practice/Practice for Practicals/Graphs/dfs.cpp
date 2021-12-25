#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> g, int i = 1)
{
    static vector<bool> vis(g.size(), false);
    vis[i] = true;
    cout << i << endl;
    for(int node : g[i]) {
        if(!vis[node])
        {
            dfs(g, node);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for(int i = 0; i < m ;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    dfs(g, 2);
}