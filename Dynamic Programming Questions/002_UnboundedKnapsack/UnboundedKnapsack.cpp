#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> W(n, 0);
    // vector<int> C(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> W[i];
    }

    int target;
    cin >> target;

    vector<vector<int>> table(n+1, vector<int>(target+1, 0));
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= target; j++){
            if(i == 0)
            {
                table[i][j] = 1;
            }
            else if(W[i-1] <= j) 
            table[i][j] = table[i][j-W[i-1]] + table[i-1][j];
            else
            table[i][j] = table[i-1][j];
        }
    }

    cout << "The answer is : " << table[n][target];
}