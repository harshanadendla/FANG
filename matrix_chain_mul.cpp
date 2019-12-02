#include<climits>
#include<vector>
#include<iostream>
using namespace std;

int mcm(vector<int> p)
{
    vector<vector<int> >m(p.size(),vector<int>(p.size()));
   // vector<vector<int> >brackets(p.size()+1,vector<int>(p.size()+1)); 

    for(int i=1;i<p.size();i++)
    {
        m[i][i]=0;
    }

    for(int l=2;l<p.size();l++)
    {
        for(int i=1;i<=p.size()-l+1;i++)
        {
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int cost=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(cost<=m[i][j])
                {
                    m[i][j]=cost;
                   // brackets[i][j]=k;
                }
            }
        }
    }
    return m[1][p.size()-1];
}

int main()
{
    vector<int> p;
    p.push_back(3);
    p.push_back(4);
    p.push_back(2);
    p.push_back(3);
    p.push_back(1);
    cout<<mcm(p)<<endl;
    return 0;
}