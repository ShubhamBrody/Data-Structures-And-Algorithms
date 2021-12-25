#include<bits/stdc++.h>
using namespace std;

void lpscreater(vector<int> &lps, string pat)
{
    int i = 1, l = pat.length(), len = 0;
    while(i < l)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(string pat, string txt)
{
    vector<int> lps(pat.length(), 0);
    lpscreater(lps, pat);
    bool found = false;
    int i = 0, j = -1, n = txt.length(), m = pat.length();
    //i for txt, j for pat.
    
    while(i < txt.length())
    {
        if(pat[j+1] == txt[i])
        {
            j++;
            i++;
        }
        if(j == m-1)
        {
            cout << "Found the pattern in the text.";
            found = true;
        }
        if(i < n && pat[j+1] != txt[i])
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j = lps[j];
            }
        }
    }
    if(!found)
    cout << "Not found!!";
}

int main()
{
    string pat, txt;
    cin >> txt >> pat;
    kmp(pat, txt);
}