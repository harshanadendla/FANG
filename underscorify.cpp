using namespace std;
#include<vector>
#include<numeric>

string underscorify(string str,vector<vector<int>> locations)
{
	int stringidx=0;
	int locationsidx=0;
	int i=0;
	bool inbetweenunderscores=false;
	vector<string> res{};
	
	while(stringidx<str.length() && locationsidx<locations.size())
	{
		if(stringidx==locations[locationsidx][i])
		{
			res.push_back("_");
			inbetweenunderscores=!inbetweenunderscores;
			if(!inbetweenunderscores)
			{
				locationsidx++;
			}
			i=(i==1) ? 0 : 1 ;
		}
		string s(1,str[stringidx]);
		res.push_back(s);
		stringidx++;
	}
	if(locationsidx<locations.size())
	{
		res.push_back("_");
	}
	else if(stringidx<str.length())
	{
		res.push_back(str.substr(stringidx));
	}
	return accumulate(res.begin(),res.end(),string());
}

vector<vector<int>> collapse(vector<vector<int>> locations)
{
	if(locations.empty())
	{
		return locations;
	}
	vector<vector<int>> newlocations{locations[0]};
	vector<int>* prev=&newlocations[0];
	
	for(int i=1;i<locations.size();i++)
	{
		vector<int>* curr=&locations[i];
		if(curr->at(0) <= prev->at(1))
		{
			prev->at(1)=curr->at(1);
		}
		else
		{
			newlocations.push_back(*curr);
			prev=&newlocations.back();
		}
	}
	return newlocations;
}

vector<vector<int>> getLocations(string str,string sub)
{
	vector<vector<int>> locations{};
	int startIdx=0;
	
	while(startIdx<str.length())
	{
		int nextIdx=str.find(sub,startIdx);
		if(nextIdx != string:: npos)
		{
			locations.push_back({nextIdx,(int)(nextIdx+sub.length())});
			startIdx=nextIdx+1;
		}
		else
		{
			break;
		}
	}
	
	return locations;
}

string underscorifySubstring(string str, string subStr) 
{
  vector<vector<int>> locations=collapse(getLocations(str,subStr));
	return underscorify(str,locations);
}