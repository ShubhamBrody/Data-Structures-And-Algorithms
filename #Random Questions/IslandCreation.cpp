#include<bits/stdc++.h>
using namespace std;

int arr[1000][1000];

int ops = [[1, 0],
           [0, 1],
           [-1, 0],
           [0, -1]];

void dfsRemover(int i, int j)
{
    for(int k = 0; k < ops.length(); k++)
    {
        if(i+ops[k][0] >= 0 && j+ops[k][1] >= 0)
        {
            if(arr[i+ops[k][0]][ops[k][1]] == 1)
            {
                arr[i+ops[k][0]][ops[k][1]] = 0;
            }
        }
    }
}


int main()
{
    //Island question youtube
    //Clement-BenAwad

    int n;
    cin >> n;
    int visited[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    for(int i = 0 ;i < n; i++)
    {
        dfsRemover();
    }
}