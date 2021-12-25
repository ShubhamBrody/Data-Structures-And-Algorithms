#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    string s = "";
    while(num > 0)
    {
        s = (char)(num % 26 + 64) + s;
        num /= 26;
    }
    cout << s;
}