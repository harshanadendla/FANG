#include<bits/stdc++.h>
using namespace std;

bool helper(string one,string two,string three,int i,int j,vector<vector<int>>& hash)
{
    if(hash[i][j]!=-1)
    {
        return hash[i][j];
    }
    int k=i+j;
    if(k==three.length())
    {
        return true;
    }
    if(i<one.length() && one[i]==three[k])
    {
        hash[i][j]=helper(one,two,three,i+1,j,hash);
        if(hash[i][j]) return true;
    }
    if(j<two.length() && two[j]==three[k])
    {
        hash[i][j]=helper(one,two,three,i,j+1,hash);
        if(hash[i][j]) return true;
    }
    hash[i][j]=false;
    return false;
}

bool interweavingStrings(string one,string two,string three)
{
    if(one.length()+two.length() != three.length())
    {
        return false;
    }
    vector<vector<int>> hash(one.length()+1,vector<int>(two.length()+1,-1));
    return helper(one,two,three,0,0,hash);
}

int main()
{
    cout<<interweavingStrings("aaa","aaaf","aaafaaa");
    return 0;
}