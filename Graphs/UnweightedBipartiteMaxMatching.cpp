#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF INT_MAX/2

class Edge {
    public:
    int from, to, capacity, flow;
    Edge* residual;
    Edge(int from, int to, int capacity) :from(from), to(to), capacity(capacity), flow(0){}
    int remainingCapacity();
    void augmentpath(int);
};

int Edge::remainingCapacity() { return capacity-flow; }

void Edge::augmentpath(int bottleneck) {
    flow += bottleneck;
    residual->flow -= bottleneck;
}
//Edge Ends Here


class FordFulkerson {
    public:
    int n, s, t, maxflow;
    int visitedToken = 1;
    vector<int> visited;
    vector<vector<Edge*>> g;
    FordFulkerson(int n, int s, int t, vector<vector<Edge*>> g) :n(n), s(s), t(t), g(g){
        visited.resize(n);
        maxflow = 0;
    }
    void sourseSink(int s, int t){
        this->s = s;
        this->t = t;
    }
    void fordfulkerson();
    void graphPrinter();

    private:
    int dfs(int, int);
};

void FordFulkerson::graphPrinter()
{
    for(auto li : g)
    {
        for(auto edge: li)
        {
            cout << "From : From : " << edge->from << " To : " << edge->to << " with Remaining Capacity :" << edge->remainingCapacity() << endl;
        }
        cout << endl;
    }
}

void FordFulkerson::fordfulkerson(){ 
    while(1)
    {
        int f = dfs(s, INF);
        maxflow += f;
        visitedToken++;
        if(f==0) break;
    }

    // for(int f = dfs(s, INF); f!=0; f = dfs(s, INF))
    // {
    //     maxflow += f;
    //     visitedToken++;
    // }
}

int FordFulkerson::dfs(int node, int flow)
{
    if(node == t) return flow;
    visited[node] = visitedToken;

    for(auto edge : g[node])
    {
        if(edge->remainingCapacity() > 0 && visited[edge->to] != visitedToken)
        {
            int bottleneck = dfs(edge->to, min(flow, edge->remainingCapacity()));

            if(bottleneck > 0)
            {
                edge->augmentpath(bottleneck);
                return bottleneck;
            }
        }
    }
    return 0;
}
//FordFulkerson Ends Here

void addEdge(vector<vector<Edge*>> &g, int from, int to, int capacity){
    Edge* e1 = new Edge(from, to, capacity);
    Edge* e2 = new Edge(to, from, 0);
    e1->residual = e2;
    e2->residual = e1;
    g[from].pb(e1);
    g[to].pb(e2);
}

FordFulkerson soursesinkmaker(int n, vector<vector<Edge*>> g, set<int> fromList, set<int> toList)
{
    int s = n, t = n+1;
    for(int i : fromList) {
        addEdge(g, s, i, 1); // max 1 book per person
    }

    for(int i : toList)
    {
        addEdge(g, i, t, 1); // max 1 copy of a book will be given to anybody
    }

    FordFulkerson ff(n, s, t, g);
    return ff;
}

int main() {
    int n, s, t, m;
    cin >> n >> m;
    vector<vector<Edge*>> g(n+2);
    set<int> fromList;
    set<int> toList;
    while(m--)
    {
        int from, to, capacity;
        cin >> from >> to;
        fromList.insert(from);
        toList.insert(to);
        addEdge(g, from, to, 1);
    }
    FordFulkerson ff = soursesinkmaker(n, g, fromList, toList);
    ff.graphPrinter();
    ff.fordfulkerson();
    cout << "Maximum Books alotted : " << ff.maxflow;
}

// Graph example : A person is matched to n books he likes in a library, a book can be liked by many person.
// The source and sink is generated and augmented by the code.
// source -> from capacity determines the number of books a person can take with him/her.
// to -> sink capacity determines the number of copies of each book present in the library.
// from -> to capacity determines the number of same book that a person can take with him/her.