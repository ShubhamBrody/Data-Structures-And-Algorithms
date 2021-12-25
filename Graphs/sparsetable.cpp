//Ranged Minimum Queries using sparse table
#include<bits/stdc++.h>
#define LOG2(n) floor(log10(n)/log10(2))
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(int &a : A)
    {
        cin >> a;
    }

    int P = LOG2(n);

    vector<vector<int>> spt(P+1, vector<int>(n, 0));
    spt[0] = A;

    for(int i = 1; i <= P; i++){
        int p2 = pow(2, i);
        int p3 = pow(2, i-1);
        for(int j = 0 ; j <= n-p2; j++){
            spt[i][j] = min(spt[i-1][j], spt[i-1][j+p3]);
        }
    }

    for(int i = 0; i <= P; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << spt[i][j] << " ";
        }
        cout << endl;
    }

    int l, r;
    cin >> l >> r;
    int newP = LOG2(r-l+1);
    cout << "Minimum Range Querry is : " << min(spt[newP][l], spt[newP][r-pow(2,newP)-1]);
}