#include<bits/stdc++.h>
using namespace std;

bool helper(int l,TreeNode *tree,int r)
{
    if(!tree) return true;
    if(tree->val < l || tree->val >=r) return false;
    return helper(l,tree->left,tree->val) && helper(tree->val,tree->right,r);
}

bool validateBst(TreeNode* tree)
{
    if(!tree) return true;
    return helper(INT_MIN,tree,INT_MAX);
}
