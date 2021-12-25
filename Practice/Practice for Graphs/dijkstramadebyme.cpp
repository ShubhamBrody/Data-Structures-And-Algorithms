#include <bits/stdc++.h>
using namespace std;
#define INF 99999

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

void dijkstra(vector<vector<int>> g, int src)
{
    int n = g.size();
    vector<int> dist(n, INF);
    vector<bool> sptSet(n, false);

    dist[src] = 0;

    for (int i = 0; i < n; i++)
    {
        int idx = calcMin(dist, sptSet);
        sptSet[idx] = true;
        for(int j = 0;j < n; j++){
            if(!sptSet[j] && g[idx][j] && dist[idx] != INF && dist[j] > g[idx][j] + dist[idx])
            dist[j] = g[idx][j] + dist[idx];
        }

    }
    cout << "The answer is :" << endl;

    for(int i = 0; i < n; i++){
        cout << i << "  --->  " << dist[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(9, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    int src;
    cin >> src;

    dijkstra(g, src);
}