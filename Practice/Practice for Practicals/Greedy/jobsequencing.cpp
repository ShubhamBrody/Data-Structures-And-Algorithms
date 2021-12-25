#include<bits/stdc++.h>
using namespace std;
#define VEC vector<pair<int, int>> 

int main(){
    int n;
    cin >> n;

    VEC V(n);
    for(int i = 0; i < n; i++){
        int profit, timelimit;
        cin >> profit >> timelimit;
        V[i] = {profit, timelimit};
    }

    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());

    int tl;
    cin >> tl;
    int profit = 0;

    vector<bool> vis(tl+1, false);
    for(int i = 0; i < n; i++){
        int k = V[i].second;
        while(k != 0)
        {
            if(vis[k])
            {
                k--;
            }
            else
            break;
        }
        if(k != 0)
        {
            vis[k] = true;
            profit += V[i].first;
        }
    }

    cout << "The max profit is : " << profit << endl;
}