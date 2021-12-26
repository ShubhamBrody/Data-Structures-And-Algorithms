#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define log2(b) log10(b)/log10(2)

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

//capacity scaling variables
int U, delta;

void addEdge(int from, int to, int capacity) // to add an edge and also to create an edge ofc
{
    Edge* e1 = new Edge(from, to, capacity);
    Edge* e2 = new Edge(to, from, 0);
    e1->residual = e2;
    e2->residual = e1;
    g[from].pb(e1);
    g[to].pb(e2);
}

int dfs(int node, int flow) 
{
    if(node == t) return flow;
    visited[node] = visitedToken;
    for(auto edge : g[node]){
        if(edge->remainingCapacity() > delta && visited[edge->to] != visitedToken){
            int bottleneck = dfs(edge->to, min(flow, edge->remainingCapacity()));

            if(bottleneck > 0)
            {
                cout << "BEFORE : From : " << edge->from << " To : " << edge->to << " with Capacity : " << edge->remainingCapacity() << endl;
                edge->augument(bottleneck);
                cout << "AFTER  : From : " << edge->from << " To : " << edge->to << " with Capacity : " << edge->remainingCapacity() << endl;
                return bottleneck;
            }
        }
    }
    return 0;
}

//algorithm initiator method of the program
void fordfulkersonswithCS()
{
    int maxval = INT_MAX/2;
    delta = U;
    while(1)
    {
        int f = dfs(s, maxval);
        maxflow += f;
        visitedToken++;
        if(f == 0 && delta != 0)
        delta /= 2;
        else if(f==0 && delta==0)
        break;
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
    int maxval = -1;
    while(m--) {
        int from, to, capacity;
        cin >> from >> to >> capacity;
        maxval = max(maxval, capacity);
        addEdge(from, to, capacity);
    }

    cout << "log val " << maxval << " "<< log2(maxval) << endl;
    U = pow(2, log2(maxval));
    cout << "The value of U is : " << U << endl;

    // graphPrinter();
    fordfulkersonswithCS();
    cout << endl;
    graphPrinter();
    cout << "The maximum flow is : " << maxflow;
}