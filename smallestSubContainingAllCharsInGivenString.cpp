#include<bits/stdc++.h>
using namespace std;
string smallestSubstringContaining(string bigS, string smallS) 
{
	if(smallS.length()>bigS.length())
	{
		return "";
	}
	unordered_map<char,int> hash;
	unordered_map<char,int> mp;
	vector<int> ans(2);
	ans[0]=INT_MIN/2;
	ans[1]=INT_MAX/2;
	int count=0;
	for(int i=0;i<smallS.length();i++)
	{
		hash[smallS[i]]++;
		if(hash[smallS[i]]==1) count++;
		mp[smallS[i]]=0;
	}
	int l=0,r=0,chars=0;
    while(smallS.find(bigS[l]) == string::npos)
	{
		l++;
	}
	l=r;
	while(l<=r && r<bigS.length())
	{
		if(hash.find(bigS[r]) != hash.end())
		{
			mp[bigS[r]]++;
			if(mp[bigS[r]]==hash[bigS[r]])
			{
				chars++;
			}
			while(chars==count)
			{
				if(r-l < ans[1]-ans[0])
				{
					ans[0]=l;
					ans[1]=r;
				}
				if(hash.find(bigS[l]) != hash.end())
                {
                    mp[bigS[l]]--;
				    if(mp[bigS[l]]<hash[bigS[l]]) chars--;
                }
				l++;
			}
			r++;
		}
		else
		{
			r++;
		}
	}
    if(ans[0]==INT_MIN/2) return "";
	return bigS.substr(ans[0],ans[1]-ans[0]+1);
}

int main()
{
    cout<<smallestSubstringContaining("abcd$ef$axb$c$","$$abf");
    return 0;
}