#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream &operator<<(ostream &stream, const vector<T> &vec)
{
    for (T t : vec)
        stream << t << " ";
    stream << endl;
    return stream;
}

int calcsize(int n)
{
    int x = ceil(log2(n));
    return pow(2, x + 1) - 1; // X leaf nodes and X-1 nodes that are above it... so X + X - 1 -> 2X-1 where X = 2^x;
}

int fillsegtreeutil(vector<int> &segtree, vector<int> &elems, int sl, int sr, int idx)
{
    if (sl == sr)
        return segtree[idx] = elems[sr];
    int mid = sl + (sr - sl) / 2;
    segtree[idx] = fillsegtreeutil(segtree, elems, sl, mid, 2 * idx + 1) + fillsegtreeutil(segtree, elems, mid + 1, sr, 2 * idx + 2);
    return segtree[idx];
}

void fillsegtree(vector<int> &segtree, vector<int> &elems)
{
    fillsegtreeutil(segtree, elems, 0, elems.size() - 1, 0);
}

int rangequery(vector<int> &segtree, int ql, int qr, int sl, int sr, int idx)
{
    if(qr < sl || ql > sr)
    return 0;
    if(ql <= sl && qr >= sr) return segtree[idx];
    int mid = sl + (sr - sl)/ 2;
    return rangequery(segtree, ql, qr, sl, mid, 2 * idx + 1) + rangequery(segtree, ql, qr, mid+1, sr, 2 * idx + 2);
}

void updatetreeutil(vector<int> &segtree, int index, int diff, int sl, int sr, int idx)
{
    if (sl == sr)
    {
        segtree[idx] += diff;
        return;
    }
    segtree[idx] += diff;
    int mid = sl + (sr - sl) / 2;
    if (index <= mid)
        updatetreeutil(segtree, index, diff, sl, mid, 2 * idx + 1);
    else
        updatetreeutil(segtree, index, diff, mid + 1, sr, 2 * idx + 2);
}

void updatesegtree(vector<int> &segtree, vector<int> &elems, int index, int newvalue)
{
    int diff = newvalue - elems[index];
    elems[index] = newvalue;
    updatetreeutil(segtree, index, diff, 0, elems.size() - 1, 0);
}

int main()
{
    int n;
    cout << "Input the number of elements : \n";
    cin >> n;
    vector<int> elems(n);
    cout << "Input the elements to be filled : \n";
    for (int &a : elems)
        cin >> a;
    int size = calcsize(n);
    vector<int> segtree(size);
    fillsegtree(segtree, elems);
    cout << "The segtree is as follows : \n";
    cout << segtree;
    int q;
    cout << "Enter the number of queries : \n";
    cin >> q;
    while (q--)
    {
        int i, a, b;
        cin >> i >> a >> b;
        if(i == 1)
        {
            updatesegtree(segtree, elems, a, b);
            cout << segtree;
        }
        else
        cout << rangequery(segtree, a, b, 0, n-1, 0);
    }
}