#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int num;
    Node *next;

} Node;



int main()
{
    Node head, tail;
    int n;
    cout << "Please Enter the Value of N : " << endl;
    cin >> n;
    Node *node = new Node[n];
    head.next = &node[0];
    //head->next = &node[0];
    tail.next = nullptr;
    cout << "hlo" << endl;

    for(int i = 0; i < n; i++)
    {
        node[i].num = i+1;
        if(i != n-1)
        {
            node[i].next = &node[i+1];
        }
        else
        {
            node[i].next = &tail;
        }
    }

    cout << "Now displaying the elements : " << endl;

    Node *temp = &head;
    while(temp->next->next != nullptr)
    {
        temp = temp->next;
        cout << temp->num << " -> ";
    }
    //cout << temp->next->num;
}