#include<bits/stdc++.h>
using namespace std;
int a;
int lcs(string s1, string s2, int i = 0, int j = 0)
{
    if(s1[i] == '\0' || s2[j] == '\0')
    return 0;

    if(s1[i] == s2[j])
    return (1 + lcs(s1, s2, i+1, j+1));
    else
    return max(lcs(s1,s2,i,j+1), lcs(s1,s2,i+1,j));
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "The longest common subsequence is : " << lcs(s1, s2);
}