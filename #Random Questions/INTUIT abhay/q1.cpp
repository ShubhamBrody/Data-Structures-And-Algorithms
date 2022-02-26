#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cap;
    vector<int> values(2);
    vector<int> wts(2);
    cin >> cap >> values[0] >> values[1] >> wts[0] >> wts[1];
    vector<vector<int>> dp(3, vector<int>(cap+1, 0));
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= cap; j++)
        {
            if(wts[i-1] > j)
            dp[i][j] = dp[i-1][j];
            else
            dp[i][j] = max(values[i-1]+dp[i][j-wts[i-1]], dp[i-1][j]);
        }
    }
    cout << dp[2][cap];
}