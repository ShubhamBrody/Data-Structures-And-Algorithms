#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, p;
    cin >> s >> p;

    vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, 0));

    for(int i = 0; i <= p.length(); i++){
        dp[0][i] = 0;
    }
    
    for(int i = 0; i <= s.length(); i++){
        dp[i][0] = 1;
    }


    for(int i = 1; i <= s.length(); i++){
        for(int j = 1; j <= p.length(); j++){
            dp[i][j] = ((s[i-1] == p[j-1]) ? dp[i-1][j-1] : 0) + dp[i-1][j];
        }
    }

    cout << dp[s.length()][p.length()] << endl;
}
