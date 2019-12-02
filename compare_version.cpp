#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp> 
using namespace std; 

int Solution::compareVersion(string a, string b) 
{
    vector<string> result1;
    vector<string> result2;
    boost::split(result1,a,boost::is_any_of("."));
    boost::slpit(result2,b,boost::is_any_of("."));
    stringstream ss;
    int k=0;
    while(k<result1.size() && k<result2.size())
    {
        int i,j;
        ss<<result1[k];
        ss>>i;
        ss<<result2[k];
        ss>>j;
        if(i==j)
        {
            k++;
        }
        else if(i<j)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    if(k==result1.size())
    {
        if(k==result2.size())
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    if(k==result2.size())
    {
        return 1;
    }
}