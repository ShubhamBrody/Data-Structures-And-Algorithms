#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> ids;
vector<int> low;
vector<bool> ap;
vector<int> par;
int id = 0;

void dfs(vector<int> g[], int curr)
{
    ids[curr] = low[curr] = id++;
    int children = 0;
    for(int node : g[curr])
    {
        if(ids[node] == -1) // unvisited
        {
            children++;
            par[node] = curr;
            dfs(g, node);
            low[curr] = min(low[curr], low[node]);

            if(par[curr]==-1 && children > 1) // case-1 root node and has more than 1 children
            ap[curr] = true;

            if(par[curr]!=-1 && low[curr] < low[node])
            ap[curr] = true;
        }
        else if(par[curr]!=node)
        {
            low[curr] = min(low[curr], ids[node]);
        }
    }
}

void findAP(vector<int> g[], int n)
{
    ids.resize(n);
    low.resize(n);
    ap.resize(n);
    par.resize(n);
    fill(ids.begin(), ids.end(), -1);
    fill(ap.begin(), ap.end(), false);
    fill(par.begin(), par.end(), -1);

    for(int i = 0; i < n; i++)
    {
        dfs(g, i);
    }

    cout << "The Articulation Points are : \n";
    for(int i = 0; i < n; i++){
        if(ap[i])
        cout << i << " ";
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    findAP(g, n);
}