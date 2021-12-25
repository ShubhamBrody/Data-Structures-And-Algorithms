#include<bits/stdc++.h>
using namespace std;
#define INF 99999

int main(){
    // int n;
    // cin >> n;

    vector<int> C(50);
    iota(C.begin(), C.end(), 1);

    // for(int i = 0; i < n; i++){
    //     cin >> C[i];
    // }

    int amt = 250;
    // cin >> amt;

    vector<long long> dp(amt+1, 0);
    dp[0] = 1;

    for(int i : C){
    for(int j = 0; j < amt+1; j++){
            if(i <= j)
            dp[j] += dp[j-i];
        }
    }

    cout << dp[amt];

}