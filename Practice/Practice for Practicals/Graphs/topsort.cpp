#include <bits/stdc++.h>
using namespace std;

void topsortutil(vector<vector<int>> g, vector<bool> &V, stack<int> &st, int i) {
    if(V[i]) return;
    V[i] = true;
    for(int node : g[i])
    topsortutil(g, V, st, node);
    st.push(i);
}

void topsort(vector<vector<int>> g)
{
    vector<bool> V(g.size(), false);
    stack<int> st;

    for(int i = 0; i < g.size(); i++){
        if(!V[i]) topsortutil(g, V, st, i);
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for(int i = 0; i < m ;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    topsort(g);
}