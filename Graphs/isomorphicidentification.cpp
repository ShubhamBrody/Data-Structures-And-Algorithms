#include "rooting.h"

vector<int> findcenters(int n, vector<int> g[])
{
    vector<int> degree(n, 0);
    for(int i = 0; i < n; i++)
        degree[i] = g[i].size();
    int count = 0;
    while(count < n)
    {
        if(n-count == 1 || n-count == 2)
        break;
        vector<int> todel;
        for(int i = 0; i < n; i++)
        {
            if(degree[i] == 1)
            {
                todel.pb(g[i][0]);
                degree[i] = -1;
                count++;
            }
        }
        for(int i = 0; i < todel.size(); i++)
        {
            degree[todel[i]]--;
        }
    }
    vector<int> centers;
    for(int i = 0; i < n; i++)
    {
        if(degree[i] > -1)
        centers.pb(i);
    }
    cout << "The roots are : " << centers[0] << endl;
    return centers;
}

struct comp {
    bool operator()(string l, string r)
    {
        return l.length() < r.length();
    }
};

string AHU(TreeNode* root)
{
    vector<string> pats;
    if(root->children.size() == 0)
    {
        return "()";
    }
    for(TreeNode* child : root->children){
        pats.pb(AHU(child));
    }
    sort(pats.begin(), pats.end());
    string megastr = "";
    for(string a : pats)
    {
        megastr += a;
    }
    return "(" + megastr + ")";
}

int main() {
    int n1, m1, n2, m2;
    cout << "Graph-1" << endl;
    cin >> n1 >> m1;
    vector<int> g1[n1];
    vector<int> g2[n1];
    for(int i = 0; i < m1; i++)
    {
        int a, b;
        cin >> a >> b;
        g1[a].pb(b);
        g1[b].pb(a);
    }
    cout << "Graph-2" << endl;
    cin >> n2 >> m2;
    for(int i = 0; i < m2; i++)
    {
        int a, b;
        cin >> a >> b;
        g2[a].pb(b);
        g2[b].pb(a);
    }
    vector<int> ctr1 = findcenters(n1, g1);
    vector<int> ctr2 = findcenters(n2, g2);
    vector<bool> vis1(n1, false);
    TreeNode* gr1 = dfsRooting(g1, vis1, ctr1[0]);
    vector<bool> vis2(n2, false);
    TreeNode* gr2 = dfsRooting(g2, vis2, ctr2[0]);
    cout << AHU(gr1) << endl;
    cout << AHU(gr2) << endl;
    if(AHU(gr1) == AHU(gr2)) cout << "The graphs are isomorphic.\n";
    else cout << "The graphs are not isomorphic.\n";
}