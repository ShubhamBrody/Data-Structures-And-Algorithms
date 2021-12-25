#include<bits/stdc++.h>
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

void topsortgraph(vector<int> g[], int V, int E)
{
    bool visited[V];
    stack<int> st;

    for(int i = 0; i < V; i++)
    visited[i] = false;

    for(int i = 0; i < V; i++){
        if(!visited[i])
        topsortutils(g, st, visited, i);
    }

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<int> g[V];

    for(int i = 0; i < V; i++){
        int A, B;
        cin >> A >> B;
        g[A].push_back(B);
    }

    topsortgraph(g, V, E);
}