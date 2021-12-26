#include<bits/stdc++.h>
using namespace std;
#define pb push_back
class Edge
{
    public:
        int from, to;
        Edge* residual;
        int flow, capacity;

    public:
        Edge(int from, int to, int capacity) :from(from),to(to),capacity(capacity),flow(0) {}

        bool isResidual();
        int remainingCapacity();
        void augument(int); //for residual edge creation during the condition of a bottleneck
};

bool Edge::isResidual(){ return capacity == 0; }

int Edge::remainingCapacity() { return capacity - flow; }

void Edge::augument(int bottleneck) {
    flow += bottleneck;
    residual->flow -= bottleneck;
}

//global variables
int n, s, t; // n->number of nodes, s->source node, t->destination node
int maxflow = 0;
vector<vector<Edge*>> g; // graph to be stored g[from] = [from-to, from-to1, ...]
int visitedToken = 1;
vector<int> visited;

void addEdge(int from, int to, int capacity) // to add an edge and also to create an edge ofc
{
    Edge* e1 = new Edge(from, to, capacity);
    Edge* e2 = new Edge(to, from, 0);
    e1->residual = e2;
    e2->residual = e1;
    g[from].pb(e1);
    g[to].pb(e2);
}

int bfs() 
{
    queue<int> q;
    q.push(s);
    visited[s] = visitedToken;
    vector<Edge*> par(n, nullptr);
    while(!q.empty())
    {
        int curr = q.front(); q.pop();
        // cout << curr << endl;
        if(curr == t)
        break;
        for(auto node : g[curr])
        {
            if(node->remainingCapacity()>0 && visited[node->to] != visitedToken)
            {
                visited[node->to] = visitedToken;
                par[node->to] = node;
                q.push(node->to);
            }
        }
    }

    if(par[t] == nullptr) return 0;
    int bottleneck = INT_MAX;

    int curr = t;
    while(par[curr] != nullptr)
    {
        bottleneck = min(bottleneck, par[curr]->remainingCapacity());
        curr = par[curr]->from;
    }
    
    curr = t;
    while(par[curr] != nullptr)
    {
        par[curr]->augument(bottleneck);
        curr = par[curr]->from;
    }

    return bottleneck;
}

//algorithm initiator method of the program
void edmundskarp()
{
    for(int f = bfs(); f!=0; f = bfs())
    {
        maxflow += f;
        visitedToken++;
    }
}

void graphPrinter()
{
    for(int i = 0; i < n; i++)
    {
        for(auto e : g[i])
        {
            cout << "From : " << e->from << " To : " << e->to << " with Flow : " << e->flow << " and Capacity : " << e->capacity << endl;
        }
    }
}

int main() {
    int m;
    cout << "Enter number of nodes, source node idx, sink node idx and number of edges:\n";
    cin >> n >> s >> t >> m;
    g.resize(n);
    visited.resize(n);
    while(m--) {
        int from, to, capacity;
        cin >> from >> to >> capacity;
        addEdge(from, to, capacity);
    }
    graphPrinter();
    edmundskarp();
    cout << endl;
    graphPrinter();
    cout << "The maximum flow is : " << maxflow;
}
// 12 10 11 23
// 0 6 1
// 0 7 1
// 1 6 1
// 1 7 1
// 1 8 1
// 2 5 1
// 2 6 1
// 2 7 1
// 2 9 1
// 3 7 1
// 4 7 1
// 4 8 1
// 4 9 1
// 10 0 1
// 10 1 1
// 10 2 1
// 10 3 1
// 10 4 1
// 5 11 1
// 6 11 1
// 7 11 1
// 8 11 1
// 9 11 1