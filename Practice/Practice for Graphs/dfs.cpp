#include<bits/stdc++.h>
using namespace std;

void dfscalc(vector<vector<int>> g, int start)
{
    static vector<int> V(g.size(), false);
    if(!V[start])
    {
        V[start] = true;
        cout << start << endl;
        for(int i = 0; i < g[start].size(); i++){
            if(g[start][i] && !V[i])
            dfscalc(g, i);
        }
    }
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
    dfscalc(g, start);
}