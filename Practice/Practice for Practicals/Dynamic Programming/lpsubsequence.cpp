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

int lcsub(string str, string pat)
{
    vector<vector<int>> dp(str.length()+1, vector<int>(pat.length()+1, 0));
    for(int i = 1; i <= str.length(); i++){
        for(int j = 1; j <= pat.length(); j++){ 
            if(str[i-1] == pat[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    lcstring(dp, str, pat);
    return dp[str.length()][pat.length()];
}

int main(){
    string str, pat;
    cin >> str;
    pat = str;
    reverse(pat.begin(), pat.end());
    cout << "The Longest Common Subseuence is : " << lcsub(str, pat);
}