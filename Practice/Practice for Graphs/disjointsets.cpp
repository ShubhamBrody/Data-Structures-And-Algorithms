#include<bits/stdc++.h>
using namespace std;

int find(int i, vector<int> &roots)
{
    while(roots[i] != i)
    i = roots[i];
    return i;
}

void unioncalc(int i, int j, vector<int> &roots, vector<int> &sizes)
{
    int pi = find(i, roots), pj = find(j, roots);
    if(roots[pi] == roots[pj]) return;

    if(roots[pi] < roots[pj])
    {
        roots[pj] = roots[pi];
        sizes[pi] += sizes[pj];
        sizes[pi] = 0;
    }
    else 
    {
        roots[pi] = roots[pj];
        sizes[pj] += sizes[pi];
        sizes[pj] = 0;
    }
}

int main() {
    int n = 9;
    // cin >> n;

    vector<pair<int, int>> edges;
    vector<int> roots(n);
    iota(roots.begin(), roots.end(), 0);
    // for(int fk : roots)
    // cout << fk << endl;
    vector<int> sizes(n, 1);

    unioncalc(1, 2, roots, sizes);
    unioncalc(2, 3, roots, sizes);
    unioncalc(4, 5, roots, sizes);
    unioncalc(6, 7, roots, sizes);
    unioncalc(7, 8, roots, sizes);

    for(int fk : roots)
    cout << fk << endl;
}