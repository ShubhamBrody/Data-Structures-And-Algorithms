#include<iostream>
using namespace std;


int main()
{
    char arr[100];
    gets(arr);

    for(int i = 0; arr[i]!='\0'; i++)
    {
        if((int)arr[i] >=65 && (int)arr[i] <=90)
        {
            arr[i] = (char)((int)arr[i] + 32);
        }
        else if((int)arr[i] >=97 && (int)arr[i] <=122)
        {
            arr[i] = (char)((int)arr[i] - 32);
        }
    }
    puts(arr);
}