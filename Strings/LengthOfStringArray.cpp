#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char arr[n];
    cin.ignore();
    gets(arr);
    int c = 0;
    for(int i = 0; i < n; i++)
    {
        c++;
        if(arr[i] == '\0')
        {
            cout << "The length of the array is : " << i << endl;
            break;
        }
        
    }
    cout << "Searched over the array for " << c << " times.";
}