#include<bits/stdc++.h>

vector<int> Solution::nextGreater(vector<int> &a) 
{
    vector<int> ans(a.size(),-1);
    int n=a.size();
    stack<int> st;
    
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && a[st.top()]<=a[i]) st.pop();
        if(!st.empty()) ans[i]=a[st.top()];
        st.push(i);
    }
    
    return ans;
}   