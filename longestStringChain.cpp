#include<bits/stdc++.h>
using namespace std;

bool func(string a,string b)
{
    return a.length()<b.length() ;
}

unordered_map<string,int> hashThem(vector<string> words)
{
    unordered_map<string,int> hash;
    for(int i=0;i<words.size();i++)
    {
       hash[words[i]]=i;
    }
    return hash;
}

vector<string> buildSequence(vector<int> seq,vector<string> words,int idx)
{
    vector<string> res;
    while(idx != -1)
    {
        res.push_back(words[idx]);
        idx=seq[idx];
    }
    return res;
}

vector<string> longestStringChain(vector<string> words)
{
    sort(words.begin(),words.end(),func);
    vector<int> seq(words.size(),-1);
    int maxi=0;
    int maxL=1;
    unordered_map<string,int> hash=hashThem(words);
    unordered_map<string,pair<string,int>> bunch;
    for(int j=0;j<words.size();j++)
    {
        string word=words[j];
        bunch[word]=make_pair("",1);
        for(int i=word.length()-1;i>=0;i--)
        {
            string key=word;
            key.erase(key.begin()+i);
            if(hash.find(key) != hash.end())
            {
                if(bunch[word].second<bunch[key].second+1)
                {
                    bunch[word]=make_pair(key,bunch[key].second+1);
                    seq[j]=hash[key];
                    if(maxL<=bunch[key].second+1)
                    {
                        maxL=bunch[key].second+1;
                        maxi=j;
                    }
                }
            }
        }
    }
    if(maxL==1)
    {
        return {};
    }
    return buildSequence(seq,words,maxi);
}

int main()
{
    vector<string> chain={"abcdefg","1234c","abdefg2","abdfg","123","122","bgg","g","1a2345","12a345"};
    vector<string> res=longestStringChain(chain);
    for(string word : res)
    {
        cout<<word<<" ";
    }
    return 8899;
}