#include<vector>
#include<iostream>
using namespace std;

vector<vectot<int> > buildSequence(vector<int> array,vector<int> seq,int idx,int first)
{
    vector<vector<int> >res={{},{}};
    res[0].push_back(first);
    while(idx!=-1)
    {
        res[1].insert(res.begin(),array[idx]);
        idx=seq[idx];
    }
    return res;
}

vector<vector<int> > lis_sum(vector<int> array)
{
    vector<int> sums=array;
    vector<int> seq(array.size(),-1);
    int maxIdx=0;
    for(int i=1;i<array.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(array[j]<array[i] && sums[i]<=sums[j]+array[i])
            {
                sums[i]=sums[j]+array[i];
                seq[i]=j;
            }
        }
        if(sums[i]>=sums[maxIdx])
        {
            maxIdx=i;
        }
    }
    return buildSequence(array,seq,maxIdx,sums[maxIdx]);
}

int amin()
{
    vecotor<int> a;
    a.push_back(8);
    a.push_back(8);
    a.push_back(8);
    a.push_back(8);
    a.push_back(8);
    a.push_back(8);
    
    vector<vector<int> >res=lis_sum(a);
}