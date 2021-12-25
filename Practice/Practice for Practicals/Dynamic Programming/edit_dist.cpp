#include<bits/stdc++.h>
using namespace std;
//three operations : 
//updation
//deletion
//insertion

int dist(string str, string tos, int m, int n)
{
    if(m == 0)
    return n;
    if(n == 0)
    return m;
    if(str[m-1] == tos[n-1])
    return dist(str, tos, m-1, n-1);

    return 1+min(min(dist(str, tos, m-1, n),
                     dist(str, tos, m, n-1)),
                     dist(str, tos, m-1, n-1));
}

int distmem(string str, string tos, int m, int n)
{
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++){
            if(i == 0)
            {
                dp[i][j] = j;
            }
            else if(j == 0)
            {
                dp[i][j] = i;
            }
            else if(str[i-1] == tos[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1+min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main(){
    string str, tos;
    cin >> str >> tos;

    cout << distmem(str, tos, str.length(), tos.length());
}