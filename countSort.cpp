#include<iostream>
#include<vector>
using namespace std;

vector<int> countSort(vector<int> a)
{
    vector<int> counts(10);
    vector<int> res(a.size());

    for(int i=0;i<a.size();i++)
    {
        counts[a[i]]++;
    }
    for(int i=1;i<counts.size();i++)
    {
        counts[i]+=counts[i-1];
    }
    for(int i=0;i<res.size();i++)
    {
        res[counts[a[i]]-1]=a[i];
        counts[a[i]]--;
    }
    for(int i=0;i<a.size();i++)
    {
        a[i]=res[i];
    }
    return res;
}

int main()
{
    vector<int> a;
    a.push_back(9);
    a.push_back(1);
    a.push_back(3);
    a.push_back(9);
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    a=countSort(a);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}