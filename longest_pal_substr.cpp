#include<vector>
#include<iostream>
#include<string>
#define v vector<int>
using namespace std;

v getLongPal(string s,int l,int r)
{
    v ll;
    while(l>=0 && r<=s.length())
    {
        if(s[l]!=s[r])
        {
            break;
        }
        l--;
        r++;
    }
    ll.push_back(l+1);
    ll.push_back(r);
    return ll;
}

string longestPalSubstr(string s)
{
    v longest;
    longest.push_back(0);
    longest.push_back(1);

    for(int i=1;i<s.length();i++)
    {
        v odd=getLongPal(s,i-1,i+1);
        v even=getLongPal(s,i-1,i);
        v currLong=( (odd[1]-odd[0]>even[1]-even[0]) ? odd : even );
        longest=( (currLong[1]-currLong[0]>longest[1]-longest[0]) ? currLong : longest );
    }
    return s.substr(longest[0],longest[1]-longest[0]);
}

int main()
{
    string s="abaxyzzyxf";
    cout<<longestPalSubstr(s);
    return 0;
}