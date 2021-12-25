#include<iostream>
#include<math.h>
#define ll long long
using namespace std;

void binSearch(ll arr[],ll l,ll h, int k)
{
    if(l > h)
    {
        cout << "NOT FOUND";
        return;
    }
    ll mid = floor((int)(l+h)/2);
    cout << "MID ELEMENT : " << arr[mid] << endl;
    if(arr[mid] == k)
    {
        cout << "FOUND THE NUMBER AT : " << mid;
        return;
    }
    else if(arr[mid] > k)
    {
        binSearch(arr, l, mid - 1, k);
    }
    else
    {
        binSearch(arr, mid + 1, h, k);
    }
}


int main()
{
    ll n, k;
    cin >> n;
    ll arr[n];
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;
    ll l = 0, h = n-1, mid;
    binSearch(arr, l, h, k);
}