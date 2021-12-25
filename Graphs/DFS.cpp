#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> visited;

bool isValid(int i, int n)
{
    return !(i < 0 || i == n);
}

int checkMat[] = {1, -1};

int dfs(vector<vector<int>> adj, int i, int j, int initVal = 1)
{
    static int value = 0;
    if (initVal == 0)
    {
        value = 1;
    }

    int n = adj.size();
    visited[i][j] = 1;

    for (int k = 0; k < 2; k++)
    {
        if (isValid(i + checkMat[k], n))
        {
            if (adj[i + checkMat[k]][j] == 1 && visited[i + checkMat[k]][j] == 0)
            {
                value++;
                dfs(adj, i + checkMat[k], j);
            }
        }
        if (isValid(j + checkMat[k], n))
        {
            if (adj[i][j + checkMat[k]] == 1 && visited[i][j + checkMat[k]] == 0)
            {
                value++;
                dfs(adj, i, j + checkMat[k]);
            }
        }
    }
    return value;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        vector<int> visiTemp;
        for (int j = 0; j < n; j++)
        {
            int tempVar;
            cin >> tempVar;
            temp.push_back(tempVar);
            visiTemp.push_back(0);
        }
        adj.push_back(temp);
        visited.push_back(visiTemp);
    }

    int res;
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 1 && visited[i][j] == 0)
            {
                res = dfs(adj, i, j, 0);
                if (res > max)
                {
                    max = res;
                }
            }
        }
    }

    cout << max;
    //This program will find the number of islands and also the nodes in the largest island.
}