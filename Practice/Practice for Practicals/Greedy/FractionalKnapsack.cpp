#include <bits/stdc++.h>
using namespace std;
#define PPIIF pair<pair<int, int>, float>

struct cmp{
    bool operator()(PPIIF v1, PPIIF v2){
        return v1.second < v2.second;
    }
};

int main() {
    int n;
    cin >> n;

    priority_queue<PPIIF, vector<PPIIF>, cmp> pq;

    for(int i = 0; i < n; i++){
        int w, v;
        float div;
        cin >> v >> w;
        div = v/w;
        pq.push({{w, v} , div});
    }


    int t;
    cin >> t;
    int profit = 0;

    while(t || !pq.empty()){
        PPIIF nn = pq.top();
        pq.pop();
        pair<int, int> pt = nn.first;
        float div = nn.second;

        if(pt.first <= t)
        {
            profit += pt.second;
            t -= pt.first;
        }
        else if(t && pt.first > t)
        {
            profit +=(int) (div * t);
            t = 0;
        }
    }

    cout << "The profit is : " << profit;
}