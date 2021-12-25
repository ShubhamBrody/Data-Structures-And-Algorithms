#include<iostream>
using namespace std;


int main()
{
    char arr[100];
    gets(arr);

    for(int i = 0; arr[i]!='\0'; i++)
    {
        if(arr[i] != ' ')
        {
            arr[i] = arr[i] ^ 32;
        }
    }
    puts(arr);
}