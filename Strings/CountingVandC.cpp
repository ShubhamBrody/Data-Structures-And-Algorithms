#include<iostream>
using namespace std;


int main()
{
    char arr[100];
    gets(arr);
    int vowels = 0, consonants = 0;

    for(int i = 0; arr[i]!='\0'; i++)
    {
        char cr = tolower(arr[i]);
        if(cr == 'a' || cr == 'e' || cr == 'i' || cr == 'o' || cr == 'u')
        {
            vowels++;
        }
        else
        {
            consonants++;
        }
    }
    cout << "Vowels : " << vowels << endl;
    cout << "Consonants : " << consonants << endl;
}