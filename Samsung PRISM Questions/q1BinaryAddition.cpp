#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b, sum = "";
    cin >> a >> b; 

    int carry = 0;
    int i = a.length() - 1, j = b.length() - 1;
    while (1)
    {
        if(i < 0 && j < 0 && carry == 0)
        break;
        int n1 = 0, n2 = 0;
        if (i >=0 && a[i] == '1')
            n1 = 1;
        if (j >=0 && b[j] == '1')
            n2 = 1;

        if(i < 0)
        n1 = 0;
        if(j < 0)
        n2 = 0;

        int t = n1 + n2 + carry;
        if (t > 1)
        {
            carry = 1;
            t -= 2;
        }
        else
        {
            carry = 0;
        }

        if(t == 1)
        sum = '1'+sum;
        else
        sum = '0'+sum;

        i--;
        j--;
    }
    cout << sum << endl;
}