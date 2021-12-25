#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int n = str.length();
    vector<vector<bool>> dp(str.length(), vector<bool>(str.length(), false));
    int start = 0;
    int len = 1;

    for(int i = 0; i < n; i++)
    {
        dp[i][i] = true;
        if(i < n-1 && str[i] == str[i+1]){
             dp[i][i+1] = true;
             len = 2;
        }
    }

    for(int k = 3; k <= n; k++){
        for(int i = 0; i < n-k+1; i++)
        {
            int j = i+k-1;

            if(str[i] == str[j] && dp[i+1][j-1])
            {
                dp[i][j] = true;
                if(k > len)
                {
                    len = k;
                    start = i;
                }
            }
        }
    }

    cout << str.substr(start, len);
}