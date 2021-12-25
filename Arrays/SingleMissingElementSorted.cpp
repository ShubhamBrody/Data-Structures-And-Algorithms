#include<iostream>
#include<math.h>
#define ll long long
using namespace std;


int main()
{
    int n;
    cin >> n;
    int arr[n];
    cout << "SORTED ARRAY ONLY" << endl;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum+=arr[i];
    }
    int actSum = ((arr[n-1] * (arr[n-1] + 1))/2) - (((arr[0]-1) * (arr[0]))/2);

    cout << actSum - sum;
}