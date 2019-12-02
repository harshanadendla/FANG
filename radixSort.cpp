#include<iostream>
#include<vector>
using namespace std;

int maxElement(vector<int> a)
{
    int max=a[0];
    for(int i=1;i<a.size();i++)
    {
        if(a[i]>=max)
        {
            max=a[i];
        }
    }
    return max;
}

void countSort(vector<int>& a,int exp)
{
    vector<int> counts(10,0);
    vector<int> res(a.size());

    for(int i=0;i<a.size();i++)
    {
        counts[(a[i]/exp)%10]++;
    }
    for(int i=1;i<counts.size();i++)
    {
        counts[i]+=counts[i-1];
    }
    for(int i=a.size()-1;i>=0;i--)
    {
        res[counts[(a[i]/exp)%10]-1]=a[i];
        counts[(a[i]/exp)%10]--;
    }
    for(int i=0;i<res.size();i++)
    {
        a[i]=res[i];
    }
}

void radixSort(vector<int>& a)
{
    int m=maxElement(a);

    for(int exp=1;m/exp>0;exp*=10)
    {
        countSort(a,exp);
    }
}

int main()
{
    vector<int> a;
    a.push_back(342);
    a.push_back(267);
    a.push_back(38);
    a.push_back(8112);
    a.push_back(24);
    a.push_back(143);
    a.push_back(8746);
    a.push_back(3);
    a.push_back(42);
    radixSort(a);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}