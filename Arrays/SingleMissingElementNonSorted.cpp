#include<iostream>
#include<math.h>
#include<limits>
#define ll long long
using namespace std;


int main()
{
    int n;
    cin >> n;
    int arr[n];
    cout << "NON-SORTED ARRAY" << endl;
    int sum = 0;
    int min = numeric_limits<int>::max(), max = -numeric_limits<int>::max();
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] > max)
        max = arr[i];
        if(arr[i] < min)
        min = arr[i];
        sum+=arr[i];
    }
    int actSum = ((max * (max + 1))/2) - ((min * (min - 1))/2);
    cout << actSum - sum;
}