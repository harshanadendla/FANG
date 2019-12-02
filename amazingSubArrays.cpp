#include<bits/stdc++.h>
using namespace std;

int amazingSubArrays(string s)
{
    transform(s.begin(),s.end(),s.begin(),::tolower);
    cout<<s;
    int count;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
        {
            count+=(s.length()-i);
        }
    }
    return count;
}

int main()
{
    cout<<amazingSubArrays("harSha");
    return 0;
}