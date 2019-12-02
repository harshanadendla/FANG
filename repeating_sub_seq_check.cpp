#include<iostream>
using namespace std;

bool check(string s)
{
    vector<vector<int>> lcs(s.size()+1,vector<int>(s.size()+1,0));

    for(int i=0;i<=s.size();i++)
    {
        for(int j=0;j<=s.size();j++)
        {
            if(s[i-1]==s[j-1] && i!=j)
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
            }
            else
            {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
            if(lcs[i][j]==2)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    cout<<check("harsha");
    return 0;
}