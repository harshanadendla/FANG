bool isSafe(int ele,vector<int> a,int idx)
{
    for(int i=0;i<idx;i++)
    {
        if(a[i]==ele) return false;
    }
    return true;
}

bool solve(vector<int> a,vector<vector<int>> &res,vector<int> &temp,int i)
{
    if(i==a.size())
    {
        res.push_back(temp);
        return true;
    }
    for(int j=0;j<a.size();j++)
    {
        if(isSafe(a[j],temp,i))
        {
            temp[i]=a[j];
            solve(a,res,temp,i+1);
            temp[i]=0;
        }
    }
    return false;
}

vector<vector<int> > Solution::permute(vector<int> &a) 
{
    vector<vector<int>> res;
    vector<int> temp(a.size(),0);
    solve(a,res,temp,0);
    return res;
}