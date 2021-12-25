#include<bits/stdc++.h>
using namespace std;
#define INF 99999
#define pb push_back

int scc = 0;
int id = 0;

void tarjansutil(vector<int> g[], vector<bool> &vt, vector<int> &ids, vector<int> &low, vector<int> &st, vector<int> &sccs, int curr) {
    ids[curr] = low[curr] = id++;
    vt[curr] = true;
    st.pb(curr);
    for(int node : g[curr])
    {
        if(ids[node] == -1)
        tarjansutil(g, vt, ids, low, st, sccs, node);
        if(vt[node])
        low[curr] = min(low[node], low[curr]);
    }
    if (ids[curr] == low[curr]) {
        cout << "SCC-" << scc << endl;
      while(st.size()) {
          int val = st.back();
        st.pop_back();
        vt[val] = false;
        sccs[val] = scc;
        cout << val <<" ";
        if (val == curr) break;
      }
      cout << endl;
      scc++;
    }
}

int tarjanAlgo(vector<int> g[], int n)
{
    vector<int> ids(n, -1);
    vector<int> low(n);
    vector<int> sccs(n);
    vector<int> st;
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++){
        if(ids[i] == -1)
        {
            tarjansutil(g, vis, ids, low, st, sccs, i);
        }
    }
    cout << "Links are : " << endl;
    for(int i = 0; i < n; i++){
        cout << low[i];
    }
}

int main(){
    int n, m;
    cout << "Input the number of vertices : " << endl;
    cin >> n >> m;

    vector<int> g[n];
    while(m--)
    {
        int i, j;
        cin >> i >> j;
        g[i].pb(j);
    }
    tarjanAlgo(g, n);
}