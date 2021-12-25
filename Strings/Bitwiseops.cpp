#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int a, b;
    cin >> a >> b;

    int c = a & b;
    int d = a | b;

    cout << "a and b : " << c << endl;
    cout << "a or b : " << d << endl;
}