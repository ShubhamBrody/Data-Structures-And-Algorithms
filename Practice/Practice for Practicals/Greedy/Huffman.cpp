#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    char chr = '#';
    Node* left = nullptr;
    Node* right = nullptr;
};

struct cmp{
    bool operator()(Node* p1, Node* p2){
        return p1->value > p2->value;
    }
};

void traversal(Node* root, vector<string> &S, string s = "")
{
    if(!root) return;

    if(root->chr != '#')
    {
        S[root->chr-'a'] = s;
    }
    traversal(root->left, S, s+'0');
    traversal(root->right, S, s+'1');
}

int main(){
    int n;
    cin >> n;

    priority_queue<Node* , vector<Node*>, cmp > pq;

    for(int i =0 ; i < n; i++){
        int a;char b;
        cin >> b >> a;
        Node * temp = new Node;
        temp->value = a;
        temp->chr = b;
        pq.push(temp);
    }

    while(pq.size() > 1)
    {
        Node* n1 = pq.top();
        pq.pop();
        Node * n2 = pq.top();
        pq.pop();

        Node* nn = new Node;
        nn->value = n1->value + n2->value;
        nn->left = n1;
        nn->right = n2;

        pq.push(nn);
    }

    Node* root = pq.top();
    pq.pop();

    vector<string> S(n, "");
    traversal(root, S);

    for(int i = 0; i < n; i++){
        cout << (char)(i+'a') << " --> " << S[i] << endl;
    }
}