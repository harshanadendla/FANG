#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    whlie(t--)
    {
        int n;
        cin>>n;
        vector<vector<char>> array(n,vector<char>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>array[i][j];
            }
        }
        vector<vector<bool>> ie(n,vector<bool>(n,false));
        vector<vector<bool>> is(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++)
        {
            if(a[i][n-1]=='#')
            {
                ie[i][n-1]=false;
                is[i][n-1]=false;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=n-2;j>=0;j--)
            {
                ie[i][j]&=ie[i][j+1];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            
        }
    }
    return 0;
}

// complete chey