#include<bits/stdc++.h>
using namespace std;

int main(){
    int E, V;
    cin >> V >> E;
    vector<int> g[V];

    for(int i = 0; i < V; i++){
        int A, B;
        cin >> A >> B;
        g[A].push_back(B);
    }

    
}