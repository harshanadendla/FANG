#include<math.h>
#include<vector>
#include<unordered_map>
#include<numeric>
#include<algorithm>

using namespace std;

#define vc vector<char>
#define vs vector<string>

vc getNewPattern(string pattern)
{
    vc newPattern(pattern.begin(),pattern.end());
    if(pattern[0]=='y')
    {
        for(int i=0;i<pattern.size();i++)
        {
            newPattern[i]=(newPattern[i]=='x') ? 'y' : 'x' ;
        }
    }
    return newPattern;
}

int getCountsAndYPos(vc newPattern,unordered_map<char,int>& counts)
{
    int ypos=-1;
    for(int i=0;i<newPattern.size();i++)
    {
        counts[newPattern[i]]++;
        if(newPattern[i]=='y' && ypos==-1)
        {
            ypos=i;
        }
    }
    return ypos;
}

vector<string> patternMatcher(string pattern,string str)
{
    if(pattern.length() > str.length())
    {
        return vs {};
    }
    vc newPattern=getNewPattern(pattern);
    bool change=(newPattern[0]!=pattern[0]);
    unordered_map<char,int> counts {{'x',0},{'y',0}};
    int ypos=getCountsAndYPos(newPattern,counts);
    if(counts['y'!=0])
    {
        for(int xlen=1;xlen<str.size(),xlen++)
        {
            int ylen=((double)str.length()-(double)xlen*(double)counts['x'])/(double)counts['y'];
            if(ylen<=0 || fmod(ylen,1)!=0)
            {
                return vs{};
            }
            int yidx=ypos*xlen;
            string x=str.substr(0,xlen);
            string y=str.substr(yidx,ylen);
            vs curr(newPattern.size(),"");
            transform(newPattern.begin(),newPattern.end(),curr.begin(),[x,y](char c)->string{return c=='x' x : y;});
            if(str==accumulate(curr.begin(),curr.end(),string("")))
            {
                return change ? vs {y,x} : {x,y} ;
            }
        } 
    }
    else
    {
        int xlen=(double)str.length()/(double)counts['x'];
        if(fmod(xlen,1)==0)
        {
            string x=str.substr(0,xlen);
            vs curr(newPattern.size(),"");
            transform(newPattern.begin(),newPattern.end(),curr.begin(),[x](char c)->string{return x;});
            if(str==accumulate(curr.begin(),curr,end(),string())
            {
                return change ? vs {"",x} : vs {x,""};
            }
        }
    }
    return vs {};
}