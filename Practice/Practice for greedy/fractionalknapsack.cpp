#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<float, int>> W(n);

    for(int i = 0; i < n; i++){
        int w, v;
        cin >> w >> v;
        W[i] = {v/w, w};
    }
    // for(int i = 0; i < n; i++){
    //     cout << W[i].first << " " << W[i].second << endl;
    // }
    int w, profit = 0;
    cin >>w;
    auto cmp = [](pair<int, int> p1, pair<int, int> p2){return p1.first > p2.first;};
    sort(W.begin(), W.end(), cmp);

    for(int i = 0; i < n; i++){
        if(W[i].second <= w){
            profit += (W[i].first * W[i].second);
            w -= W[i].second;
        }
        else
        {
            profit += (W[i].first * w);
            w -= W[i].second;
            break;
        }
    }

    cout << profit;

}