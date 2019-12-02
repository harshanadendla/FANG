#include<iostream>
using namespace std;

int getWays(string s)
{
    int n=s.length();
    int count[n+1];
    count[0]=1;
    count[1]=1;
    for(int i=2;i<=n;i++)
    {
        count[i]=0;
        if(s[i-1]>'0')
        {
            count[i]=count[i-1];
        }
        int x=((s[i-2]-'0')*10 + (s[i-1]-'0'));
        if( x>=10 && x<=26 )
        {
            count[i]+=count[i-2];
        }
    }
    return count[n];
}

int main()
{
    cout<<"enter the string"<<endl;
    string s;
    cin>>s;
    cout<<getWays(s)<<endl;
    return 0;
}