#include <bits/stdc++.h>
using namespace std;
#define INF 999999

struct cmp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) { 
        return p1.second > p2.second;
    }
};

void dijkstra(vector<vector<pair<int, int>>> g, int src)
{
    int n = g.size()/2;
    vector<int> dist(n, INF);
    // vector<int> vis(n, false);
    dist[src] = 0;
    // vis[src] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, dist[src]});

    while(!pq.empty()) {
        int idx = pq.top().first;pq.pop();
        // vis[idx] = true;
        for(auto e : g[idx])
        {
            if(dist[e.first] > dist[idx] + e.second)
            {
                dist[e.first] = dist[idx]+e.second;
                pq.push({e.first, dist[e.first]});
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << i << " --> " << dist[i] << endl;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(2*n);
    for(int i = 0; i < m ;i++){
        int a,b,w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    dijkstra(g, 0);
}

// 9 14
// 0 1 4
// 0 7 8
// 1 7 11
// 1 2 8
// 7 8 7
// 7 6 1
// 2 8 2
// 8 6 6
// 2 3 7
// 2 5 4
// 6 5 2
// 3 5 14
// 3 4 9
// 5 4 10