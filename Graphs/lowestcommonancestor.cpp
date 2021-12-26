#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define LOG2(n) floor(log10(n)/log10(2))

vector<int> path;
vector<int> depth;
vector<int> nodeid;
vector<vector<int>> spt;
vector<vector<int>> idxtab;
// vector<int> in;
// vector<int> out;
void minidxpreprocess(int n)
{
    n = 2*n+1;
    int P = LOG2(n);
    spt.resize(P+1);
    idxtab.resize(P+1);
    fill(spt.begin(), spt.end(), vector<int>(n, 0));
    fill(idxtab.begin(), idxtab.end(), vector<int>(n, -1));

    spt[0] = depth;
    iota(idxtab[0].begin(), idxtab[0].end(), 0);

    for(int i = 1; i <= P; i++){
        int p2 = pow(2, i);
        int p3 = pow(2, i-1);
        for(int j = 0 ; j <= n-p2; j++){
            // spt[i][j] = min(spt[i-1][j], spt[i-1][j+p3]);
            if(spt[i-1][j] < spt[i-1][j+p3])
            {
                spt[i][j] = spt[i-1][j];
                idxtab[i][j] = idxtab[i-1][j];
            }
            else
            {
                spt[i][j] = spt[i-1][j+p3];
                idxtab[i][j] = idxtab[i-1][j+p3];
            }
        }
    }

    for(int i = 0; i <= P; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << spt[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i <= P; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << idxtab[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int minidxreturn(vector<int> path, vector<int> depth, vector<int> nodeid, int n1, int n2)
{
    int l = min(nodeid[n1], nodeid[n2]), r = max(nodeid[n1], nodeid[n2]);
    int newP = LOG2(r-l+1);
    return spt[newP][l] < spt[newP][r-pow(2,newP)-1] ? idxtab[newP][l] : idxtab[newP][r-pow(2,newP)-1];
    // int idx1 = nodeid[n1], idx2 = nodeid[n2];
    // int minid = INT_MAX, ind;
    // for(int i = min(idx1, idx2); i <= max(idx1, idx2); i++)
    // {
    //     if(minid > depth[i])
    //     {
    //         minid = depth[i];
    //         ind = i;
    //     }
    // }
    // return ind;
}

void euleriantour(vector<int> g[], int n, int m, int root)
{
    nodeid.resize(n);
    function<void(int, int)> dfs = [&](int curr, int dep)
    {
        path.pb(curr);
        depth.pb(dep);
        nodeid[curr] = path.size()-1;
        for(int node : g[curr])
        {
            dfs(node, dep+1);
            path.pb(curr);
            depth.pb(dep);
        }
    };
    dfs(root, 0);
    minidxpreprocess(m);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> g[n];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        // g[b].pb(a);
    }

    int n1, n2;
    cin >> n1 >> n2;
    euleriantour(g, n, m, 0);
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < depth.size(); i++){
        cout << depth[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < nodeid.size(); i++){
        cout << nodeid[i] << " ";
    }
    cout << endl << endl;
    int idx = minidxreturn(path, depth, nodeid, n1, n2);
    cout << "LCA is : " << path[idx] << endl;
}

// 17 16
// 0 1
// 0 4
// 1 2
// 1 3
// 4 5
// 4 10
// 5 6
// 5 9
// 10 11
// 10 13
// 6 7
// 6 8
// 11 12
// 13 14
// 12 15
// 12 16