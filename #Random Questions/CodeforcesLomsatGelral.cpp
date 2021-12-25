#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
    int nodeVal;
    int colorVal;
    vector<int> connNodes;
}Node;

int N;
vector<Node> nodeArray;
int colSumArr[100000];

void mainWork(int idx)
{
    static int N = nodeArray.size();
    if(idx >= N)
    return;
    int sum = 0;
    int size = nodeArray[idx].connNodes.size();
    int tempArr[N] = {0};
    for(int i = 0; i < size; i++)
    {
        int var = nodeArray[nodeArray[idx].connNodes[i]-1].colorVal;
        if(tempArr[var] != 1)
        {
            tempArr[var]=1;
            sum += var;
        }
    }
    sum  = sum==0?nodeArray[idx].colorVal:sum;
    colSumArr[idx] = sum;
    mainWork(idx+1);
}


int main()
{
    cin >> N;
    for(int i = 1; i < N+1; i++)
    {
        Node temp;
        temp.nodeVal = i;
        cin >> temp.colorVal;
        nodeArray.push_back(temp);
    }

    int A, B;
    for(int i = 1; i < N; i++)
    {
        cin >> A;
        cin >> B;
        nodeArray[A-1].connNodes.push_back(B);
    }

    mainWork(0);

    for(int i = 0; i < N; i++)
    {
        cout << colSumArr[i] << " ";
    }
}