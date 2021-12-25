#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string t1, string t2) {
    vector<vector<int>> dp(t1.length()+1, vector<int>(t2.length()+1, 0));
    for(int i = 1; i <= t1.length(); i++)
    {
        for(int j = 1; j <= t2.length(); j++)
        {
            if(t1[i-1] == t2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[t1.length()][t2.length()];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "The longest common subsequence is : " << longestCommonSubsequence(s1,s2) << endl;
}