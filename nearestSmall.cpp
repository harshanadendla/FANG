vector<int> Solution::prevSmaller(vector<int> &a) 
{
    vector<int> res(a.size(),-1);
    stack<int> s;
    for(int i=0;i<a.size();i++)
    {
        while(!s.empty() && s.top()>=a[i]) 
        {
            s.pop();
        }
        if(!s.empty()) res[i]=s.top();
        s.push(a[i]);
    }
    return res;
}