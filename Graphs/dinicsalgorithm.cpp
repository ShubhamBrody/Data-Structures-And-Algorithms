#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF INT_MAX/2

class Edge {
    public:
    int from, to, capacity, flow;
    Edge* residual;
    Edge(int from, int to, int capacity):from(from),to(to),capacity(capacity),flow(0){}
    int remainingCapacity();
    void augument(int);
};

int Edge::remainingCapacity() { return capacity-flow; }
void Edge::augument(int bottleneck) {
    flow += bottleneck;
    residual->flow -= bottleneck;
}

int n, s, t;
int maxflow = 0;
vector<int> level; //to keep the levels of nodes helps in dfds traversal
vector<vector<Edge*>> g;


void addEdge(int from, int to, int capacity) {
    Edge* e1 = new Edge(from, to, capacity);
    Edge* e2 = new Edge(to, from, 0);
    e1->residual = e2;
    e2->residual = e1;
    g[from].pb(e1);
    g[to].pb(e2);
}

//to assign levels to nodes
bool bfslevelgen() {
    queue<int> q;
    q.push(s);
    fill(level.begin(), level.end(), -1);
    level[s] = 0;
    while(!q.empty())
    {
        int curr = q.front(); q.pop();
        for(auto edge : g[curr])
        {
            int node = edge->to;
            if(edge->remainingCapacity() <= 0 || level[node] != -1) continue;
            level[node] = level[curr]+1;
            q.push(node);
        }
    }
    return level[t]!=-1;
}

int counter = 0;
bool inc = true;

//to actully calculate flow
int dfstraversal(int node, vector<int> &next, int flow) {
    if(inc) counter++, inc = false;
    if(node == t) return flow;
    for(; next[node] < g[node].size(); next[node]++) {
        cout << counter << " --> " << node << " --> " << next[node] << endl;
        Edge* edge = g[node][next[node]];
        if(level[edge->to] == level[node]+1 && edge->remainingCapacity() > 0)
        {
            int bottleneck = dfstraversal(edge->to, next, min(flow, edge->remainingCapacity()));
            if(bottleneck > 0)
            {
                edge->augument(bottleneck);
                return bottleneck;
            }
        }
    }
    return 0;
}

void nextprint(vector<int> next)
{
    for(int i = 0; i < n; i++)
    {
        cout << next[i] << " ";
    }
    cout << endl << endl;
}

void dinicsalgo() {
    //used here for Shimon Even and Alon Itai optimisation for pruning dead-ends
    vector<int> next(n, 0);

    while(bfslevelgen()) {
        nextprint(level);
        fill(next.begin(), next.end(), 0);
        for(int f = dfstraversal(s, next, INF); f!=0; f = dfstraversal(s, next, INF))
        {
            cout << "counter : " << counter << endl;
            nextprint(next);
            inc = true;
            maxflow += f;
        }
    }
}

int main() {
    int m;
    cin >> n >> s >> t >> m;
    g.resize(n);
    level.resize(n);
    while(m--)
    {
        int from, to, capacity;
        cin >> from >> to >> capacity;
        addEdge(from, to, capacity);
    }

    dinicsalgo();
    cout << "the maxflow calculated using dinic's algo is : " << maxflow << endl;
}

// 11 9 10 17
// 9 0 5
// 9 1 10
// 9 2 15
// 0 3 10
// 1 0 15
// 1 4 20
// 2 5 25
// 3 4 25
// 3 6 10
// 4 2 5
// 4 7 30
// 5 7 30
// 5 8 10
// 7 8 15
// 6 10 5
// 7 10 15
// 8 10 10