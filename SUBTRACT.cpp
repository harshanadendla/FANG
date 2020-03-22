    #include<bits/stdc++.h>
#define ln ListNode

ListNode* Solution::subtract(ListNode* A) 
{
    ln *ans=A;
    ln *temp=A;
    vector<int> a;
    
    while(temp)
    {
        a.push_back(temp->val);
        temp=temp->next;
    }
    reverse(a.begin(),a.end());
    int n=a.size();
    
    for(int i=0;i<n/2;i++)
    {
        A->val=a[i]-A->val;
        A=A->next;
    }
    
    return ans;
}