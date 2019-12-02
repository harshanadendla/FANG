#include<bits/stdc++.h>
using namespace std;

void prettyPrint(int n) 
{
    int k=n;
    int l=2*n-1;
    vector<vector<int> > mesh(l,vector<int>(l,1));
    int i=0,j=0;
    int dir=1;
    while(k>1)
    {
        mesh[i][j]=k;
        if(dir==1)
        {
            j++;
            if(j==l || mesh[i][j]!=1)
            {
                i++;
                j--;
                dir=2;
            }
        }
        else if(dir==2)
        {
            i++;
            if(i==l || mesh[i][j]!=1)
            {
                i--;
                j--;
                dir=3;
            }
        }
        else if(dir==3)
        {
            j--;
            if(j<0 || mesh[i][j]!=1)
            {
                i--;
                j++;
                dir=4;
            }
        }
        else if(dir==4)
        {
            i--;
            if(i<0 || mesh[i][j]!=1)
            {
                i++;
                j++;
                dir=1;
                k--;
            }
        }
    }
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<l;j++)
        {
            cout<<mesh[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    prettyPrint(2);
    return 0;
}