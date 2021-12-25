#include<bits/stdc++.h>
using namespace std;
int n;

void topsortutil(vector<int> g[], vector<int> &st, vector<bool> &V, int curr)
{
    if(V[curr]) return;
    V[curr] = true;
    for(int node : g[curr])
    {
        topsortutil(g, st, V, node);
    }

    st.push_back(curr);
}

void topsort(vector<int> g[])
{
    vector<int> st; // to be used as a stack
    vector<bool> V(n, false);

    for(int i = 0; i < n; i++) {
        if(!V[i]) {
            topsortutil(g, st, V, i);
        }
    }

    for(int i = st.size()-1; i >= 0; i--)
    {
        cout << st[i] << " ";
    }
}

int main() {
    int m;
    cin >> n >> m;
    vector<int> g[n];

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    topsort(g);
}