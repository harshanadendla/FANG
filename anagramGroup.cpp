#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) 
{
	unordered_map<string,vector<string>> hash;
	for(string word : words)
	{
		string sortedWord=word;
		sort(sortedWord.begin(),sortedWord.end());
		if(hash.find(sortedWord) != hash.end())
		{
			hash[sortedWord].push_back(word);
		}
		else
		{
			hash[sortedWord]=vector<string>{word};
		}
	}
	vector<vector<string>> res;
	for(auto it=hash.begin();it!=hash.end();it++)
	{
		res.push_back(it->second);
	}
	return res;
}

int main()
{
    vector<vector<string>> ans=groupAnagrams({"yo","flap","cat"});
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}