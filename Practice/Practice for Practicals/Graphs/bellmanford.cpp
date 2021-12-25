#include <bits/stdc++.h>
using namespace std;
#define INF 999999

struct cmp{
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return p1.second > p2.second;
    }
};

void bellmanford(vector<vector<pair<int, int>>> g, int src, int e) {
    int n = g.size();
    vector<int> dist(n, INF);
    vector<bool> V(n, false);
    dist[src] = 0;

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n; j++){
            for(auto node : g[j])
            {
                if(dist[node.first] > dist[j] + node.second){
                    dist[node.first] = dist[j] + node.second;
                }
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

    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m ;i++){
        int a,b,w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
    }

    bellmanford(g, 0, m);
}