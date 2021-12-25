#include<bits/stdc++.h>
using namespace std;

int main()
{
    char arr[1000];
    gets(arr);

    long long H = 0, x = 0;

    for(int i = 0; i < strlen(arr); i++)
    {
        x = 1;
        x = x << ((int)(arr[i])-97);

        if((x & H) != 0)
        {
            cout << "Duplicate found : " << arr[i] << " at index : " << i << endl;
        }
        else
        {
            H = x | H;
        }
    }
}