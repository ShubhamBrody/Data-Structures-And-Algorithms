#pragma once
#ifndef ROOT_H
#define ROOT_H
#include<bits/stdc++.h>
#define pb push_back
using namespace std;

struct TreeNode {
    vector<TreeNode*> children;
    TreeNode* parent = nullptr;
    int id;
};

TreeNode* dfsRooting(vector<int>[], vector<bool>&, int, TreeNode* = nullptr);

#endif