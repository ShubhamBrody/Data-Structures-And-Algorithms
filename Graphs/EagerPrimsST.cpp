#include <bits/stdc++.h>
using namespace std;

int main()
{

    int M = INT_MAX;
    int A[8][8] = {{M, M, M, M, M, M, M, M},
                   {M, M, 25, M, M, M, 5, M},
                   {M, 25, M, 12, M, M, M, 10},
                   {M, M, 12, M, 8, M, M, M},
                   {M, M, M, 8, M, 16, M, 14},
                   {M, M, M, M, 16, M, 20, 18},
                   {M, 5, M, M, M, 20, M, M},
                   {M, M, 10, M, 14, 18, M, M}};

    int near[8] = {M, M, M, M, M, M, M, M};

    int t[2][6] = {{M, M, M, M, M, M},
                   {M, M, M, M, M, M}};

    int min = INT_MAX;
    int mini = -1, minj = -1;

    for (int i = 1; i < 7; i++)
    {
        for (int j = i+1; j < 8; j++)
        {
            if (min > A[i][j])
            {
                min = A[i][j];
                mini = i;
                minj = j;
            }
        }
    }

    //cout << min << " " << mini << " " << minj << endl;

    t[0][0] = mini;
    t[1][0] = minj;

    near[t[0][0]] = 0;
    near[t[1][0]] = 0;

    for (int i = 1; i < 8; i++)
    {
        if (near[i] != 0)
        {
            near[i] = t[1][0];
            if (A[i][near[i]] > A[i][t[0][0]])
                near[i] = t[0][0];
        }
    }

    // for (int i = 1; i < 8; i++)
    // {
    //     cout << near[i] << "  ";
    // }

    int tt = 1;
    while(tt != 6)
    {
        min = M;
        mini = -1;
        minj = -1;
        for(int i = 1; i < 8; i++)
        {
            if(min > A[i][near[i]])
            {
                min = A[i][near[i]];
                mini = i;
                minj = near[i];
            }
        }
        near[mini] = 0;
        t[0][tt] = mini;
        t[1][tt] = minj;

        for (int i = 1; i < 8; i++)
        {
            if (near[i] != 0)
            {
                near[i] = t[1][tt];
                if (A[i][near[i]] > A[i][t[0][tt]])
                    near[i] = t[0][tt];
            }
        }

        tt++;
    }

    for(int i = 0; i < 6; i++)
    {
        cout << "{ " << t[0][i] << ", " << t[1][i] << " }" << endl;
    }
}