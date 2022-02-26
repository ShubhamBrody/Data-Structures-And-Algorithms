#include <bits/stdc++.h>
using namespace std;

// class Problem
// {
//     public:
//     bool isAccepted;
//     int penalties;
//     Problem():isAccepted(false), penalties(0){}
// };

int main()
{
    int n, m;
    cin >> n >> m;
    int markscnt = 0, penalties = 0;
    vector<pair<bool, int>> isAccepted(n, {false, 0}); // isAccepted and penalties;
    while (m--)
    {
        int a;
        string t;
        cin >> a >> t;
        if (t == "AC")
        {
            if (!isAccepted[a].first)
            {
                isAccepted[a].first = true;
                markscnt += 100;
                penalties += isAccepted[a].second;
            }
        }
        else if (!isAccepted[a].first)
        {
            isAccepted[a].second++;
        }
    }

    // for(int i = 0; i < n; i++)
    // {
    //     if(isAccepted[i].first)
    //     {
    //         penalties+=isAccepted[i].second;
    //     }
    // }

    cout << markscnt << " " << penalties << endl;
}