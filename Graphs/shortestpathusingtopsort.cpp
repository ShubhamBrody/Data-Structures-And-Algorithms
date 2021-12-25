#include<bits/stdc++.h>
#define INF 999999
using namespace std;

void topsortutils(vector<int> g[], stack<int> &st, bool *visited, int i)
{
    visited[i] = true;
    for(int j = 0; j < g[i].size(); j++){
        if(!visited[g[i][j]]){
            topsortutils(g, st, visited, g[i][j]);
        }
    }

    st.push(i);
}

vector<int> topsortgraph(vector<int> g[], int V, int E)
{
    bool visited[V];
    stack<int> st;

    for(int i = 0; i < V; i++)
    visited[i] = false;

    for(int i = 0; i < V; i++){
        if(!visited[i])
        topsortutils(g, st, visited, i);
    }

    vector<int> topsort;

    while(!st.empty())
    {
        topsort.push_back(st.top());
        st.pop();
    }
    return topsort;
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<int> g[V];
    vector<int> w[V];

    for(int i = 0; i < E; i++){
        int A, B, C;
        cin >> A >> B >> C;
        g[A].push_back(B);
        w[A].push_back(C);
    }

    vector<int> topsorted = topsortgraph(g, V, E);
    vector<int> shortestpath(V, INF);
    shortestpath[topsorted[0]] = 0;

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < g[i].size(); j++)
        {
            shortestpath[g[i][j]] = min(shortestpath[g[i][j]], shortestpath[i]+w[i][j]);
        }
    }

    for(int i:shortestpath)
    cout << i << " ";
}