#include "rooting.h"

TreeNode* dfsRooting(vector<int> g[], vector<bool> &V, int id, TreeNode* parent) {
    TreeNode* node = new TreeNode;
    node->id = id;
    node->parent = parent;
    for(int nid : g[id]) {
        if(!V[nid])
        {
            V[nid] = true;
            node->children.pb(dfsRooting(g, V, nid, node));
        }
    }
    return node;
}
//g++ -c rooting.cpp (this current file is to be compiled)
//g++ -c filethatisusingrooting.cpp (the using file is to be compiled)
//g++ -o newnameforexecfile rooting.o filethatisusingrooting.o