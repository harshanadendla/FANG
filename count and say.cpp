#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n) 
{
    int count;
    string ans="1";
    string temp="";
    for(int i=2;i<=n;i++)
    {
        count=1;
        for(int j=0;j<ans.length();j++)
        {
            if(j!=ans.length()-1 && ans[j+1]==ans[j])
            {
                count++;
            }
            else
            {
                temp+=to_string(count)+ans[j];
                count=1;
            }
        }
        ans=temp;
        temp.clear();
    }
    return ans;
}

int main()
{
    int n;
    cout<<"enter n";
    cin>>n;
    cout<<countAndSay(n);
    return 0;
}