#include<bits/stdc++.h>
using namespace std;

int lcsubstring(string str, string pat)
{
    vector<vector<int>> dp(str.length()+1, vector<int>(pat.length()+1, 0));
    int maxl = 0;
    for(int i = 1; i <= str.length(); i++){
        for(int j = 1; j <= pat.length(); j++){ 
            if(str[i-1] == pat[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = 0;
            maxl = max(maxl, dp[i][j]);
        }
    }
    return maxl;
}


int main(){
    string str, pat;
    cin >> str >> pat;
    cout << "The Longest Common Subseuence is : " << lcsubstring(str, pat);
}