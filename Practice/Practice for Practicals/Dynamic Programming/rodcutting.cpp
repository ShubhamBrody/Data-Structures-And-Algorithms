#include<bits/stdc++.h>
using namespace std;

int rodcutproduct(int L)
{
    vector<int> T(L+1);
    iota(T.begin(), T.end(), 0);

    for(int i = 2; i <=L; i++){
        for(int j = 1; j <= i; j++){
            T[i] = max(T[i], j * T[i-j]);
        }
    }

    return T[L];
}

int rodcut(vector<int> C, int L)
{
    vector<int> T(L+1, 0);

    for(int i = 1; i <=L; i++){
        for(int j = 1; j <= i; j++){
            T[i] = max(T[i], C[j-1] + T[i-j]);
        }
    }

    return T[L];
}

int main(){
    vector<int> C{1,5,8,9,10,17,17,20};
    int L = 15;
    cout << rodcutproduct(L);
}