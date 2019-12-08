#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

int sum=0;
int checkSum(TreeNode* a,int target)
{
    sum+=a->val;
    if(a->left) checkSum(a->left,target);
    if(sum==target) return 1; 
    if(a->right) checkSum(a->right,target);
    if(!a->left && !a->right && sum==target) return ;
    sum-=a->val;
}

int main()
{
    TreeNode *a=new TreeNode(5);
    a->left=new TreeNode(6);
    a->right=new TreeNode(7);
    a->left->left=new TreeNode(8);
    a->left->left->right=new TreeNode(9);
    int target=28;
    checkSum(a,target,sum);
    cout<<sum<<endl;
    if(sum==target) cout<<"found"<<endl;
    else cout<<"No"<<endl;
}