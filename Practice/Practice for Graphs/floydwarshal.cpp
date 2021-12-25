#include<bits/stdc++.h>
using namespace std;
#define INF 99999

void floyddwarshal(vector<vector<int>> &g)
{
    for(int k = 0; k < g.size(); k++) {
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g.size(); j++){
                if(g[j][k] && g[j][i] && g[i][k] && g[j][k] > g[j][i] + g[i][k]) 
                {
                    g[j][k] = g[j][i]+g[i][k];
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, INF));

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        g[x][y] = w;
    }

    floyddwarshal(g);

    cout << "New matrix : \n";

    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}