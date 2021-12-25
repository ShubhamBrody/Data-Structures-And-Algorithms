#include<bits/stdc++.h>
using namespace std;


int maxSum (int arr[], int n)
{
    int currSum = 0;
    int maxSum = 0;
    int maxElem = -INT_MAX;

    for(int i = 0; i < n; i++)
    {
        if(maxElem < arr[i])
        {
            maxElem = arr[i];
        }   
        if(arr[i] < 0)
        {
            if(currSum > maxSum)
            {
                maxSum = currSum;
                currSum = 0;
            }
        }
        else
            currSum += arr[i];
    }

    if(maxElem < 0)
        return maxElem;
    else
        return maxSum;

}

int main() 
{
    int arr[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxSum(arr, n);
}