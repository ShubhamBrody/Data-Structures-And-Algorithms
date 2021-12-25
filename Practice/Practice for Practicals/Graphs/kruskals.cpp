#include <bits/stdc++.h>
using namespace std;
#define PPIII pair<pair<int, int>, int>

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

struct cmp{
    bool operator()(PPIII p1, PPIII p2){
        return p1.second > p2.second;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> ranks(n, 1);
    vector<int> P(n);
    iota(P.begin(), P.end(), 0);

    priority_queue<PPIII, vector<PPIII>, cmp> pq;
    for(int i = 0; i < m ;i++){
        int a, b, w;
        cin >> a >> b >> w;
        pq.push({{a, b}, w});
    }

    while(!pq.empty())
    {
        PPIII nt = pq.top(); pq.pop();
        if(dofind(nt.first.first, P) == dofind(nt.first.second, P))
        {
            continue;
        }
        cout << nt.first.first << "  " << nt.first.second << "  " << nt.second << endl;
        dounion(nt.first.first, nt.first.second, ranks, P);
    }
}