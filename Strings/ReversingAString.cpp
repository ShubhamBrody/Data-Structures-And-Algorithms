#include<iostream>
#include <cstring>
using namespace std;


int main()
{
    char arr[1000];
    cin >> arr;

    for(int i = 0; i < strlen(arr) / 2; ++i)
    {
        char temp = arr[i];
        arr[i] = arr[strlen(arr) - 1 - i];
        arr[strlen(arr) - 1 - i] = temp;
    }

    cout << arr;
}