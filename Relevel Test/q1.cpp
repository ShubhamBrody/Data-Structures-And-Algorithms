#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
vector<int> temp;
void recur(vector<int> &rngq, int k = 1, int idx = 0)
{
    if(k == 3)
    {
        temp.push_back(rngq.back()-rngq[idx]);
        int sum = 0;
        // for(int i : temp)
        // cout << i << " ";
        // cout << endl;
        for(int i=0; i < temp.size(); i++)
        for(int j=i+1; j < temp.size(); j++)
        sum+=abs(temp[i]-temp[j]);
        ans = min(ans, sum);
        temp.pop_back();
        return;
    }
    int beginIdx = idx, endIdx = idx+1;
    while(endIdx < rngq.size())
    {
        temp.push_back(rngq[endIdx]-rngq[beginIdx]);
        // cout << k << ":" << temp.back() << endl;
        recur(rngq, k+1, endIdx);
        temp.pop_back();
        endIdx++;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> rangeq(n+1);
        for (int i = 0; i < n; i++)
        {
            int A;
            cin >> A;
            rangeq[i+1] = A + rangeq[i];
        }
        ans = INT_MAX;
        recur(rangeq);
        cout << "ans " << ans << endl;
    }
}