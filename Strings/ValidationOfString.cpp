//Here the string will be rendered invalid if it contains special characters
#include<iostream>
using namespace std;

bool isValid(char arr[])
{
    for(int i = 0; arr[i]!='\0'; i++)
    {
        char c = arr[i];
        if(!((int)c >= 65 && (int)c <= 90) && !((int)c >= 97 && (int)c <= 122) && !((int)c >=48 && (int)c <= 57))
        return false;
    }
    return true;
}


int main()
{
    char arr[100];
    gets(arr);
    if(isValid(arr))
    {
        cout << "The string is Valid.";
    }
    else
    {
        cout << "The string is invalid.";
    }
}