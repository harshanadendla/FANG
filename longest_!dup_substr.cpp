#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

string longestWithoutDups(string str)
{
    unordered_map<char,int> lastseen;
    v longest {0,1};
    int startIdx=0;

    for(int i=0;i<str.length();i++)
    {
        char c=s[i];
        if(lastseen[c] != lastseen.end())
        {
            startIdx=max(startIdx,lastseen[c]+1);
        }
        if(longest[1]-longest[0]<i+1-startIdx)
        {
            longest={startIdx,i+1};
        }
        lastseen[c]=i;
    }
    return str.substr(longest[0],longest[1]-longest[0]);
}

int main()
{
    string str="harshakumbi";
    cout<<longestWithoutDups(str);
    return 0;
}