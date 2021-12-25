#include<bits/stdc++.h>
using namespace std;

void lcstring(vector<vector<int>> dp, string str, string pat)
{
    int i = dp.size()-1;
    int j = dp[0].size()-1;

    string s = "";

    while(i>0 && j>0)
    {
        if(str[i-1] == pat[j-1])
        {
            s = str[i-1] + s;
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j] == dp[i][j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    
    cout << endl << s;
}

vector<string> lcsub(vector<vector<int>> &dp, string str, string pat)
{
    for(int i = 0; i <= str.length(); i++){
        dp[i][0] = i;
    }

    for(int i = 0; i <= pat.length(); i++){
        dp[0][i] = i;
    }

    for(int i = 1; i <= str.length(); i++){
        for(int j = 1; j <= pat.length(); j++){
            if(str[i-1] == pat[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j]+1, dp[i][j-1]+1);
        }
    }

    lcstring(dp, str, pat);
    return {""};
}

int main(){
    string str, pat;
    cin >> str >> pat;
    vector<vector<int>> dp(str.length()+1, vector<int>(pat.length()+1, 0));
}