//Here the string will be rendered invalid if it contains special characters
#include<iostream>
#include<regex>

using namespace std;


int main()
{
    char arr[100];
    gets(arr);
    regex match("[A-Za-z0-9]+");
    if(regex_match(arr, match))
    {
        cout << "The string is Valid.";
    }
    else
    {
        cout << "The string is invalid.";
    }
}