#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void findcenter(int n, vector<int> g[])
{
    vector<int> degree(n, 0);
    for(int i = 0; i < n; i++)
    {
        degree[i] = g[i].size();
    }
    int count = 0;
    while(count < n)
    {
        if(n-count == 1 || n-count == 2)
        break;
        vector<int> todel;
        for(int i = 0; i < n; i++)
        {
            if(degree[i] == 1)
            {
                todel.pb(g[i][0]);
                degree[i] = -1;
                count++;
            }
        }
        for(int i = 0; i < todel.size(); i++)
        {
            degree[todel[i]]--;
        }
    }
    cout << "The roots are : \n";
    for(int i = 0; i < n; i++)
    {
        if(degree[i] > -1)
        cout << i << endl;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    findcenter(n, g);
}