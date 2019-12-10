#include<bits/stdc++.h>
using namespace std;

vector<string> temp;
void partition(string a,vector<vector<string>> &res,vector<vector<bool>> pals,int here) 
{
    if(here==a.length())
    {
        res.push_back(temp);
        return ;
    }
    for(int i=here;i<a.length();i++)
    {
        if(pals[here][i])
        {
            temp.push_back(a.substr(here,i-here+1));
            partition(a,res,pals,i+1);
            temp.pop_back();
        }
    }
}

bool isPal(string s)
{
    int l=0,r=s.length()-1;
    while(l<r)
    {
        if(s[l]!=s[r])
        {
            return false;
        }
        l++,r--;
    }
    return true;
}

int main()
{
    vector<vector<string>> res;
    string a="efe";
    vector<vector<bool>> pals(a.length(),vector<bool>(a.length(),false));
    for(int i=0;i<a.length();i++)
    {
        for(int j=0;j<a.length();j++)
        {
            if(isPal(a.substr(i,j-i+1)))
            {
                pals[i][j]=true;
            }
        }
    }
    partition(a,res,pals,0);
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