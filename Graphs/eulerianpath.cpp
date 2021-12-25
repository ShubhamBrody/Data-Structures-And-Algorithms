#include "eulerianpath.h"

void calcinandoutdeg(vector<int> g[], int n, vector<int> &in, vector<int> &out)
{
    for(int i = 0; i < n; i++){
        out[i] = g[i].size();
        for(int to : g[i]){
            in[to]++;
        }
    }
}

bool eulerpossible(vector<int> g[], int n, vector<int> &in, vector<int> &out)
{
    int start_nodes = 0, end_nodes = 0;
    for(int i = 0; i < n; i++){
        if(abs(in[i]-out[i]) > 1)
        return false;
        else if(in[i]-out[i] == 1)
        end_nodes++;
        else if(out[i]-in[i] == 1)
        start_nodes++;
    }
    return start_nodes == end_nodes && (start_nodes == 1 || end_nodes == 0);
}

int findstartingnode(vector<int> &in, vector<int> &out)
{
    int start = -1;
    for(int i = 0; i < in.size(); i++){
        if(out[i]-in[i] == 1)
        return i;
        if(out[i] > 0)
        start = i;
    }
    return start;
}

void dfs(int node, vector<int> g[], vector<int> &in, vector<int> &out, vector<int> &path)
{
    while(out[node])
    {
        int nextnode = g[node][--out[node]];
        dfs(nextnode, g, in, out, path);
    }
    path.pb(node);
}

void dfscircuitgen(vector<int> g[], int n, int node, vector<int> &path, vector<int> &depth, vector<int> &nodeid, int d = 0)
{
    path.pb(node);
    depth.pb(d);
    nodeid[node] = path.size()-1;
    for(int i : g[node])
    {
        dfscircuitgen(g, n, i, path, depth, nodeid, d+1);
        path.pb(node);
        depth.pb(d);
        nodeid[node] = path.size()-1;
    }
}

bool eulerpath(vector<int> g[], int n, int m, vector<int> &path)
{
    vector<int> indegree(n, 0);
    vector<int> outdegree(n, 0);
    calcinandoutdeg(g, n, indegree, outdegree);
    if(eulerpossible(g, n, indegree, outdegree))
    {
        dfs(findstartingnode(indegree, outdegree), g, indegree, outdegree, path);
        if(path.size() == m+1)
        return true;
        else
        return false;
    }
    else
    {
        cout << "NO EULERIAN PATH IS POSSIBLE" << endl;
        return false;
    }
}

bool eulercircuit(vector<int> g[], int n, vector<int> &path, vector<int> &depth, int start, vector<int> &nodeid)
{
    dfscircuitgen(g, n, start, path, depth, nodeid);
}