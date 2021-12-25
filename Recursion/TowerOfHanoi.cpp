#include<iostream>
#define ll long long
using namespace std;


void toh(int n, int A, int B, int C)
{
    if(n == 0)
    return;
    toh(n-1, A, C, B);
    cout << "Move the disc from " << A << " to " << C << " using " << B << ".\n";
    toh(n-1, B, A, C);
}

int main()
{
    int n;//Number of stones in the pile in tile set A.

    //A -> 1, B-> 2, C->3
    cin >> n;
    toh(n, 1, 2, 3);
}