#include<iostream>
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
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == k)
        {
            cout << "FOUND AT " << i << endl;
            found = true;
            break;
        }
    }
    if(!found)
    cout << "NOT FOUND" << endl;
}