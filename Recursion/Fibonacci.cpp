#include<iostream>
#define ll long long
using namespace std;

ll a[1000];

ll fib(ll n)
{
    ll x, y;
    static ll c = 0;

    if(n < 2)
    return 1;

    if(a[n-1] != -1)
    x = a[n-1];
    else
    {
        x = fib(n-1);
        a[n-1] = x;
        //cout << "IT IS DONE FOR" << n - 1 << endl;
    }
    if(a[n-2] != -1)
    y = a[n-2];
    else
    {
        y = fib(n-2);
        a[n-2] = y;
        //cout << "IT IS DONE FOR" + n - 2 << endl;
    }
    return x + y;
}


int main()
{
    ll val;
    cin >> val;

    for(ll i = 0; i <= val; i++)
    {
        a[i] = -1;
    }
    a[0] = 0; a[1] = 1;

    cout << fib(val);
}