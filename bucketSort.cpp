#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

void bucketSort(vector<float>& a)
{
    vector<vector<float> > buckets(a.size());

    for(int i=0;i<a.size();i++)
    {
        int intoBucket=a.size()*a[i];
        buckets[intoBucket].push_back(a[i]);
    }

    for(int i=0;i<buckets.size();i++)
    {
        sort(buckets[i].begin(),buckets[i].end());
    }
    
    int finalIdx=0;

    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<buckets[i].size();j++)
        {
            a[finalIdx++]=buckets[i][j];
        }
    }
}

int main()
{
    vector<float> a;
    a.push_back(0.456);
    a.push_back(0.56);
    a.push_back(0.6);
    a.push_back(0.3456);
    a.push_back(0.9456);
    a.push_back(0.256);
    a.push_back(0.156);

    bucketSort(a);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}