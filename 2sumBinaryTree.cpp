bool 2sumInBinaryTree(TreeNode* a,int target) {
    stack<TreeNode*> s1,s2;
    TreeNode* temp1=a;
    TreeNode* temp2=a;
    while(temp1) {
        s1.push(temp1);
        temp1=temp1->left;
    }
    while(temp2) {
        s2.push(temp2);
        temp2=temp2->right;
    }
    temp1=s1.top();
    temp2=s2.top();
    while(temp1 && temp2 && temp1->val < temp2->val) {
        if(temp1->val + temp2->val == target) {
            return true;
        } else if(temp1->val + temp2->val < target) {
            s1.pop();
            temp1=temp1->right;
            while(temp1) {
                s1.push(temp1);
                temp1=temp1->left;
            }
            temp1=s1.top();
        } else {
            s2.pop();
            temp2=temp2->left;
            while(temp2) {
                s2.push(temp2);
                temp2=temp2->right;
            }
            temp2=s2.top();
        }
    }
    return false;
}
