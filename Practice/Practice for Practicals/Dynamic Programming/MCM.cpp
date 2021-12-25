#include<bits/stdc++.h>
using namespace std;

int mcm(vector<int> V, vector<vector<int>> &dp, int i, int j)
{
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j] != -1)
    return dp[i][j];

    dp[i][j] = INT_MAX;

    for(int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], mcm(V, dp, i, k)+mcm(V, dp, k+1, j)+V[i-1]*V[k]*V[j]);
    }

    return dp[i][j];
}

int main(){
    int n;
    cin >> n;

    vector<int> V(n);
    for(int i = 0; i < n; i++)
    {
        cin >> V[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << mcm(V, dp, 1, V.size()-1);
}
