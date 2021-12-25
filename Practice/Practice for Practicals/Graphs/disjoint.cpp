#include <bits/stdc++.h>
using namespace std;

int dofind(int x, vector<int> &P)
{
    while(x != P[x])
    x = P[x];
    return x;
}

void dounion(int x, int y, vector<int> &ranks, vector<int> &P)
{
    int p1 = dofind(x, P);
    int p2 = dofind(y, P);

    if(p1 == p2)
    return;

    if(ranks[p1] >= ranks[p2])
    {
        P[p2] = p1;
        ranks[p1] += ranks[p2];
        ranks[p2] = 0;
    }
    else
    {
        P[p1] = p2;
        ranks[p2] += ranks[p1];
        ranks[p1] = 0;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> ranks(n, 1);
    vector<int> P(n);
    iota(P.begin(), P.end(), 0);

    vector<vector<int>> g(n);
    for(int i = 0; i < m ;i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        dounion(a, b, ranks, P);
    }

    for(int i = 0; i < n; i++)
    {
        cout << i << " --> " << ranks[i] << endl;
    }
}