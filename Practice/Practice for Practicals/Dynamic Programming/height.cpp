int lvl = 0, dpth = -1;
void traversal(TreeNode* node, int i=0)
{
    if(!node) {
        lvl = max(lvl, i-1);
        return;

    }
    traversal(node->left, i+1);
    traversal(node->right, i+1);
}

bool traversal2(TreeNode* node, TreeNode* target, int i = 0)
{
    if(!node) return false;
    if(node == target){
         dpth = i;
         return true;
    }
    if(traversal(node->left, target, i+1)) return true;
    if(traversal(node->right, target, i+1)) return true;
    return false;
}

int height(TreeNode* node)
{
    traversal(node);
    return lvl;
}

int depth(TreeNode* node, TreeNode* target)
{
    if(!traversal2(node, target)) return -1;
    else return dpth;
}

void preorder(TreeNode* node)
{
    if(node) return;
    cout << node->val;
    preorder(node->left);
    preorder(node->right);
}

void postorder(TreeNode* node)
{
    if(node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->val;
}

void inorder(TreeNode* node)
{
    if(node) return;
    inorder(node->left);
    cout << node->val;
    inorder(node->right);
}

void bfs()
{
    TreeNode* node;
    queue<TreeNode*> q;
    q.push(node);
    while(!q.empty())
    {
        TreeNode* curr = q.front(); q.pop();
        cout << node->val << " ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}