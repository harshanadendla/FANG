#include<vector>
#include<iostream>
using namepspace std;

vector<int> buildSequence(vector<int> seq,vector<int> array,int idx)
{
    vector<int> res;
    while(idx!=-1)
    {
        res.insert(res.begin(),array[idx]);
        idx=seq[idx];
    }
    retrun res;
}

int binarySearch(int low,int high,vector<int> indices,vector<int> array,int target)
{
    if(low>high)
    {
        return low;
    }
    int mid=(low+high)/2;
    if(array[indices[mid]]<target)
    {
        low=mid+1;
    }
    else
    {
        high=mid-1;
    }
    return binarySearch(low,high,indices,array,target);
}

vector<int> lis(vector<int> array)
{
    vector<int> seq(array.size(),-1);
    vector<int> indices(array.size()+1,-1);
    int maxIdx=0;

    for(int i=0;i<array.size();i++)
    {
        int curr=array[i];
        int newLength=binarySearch(1,maxidx,indices,array,curr);
        seq[i]=indices[newLength-1];
        indices[newLenght]=i;
        maxIdx=max(newLength,maxIdx);
    }
    return buildSequence(seq,array,indices[maxIdx]);
}

int main()
{
    vector<int> a;
    a.push_back(4);
    a.push_back(5);
    a.push_back(2);
    a.push_back(3);
    a.push_back(8);
    a.push_back(4);
    a.push_back(9);
    a.push_back(0);
    a.push_back(1);
    vector<int>b=lis(a);
    for(int i=0;i<array.size();i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}