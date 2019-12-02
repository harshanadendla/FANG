#include<iostream>
using namespace std;

int minCharsToMakeItAPal(String s)
{
    int l=0,r=s.length()-1,end=s.length()-1;
    while(l<r)
    {
        if(s[l]==s[r])
        {
            l++;
            r--;
        }
        else
        {
            l=0;
            r=--end;
        }
    }
    return s.length()-end-1;
}

int main()
{
    string s;
    cin>>s;
    cout<<minCharsToMakeItAPal(s);
    return 0;
}