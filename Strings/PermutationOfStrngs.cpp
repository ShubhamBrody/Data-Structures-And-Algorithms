#include<bits/stdc++.h>
using namespace std;

void permutations(char arr[], int index)
{
    static int a[1000];
    static char arr2[1000];
    static int i = 0;

    for(int i = 0; i < strlen(arr); i++)
    {
        if(a[i] == 0)
        {
            a[i] = 1;
            arr2[index] = arr[i];
            permutations(arr, index+1);
            a[i] = 0;
        }
    }
    if(index == strlen(arr))
    cout << "Perm : " << ++i << " : " << arr2 << endl;
    return;
}

int main()
{
    char arr[1000];
    cin >> arr;

    permutations(arr, 0);
}