#include<bits/stdc++.h>
using namespace std;

vector<string> lcstring(vector<vector<int>> &dp, string str, string pat, int m, int n)
{
    if(m == 0 || n == 0)
    {
        return {""};
    }

    if(str[m-1] == pat[n-1])
    {
        vector<string> t = lcstring(dp, str, pat, m-1, n-1);

        for(string &st : t)
        {
            st.push_back(str[m-1]);
        }

        return t;
    }

    if(dp[m][n-1] > dp[m-1][n])
    {
        return lcstring(dp, str, pat, m, n-1);
    }
    if(dp[m-1][n] > dp[m][n-1])
    {
        return lcstring(dp, str, pat, m-1, n);
    }

    vector<string> top = lcstring(dp, str, pat, m-1, n);
    vector<string> left = lcstring(dp, str, pat, m, n-1);
    top.insert(top.end(), left.begin(), left.end());
    return top;

}

vector<string> lcsub(vector<vector<int>> &dp, string str, string pat)
{
    for(int i = 1; i <= str.length(); i++){
        for(int j = 1; j <= pat.length(); j++){ 
            if(str[i-1] == pat[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return lcstring(dp, str, pat, str.length(), pat.length());
}

int main(){
    string str, pat;
    cin >> str >> pat;
    vector<vector<int>> dp(str.length()+1, vector<int>(pat.length()+1, 0));
    vector<string> all = lcsub(dp, str, pat);

    set<string> s(all.begin(), all.end());

    for(string ss : s)
    cout << ss << endl;
}