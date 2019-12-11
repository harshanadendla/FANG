// VERTICAL FASHION //

#incldue<bits/stdc++.h>
using namespace std;

bool isSafe(int n,vector<string> temp,int row,int col)
{
    for(int i=0;i<n;i++)
    {
        if(temp[i][col]=='Q') return false;
        if(temp[row][i]=='Q') return false;
    }
    for(int i=row,j=col;i<n && j>=0;i++,j--)
    {
        if(temp[i][j]=='Q') return false; 
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(temp[i][j]=='Q') return false;
    }
    return true;
}

bool solve(int n,vector<vector<string> &res,vector<string> &temp,int col)
{
    if(col==n)
    {
        res.push_back(temp);
        return true;
    }
    for(int row=0;row<n;row++)
    {
        if(isSafe(n,temp,row,col))
        {
            temp[row][col]='Q';
            solve(n,res,temp,col+1);
            temp[row][col]='.';
        }
    }
    return false;
}

vecto<vector<string> NQueens(int n)
{
    vector<vector<string>> res;
    vector<string> temp;
    string ans;
    for(int i=0;i<n;i++)
    {
        ans.push_back('.');
    }
    for(int i=0;i<n;i++)
    {
        temp.push_back(ans);
    }
    solve(n,res,temp,0);
    return res;
}