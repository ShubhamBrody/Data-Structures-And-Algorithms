#include<bits/stdc++.h>
using namespace std;

int n;
int mcm(vector<int> p, int i, int j, vector<vector<int>> &dp)
{
    if(i == j)
    return 0;
    
    if(dp[i][j] != -1)
    return dp[i][j];
    dp[i][j] = INT_MAX;
    for(int k = i; k < j; k++)
    {
        dp[i][j] = min(mcm(p, i, k, dp) + mcm(p, k+1, j, dp) + p[i-1]*p[k]*p[j], dp[i][j]);
    }
    return dp[i][j];
}

int main()
{
    cin >> n;
    
    vector<int> q(n);
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int &a : q)
    cin >> a;
    
    cout << mcm(q, 1, q.size()-1, dp);
}