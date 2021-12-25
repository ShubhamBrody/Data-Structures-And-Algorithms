#include <bits/stdc++.h>
using namespace std;
#define INF 99999

struct comp
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
};

void dijkstra(vector<vector<int>> g, int src)
{
    int n = g.size();
    vector<int> dist(n, INF);
    vector<bool> sptSet(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> Q;

    dist[src] = 0;
    Q.push({src, dist[src]});
    int kk = 0;

    while (!Q.empty())
    {
        int idx = Q.top().first;
        Q.pop();
        sptSet[idx] = true;
        for (int j = 0; j < n; j++)
        {
            if (!sptSet[j] && g[idx][j] && dist[idx] != INF && dist[j] > g[idx][j] + dist[idx])
            {
                dist[j] = g[idx][j] + dist[idx];
                Q.push({j, dist[j]});
            }
        }
    }
    cout << "The answer is :" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i << "  --->  " << dist[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n, 0));
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