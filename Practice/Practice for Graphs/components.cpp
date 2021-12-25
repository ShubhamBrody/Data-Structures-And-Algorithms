#include<bits/stdc++.h>
using namespace std;

void dfsutil(vector<vector<int>> g, vector<bool> &used, vector<int> &comp, int start)
{
    comp.push_back(start);
    used[start] = true;
    for(int i = 0; i < g[start].size(); i++){
        if(g[start][i] && !used[i])
        dfsutil(g, used, comp, i);
    }
}

int componentcounter(vector<vector<int>> g, int n)
{
    vector<bool> used(n, false);
    vector<int> comp;
    int components = 0;
    for(int i = 0; i < n; i++){
        if(!used[i])
        {
            comp.clear();
            dfsutil(g, used, comp, i);
            cout << "Component : \n";
            for(int node : comp)
            {
                cout << node << " ";
            }
            components++;
            cout << endl;
        }
    }

    return components;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            cin >> g[i][j];
        }
    }
    int start;
    cin >> start;
    int compo = componentcounter(g, start);
    cout << "Total components : " << compo;
}