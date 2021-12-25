// C++ Implementation of Kosaraju's algorithm to print all SCCs
#include <iostream>
#include <list>
#include <stack>
using namespace std;

int mySqrt(int x) {
        long i=0;
        float x2, y;
        float t = 1.5f;
        
        x2 = x * 0.5f;
        y = x;
        i = * ( long * ) &y;
        i = 0x5f3759df - (i >> 1);
        y = *(float*) &i;
        y = y * (t-(x2*y*y));
        
        return (int)(1/y);
}

int main()
{
	cout << mySqrt(91);
}
