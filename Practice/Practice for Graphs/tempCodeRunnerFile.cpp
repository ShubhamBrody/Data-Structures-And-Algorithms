#include <bits/stdc++.h>
using namespace std;
#define INF 99999

int calcMin(vector<int> keys, vector<bool> mstSet)
{
    int min = INF, minIdx = -1;
    for (int i = 0; i < keys.size(); i++)
    {
        if (!mstSet[i] && keys[i] < min)
        {
            min = keys[i];
            minIdx = i;
        }
    }

    return minIdx;
}

void primsalgo(vector<vector<int>> g, int src)
{
    int n = g.size();
    vector<int> keys(n, INF);
    vector<bool> mstSet(n, false);
    vector<int> P(n, -1);

    keys[src] = 0;
    P[0] = -1;

    for (int i = 0; i < n-1; i++)
    {
        int idx = calcMin(keys, mstSet);
        mstSet[idx] = true;
        for(int j = 0;j < n; j++){
            if(!mstSet[j] && g[idx][j] && keys[idx] != INF && keys[j] > g[idx][j])
            {
                P[j] = idx;
                keys[j] = g[idx][j];
            }
        }

    }
    cout << "The answer is :" << endl;

    for(int i = 1; i < n; i++){
        cout << "From : " << P[i] << " to : " << i << " with weight : " << g[i][P[i]] << endl;
    }

    int srcq = 4;
    while(srcq != 0){
        cout << srcq << " <--- ";
        srcq = P[srcq];
    }
    cout << src;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(9, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    int src;
    cin >> src;

    primsalgo(g, src);
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
// 0