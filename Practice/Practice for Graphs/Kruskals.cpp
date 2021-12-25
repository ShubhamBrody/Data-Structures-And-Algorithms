#include<bits/stdc++.h>
using namespace std;
#define PPIII pair<pair<int, int>, int>

struct comp{
    bool operator()(PPIII p1, PPIII p2){
        return p1.second > p2.second;
    }
};

int parfind(vector<int> &sets, int i)
{
    while(sets[i] != -1)
    {
        i = sets[i];
    }

    return i;
}

void unioncalc(vector<int> &sets, int i, int j)
{
    int pi = parfind(sets, i);
    int pj = parfind(sets, j);
    sets[pi] = pj;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n, 0));
    // I, J, Value;
    priority_queue<PPIII, vector<PPIII>, comp> Q;
    vector<int> sets(n, -1);
    vector<int> rank(n, 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
        {
            cin >> g[i][j];
            if(j > i && g[i][j])
            {
                Q.push({{i, j},g[i][j]});
            }
        }
    }

    vector<PPIII> gnew;
    vector<bool> used(n, false);

    while(!Q.empty()){
        int i = Q.top().first.first;
        int j = Q.top().first.second;
        int val = Q.top().second;
        auto edge = Q.top();
        Q.pop();

        // if(used[i])
        // continue;

        // used[j] = true;

        int fouI = parfind(sets, i);
        int fouJ = parfind(sets, j);
        if((fouI != fouJ) || fouI == -1)
        {
            unioncalc(sets, i, j);
            gnew.push_back(edge);
        }
    }

    for(int i = 0; i < gnew.size(); i++)
    {
        cout << "I : " << gnew[i].first.first << " J : " << gnew[i].first.second << " Value : " << gnew[i].second << endl;
    }
}

// 9
// 0 4 0 0 0 0 0 8 0         
// 4 0 8 0 0 0 0 11 0         
// 0 8 0 7 0 4 0 0 2         
// 0 0 7 0 9 14 0 0 0         
// 0 0 0 9 0 10 0 0 0         
// 0 0 4 14 10 0 2 0 0         
// 0 0 0 0 0 2 0 1 6         
// 8 11 0 0 0 0 1 0 7         
// 0 0 2 0 0 0 6 7 0