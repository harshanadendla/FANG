#include <bits/stdc++.h>>
using namespace std;

vector<vector<int> > fourNumberSum(vector<int> array, int target) 
{
	unordered_map<int,vector<vector<int>>>hash;
	vector<vector<int>> ans;
	for(int i=0;i<array.size()-1;i++)
	{
		for(int j=i+1;j<array.size();j++)
		{
            int sum=array[i]+array[j];
			if(hash.find(target-sum) != hash.end())
            {
                for(vector<int> pair : hash[target-sum])
                {
                    pair.push_back(array[i]);
                    pair.push_back(array[j]);
                    ans.push_back(pair);
                }
            }
        }
        for(int k=0;k<i;k++)
        {
            int sum=array[i]+Array[k];
            if(hash.find(sum) != hash.end())
            {
                hash[sum].push_back({array[i],array[k]});
            }
            else
            {
                hash[sum]=vector<vector<int>>{{array[i],array[k]}};
            }
            
        }
	}
    return 0;   
}