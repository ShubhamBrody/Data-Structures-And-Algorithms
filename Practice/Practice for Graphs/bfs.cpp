#include<bits/stdc++.h>
using namespace std;

void bfscalc(vector<vector<int>> g, int node)
{
    vector<bool> V(g.size(), false);
    queue<int> Q;
    Q.push(node);
    V[node] = true;
    int take = 0;
    cout << "At level : " << take << endl << node << endl;

    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        cout << "At level : " << ++take << endl;
        for(int i = 0; i < g[curr].size(); i++){
            if(g[curr][i] == 1 && !V[i]){
                cout << i << endl;
                Q.push(i);
                V[i] = true;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }

    int start;
    cin >> start;

    bfscalc(g, start);
}