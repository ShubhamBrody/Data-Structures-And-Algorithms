#include<iostream>
#include<math.h>
#define ll long long
using namespace std;




int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;
    bool found = false;
    ll l = 0, h = n-1, mid;
    while(l <= h)
    {
        mid = floor((int)(l+h)/2);
        cout << "MID ELEMENT : " << arr[mid] << endl;
        if(arr[mid] == k)
        {
            found = true;
            cout << "FOUND THE NUMBER AT : " << mid;
            break;
        }
        else if(arr[mid] > k)
        {
            h = mid - 1;
            continue;
        }
        else
        {
            l = mid + 1;
            continue;
        }
    }
}