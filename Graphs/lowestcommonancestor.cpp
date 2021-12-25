#include "eulerianpath.h"

int minidxreturn(vector<int> path, vector<int> depth, vector<int> nodeid, int n1, int n2)
{
    int idx1 = nodeid[n1], idx2 = nodeid[n2];
    int minid = INT_MAX, ind;
    for(int i = min(idx1, idx2); i <= max(idx1, idx2); i++)
    {
        if(minid > depth[i])
        {
            minid = depth[i];
            ind = i;
        }
    }
    return ind;
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
    }
    int start;
    cin >> start;
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> path;
    vector<int> depth;
    vector<int> nodeid(n);
    // eulerpath(g, n, m, path);
    eulercircuit(g, n, path, depth, start, nodeid);
    // reverse(path.begin(), path.end());
    // reverse(depth.begin(), depth.end());
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