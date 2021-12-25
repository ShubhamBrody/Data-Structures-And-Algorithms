#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    char chr = '#';
    Node* left = nullptr;
    Node* right = nullptr;
};

struct cpm {
    bool operator()(Node* p1, Node* p2) {
        return p1->value > p2->value;
    }
};

void traversal(Node *root, vector<pair<char, string>> &A, string s = "")
{
    if(root == nullptr) return;
    if(root->chr != '#')
    A.push_back({root->chr, s});
    // cout << root->chr << " " << root->value << endl;
    traversal(root->left, A, s+"0");
    traversal(root->right, A, s+"1");
}

int main() {
    int n;
    cin >> n;

    // vector<pair<int, char>> H(n);
    priority_queue<Node*, vector<Node*>, cpm> pq;

    for(int i = 0; i < n; i++){
        int a; char c;
        cin >> a >> c;
        Node* ntemp = new Node;
        ntemp->value = a;
        ntemp->chr = c;
        pq.push(ntemp);
    }

    while(pq.size() > 1) {
        Node* v1 = pq.top();
        pq.pop();
        Node* v2 = pq.top();
        pq.pop();
        // cout << v1->value << " " << v2->value << endl;
        // return 0;
        Node* nt = new Node;
        nt->value = v1->value + v2->value;
        // if(v1->chr != '#' && v2->chr)
        nt->left = v1;
        nt->right = v2;
        cout << nt->left->chr << "  " << nt->right->chr << "   " << nt->value << endl;
        pq.push(nt);
    }

    // return 0;

    vector<pair<char, string>> A;
    cout << endl << endl;
    traversal(pq.top(), A);

    for(auto p : A)
    {
        cout << p.first << " ---> " << p.second << endl;
    }
}