#include<iostream>
#include<vector>
#include<string>
#include<numeric>
using namespace std;

string underscorify(string S,vector<vector<int> > locations)
{
    vector<string> res {};
    int stridx=0;
    int locationsidx=0;
    bool inbetweenunderscores=false;
    int i=0;
    while(stridx<S.length() && locationsidx<locations.size())
    {
        if(stridx==locations[locationsidx][i])
        {
            res.push_back("_");
            inbetweenunderscores=!inbetweenunderscores;
            if(!inbetweenunderscores)
            {
                locationsidx++;
            }
            i=(i==1) ? 0 : 1 ;
        }
        string s(1,stridx);
        res.push_back(s);
        stridx++;
    }
    if(locationsidx<locations.size())
    {
        res.push_bak("_");
    }
    else if(stridx<S.length())
    {
        res.push_back(S.substr(stridx));
    }
    return accumulate(res.begin(),res.end(),string());
}

vector<vector<int> > collapse(vector<vector<int> > locations)
{
    if(locations.size()==0)
    {
        return locations;
    }
    vector<vector<int> > newlocations {locations[0]};
    vector<int>* prev=&newlocations[0];
    while(int i=1;i<locations.size();i++)
    {
        vector<int>* curr=&locations[i];
        if(curr->at(0) <= prev->at(1))
        {
            prev->at(1)=curr->at(1);
        }
        else
        {
            newlocations.push_back(*current);
            prev=&newlocations.back();
        }
    }
    return newlocations;
}

vector<vector<int> > getLocations(string S,string s)
{
    vector<vector<int> > locations {};
    int startidx=0;
    while(startidx<S.length())
    {
        int nextIdx=S.find(s,startidx);
        if(nextIdx != string::npos)
        {
            locations.push_back({nextIdx,nextIdx+s.length()});
            startidx=nextIdx+1;
        }
    }
    return locations;
}

string underScorify(string S,string s)
{
    vector<vector<int> > locations=collapse(getLocations(S,s));
    return underscorify(S,locations);
}

int main()
{
    string S="harsha is a harsh harsha";
    string s="harsh";
    cout<<underScorify(S,s);
    return 0;
}