#include <bits/stdc++.h>
using namespace std;
#define INF 999999
#define PPIII pair<pair<int, int>, int>

struct cmp{
    bool operator()(PPIII p1, PPIII p2) {
        return p1.second > p2.second;
    }
};

void prims(vector<vector<pair<int, int>>> g, int src)
{
    int n = g.size()/2;
    // vector<int> dist(g.size(), INF);
    vector<bool> V(n, false);
    priority_queue<PPIII, vector<PPIII>, cmp> pq;
    vector<int> P(n, -1);
    V[src] = true;
    for(auto e : g[src])
    {
        pq.push({{src, e.first}, e.second});
    }

    while(!pq.empty())
    {
        PPIII nt = pq.top();pq.pop();
        if(V[nt.first.second]) continue;
        V[nt.first.second] = true;
        P[nt.first.second] = nt.first.first;
        for(auto e : g[nt.first.second])
        {
            if(!V[e.first])
            pq.push({{nt.first.second, e.first}, e.second});
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << P[i] << " : parent of : " << i << endl;
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
    prims(g, 0);
}