#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int i = 0, int j = 0)
{
    static vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), 0));
    if(s1[i] == '\0' || s2[j] == '\0')
    {
        dp[i][j] = 0;
        return 0;
    }

    if(s1[i] == s2[j])
    {
        if(dp[i+1][j+1] != -1)
        {
            return dp[i][j] = 1+dp[i+1][j+1];
        }
        else
            return dp[i][j] = (1 + lcs(s1, s2, i+1, j+1));
    }
    else
    {
        int a1 = dp[i][j+1] != -1 ? dp[i][j+1] : lcs(s1,s2,i,j+1);
        int a2 = dp[i+1][j] != -1 ? dp[i+1][j] : lcs(s1,s2,i+1,j);
        return dp[i][j] = max(a1,a2);
    }
    // return max(lcs(s1,s2,i,j+1), lcs(s1,s2,i+1,j));
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "The longest common subsequence is : " << lcs(s1, s2);
}