#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets_iter(vector<int> &a) 
{
    if(a.size()==0) return {{}};
    sort(a.begin(),a.end());
    vector<vector<int>> res={{}};
    for(int i=0;i<a.size();i++)
    {
        int k=res.size();
        for(int j=0;j<k;j++)
        {
            vector<int> t=res[j];
            t.push_back(a[i]);
            res.push_back(t);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

void subsets_backTrack(vector<int> &a,vector<vector<int>> &res,int here,vector<int> &temp)
{
    res.push_back(temp);
    for(int i=here;i<a.size();i++)
    {
        temp.push_back(a[i]);
        subsets_backTrack(a,res,i+1,temp);
        temp.pop_back();
    }
}

int main()
{
    vector<int> a={1,2,3};
    vector<vector<int>> res=subsets_iter(a);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    res.clear();
    vector<int> temp={};
    subsets_backTrack(a,res,0,temp);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}