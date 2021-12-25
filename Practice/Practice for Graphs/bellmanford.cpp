#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define PPIII pair<pair<int, int>, int>
#define pb push_back

int calcMin(vector<int> dist, vector<bool> sptSet)
{
    int min = INF, minIdx = -1;
    for (int i = 0; i < dist.size(); i++)
    {
        if (!sptSet[i] && dist[i] < min)
        {
            min = dist[i];
            minIdx = i;
        }
    }

    return minIdx;
}

void bellmanford(vector<vector<int>> g, int src, int n)
{
    int e = g.size();
    vector<int> dist(n, INF);
    vector<bool> sptSet(n, false);

    dist[src] = 0;

    for(int i = 0; i < n; i++){
        for(int i = 0; i < e; i++){
            if(dist[g[i][0]] != INF && dist[g[i][1]] > dist[g[i][0]] + g[i][2])
            {
                dist[g[i][1]] = dist[g[i][0]] + g[i][2];
            }
                
        }
    }
    
    cout << "The answer is :" << endl;

    for(int i = 0; i < n; i++){
        cout << i << "  --->  " << dist[i] << endl;
    }

}

int main()
{
    int n; // number of vertices
    cin >> n;

    int m;
    cin >> m; // number of edges

    vector<vector<int>> g;
    for (int I = 0; I < m; I++)
    {
        int i, j, a;
        cin >> i >> j >> a;
        g.pb({i, j, a});
    }

    int src;
    cin >> src;

    bellmanford(g, src, n);
}


// 5
// 8
// 0 1 -1
// 0 2 4
// 1 2 3
// 1 3 2
// 1 4 2
// 3 2 5
// 3 1 1 
// 4 3 -3
// 0