#include<iostream>
#define ll long long
using namespace std;

ll ncr(int n, int r)
{
    if(r == 0 || r == n)
    {
        return 1;
    }
    return ncr(n-1, r-1) + ncr(n-1, r);
}


int main()
{
     ll n, r;
     cin >> n >> r;
     cout << ncr(n, r);
}