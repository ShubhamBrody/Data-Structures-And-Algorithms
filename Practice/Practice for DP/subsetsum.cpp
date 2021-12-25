#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> A(n);
    
    for(int &a : A)
    cin >> a;
    
    int sum;
    cin >> sum;
    
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= sum; j++)
        {
            if(j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            if(i == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            
            if(A[i-1] <= j)
            dp[i][j] = dp[i-1][j] + dp[i-1][j-A[i-1]];
            if(A[i-1] > j)
            dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][sum];
}