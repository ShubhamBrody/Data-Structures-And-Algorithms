#include <bits/stdc++.h>
using namespace std;

void filler(vector<int> &fntree, vector<int> &arr, int n, int i)
{
    for (int I = i + 1; I < n + 1;)
    {
        fntree[I] += arr[i];
        I += (I & -I);
    }
}

void printer(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void calcfntree(vector<int> &fntree, vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        filler(fntree, arr, n, i);
    }
}

int rangequerysolver(vector<int> &fntree, int idx)
{
    int sum = 0;
    // idx;
    while(idx)
    {
        sum += fntree[idx];
        int val = idx & -idx;
        idx &= ~(val);
        // cout << "idx : " << idx << endl;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    vector<int> fntree(n + 1, 0);
    calcfntree(fntree, arr, n);
    printer(fntree);
    int q;
    cin >> q;
    while(q--)
    {
        int start, end;
        cin >> start >> end;
        cout << rangequerysolver(fntree, end) - rangequerysolver(fntree, start) << endl;
    }
}