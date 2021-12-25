#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c = 0;
    for(int i = 1; i < 101; i++)
    {
        if(i%3==0)
        {
            cout << "Fizz";
            if(i%5==0)
            cout << "Buzz";
        }
        else if(i%5==0)
        {
            cout << "Buzz";
        }
        else
        {
            cout << i;
        }
        cout << endl;
    }
}