#include "rooting.h"

void TreePrinter(TreeNode* root)
{
    if(root == nullptr) return;
    cout << "Parent : " << root->id << " --> ";
    for(TreeNode* child : root->children){
        cout << child->id <<" ";
    }
    for(TreeNode* child : root->children){
        TreePrinter(child);
    }
    cout << endl;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<bool> V(n, false);
    TreePrinter(dfsRooting(g, V, 0));
}