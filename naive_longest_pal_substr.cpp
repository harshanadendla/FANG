#include<iostream>
#include<string>
using namespace std;

bool isPal(string s)
{
    int l=0;
    int r=s.length()-1;
    while(l<r)
    {
        if(s[l]!=s[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

string longestPal(string s)
{
    string longest="";
    for(int i=0;i<s.length();i++)
    {
        for(int j=i;j<s.length();j++)
        {
            string substring=s.substr(i,j-i+1);
            if(substring.length()>longest.length() && isPal(substring))
            {
                longest=substring;
            }
        }
    }
    return longest;
}

int main()
{
    string s="abaxyzzyxf";
    cout<<longestPal(s);
    return 0;
}