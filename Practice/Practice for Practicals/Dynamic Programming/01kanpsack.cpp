#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> w(n);
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }

    int target = 0;
    cin >> target;

    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    for(int i = 0; i <= n; i++){
        for(int j = 0 ;j <= target; j++){
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if(w[i-1] <= j)
            {
                dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << dp[n][target];
}