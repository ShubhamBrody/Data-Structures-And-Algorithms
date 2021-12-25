#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;

    int arr[2][N+1];
    arr[0][0] = 0;
    arr[1][0] = 0;

    for(int i = 1; i <= N; i++){
        cin >> arr[0][i] >> arr[1][i];
    }

    int DP[N+1][W+1], j;

    for(int i = 0; i <= N; i++){
        for(j = 0; j <= W; j++){
            if(i == 0 || j == 0)
                DP[i][j] = 0;
            else if(arr[1][i] <= j)
                DP[i][j] = max((arr[0][i] + DP[i-1][j-arr[1][i]]), DP[i-1][j]);
            else
                DP[i][j] = DP[i-1][j];
        }
    }

    cout << "The answer is : " << DP[N][j];

//    profit  : 1  2
//    weight :  12 8


}