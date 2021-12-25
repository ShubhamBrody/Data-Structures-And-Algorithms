#include<bits/stdc++.h>
using namespace std;

int n;
int mcm(vector<int> p, int i, int j, vector<vector<int>> &dp)
{
    if(i >= j)
    return 0;
    
    int min = INT_MAX, count;
    for(int k = i; k < j; k++)
    {
        count = mcm(p, i, k, dp)+mcm(p, k+1, j, dp) + p[i-1]*p[k]*p[j];
        if(count < min)
        min = count;
    }
    
    return min;
}

int main()
{
    cin >> n;
    
    vector<int> q(n);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int &a : q)
    cin >> a;
    
    cout << mcm(q, 1, q.size()-1, dp);
}