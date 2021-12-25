#include <bits/stdc++.h>
using namespace std;
#define INF 99999
int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(n, INF));
    vector<vector<int>> oldg(n);
    for(int i = 0; i < m ;i++){
        int a,b,w;
        cin >> a >> b >> w;
        oldg[a].push_back(b);
        g[a][b] = w;
    }

    for(int k = 0; k < n; k++){
        g[k][k] = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                 if(g[i][j] > g[i][k]+g[k][j])
                 g[i][j] = g[i][k]+g[k][j];
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }


}