#include<vector>
#include<iostream>
using namespace std;

void swap(int* a,int& b)
{
    int t=*a;
    *a=b;
    b=t;
}

int partition(vector<int>& array,int low,int high)
{
    int i=low-1;
    int pivot=array[high];
    for(int j=low;j<high;j++)
    {
        if(array[j]<=pivot)
        {
            i++;
            swap(&array[i],array[j]);
        }
    }
    swap(&array[i+1],array[high]);
    return (i+1);
}

int selectHelper(vector<int>& array,int low,int high,int pos)
{
    if(low<high)
    {
        int piv_idx=partition(array,low,high);
        if(piv_idx == pos)
        {
            return array[piv_idx];
        }
        else if(pos < piv_idx)
        {
            return selectHelper(array,low,piv_idx-1,pos);
        }
        else
        {
            return selectHelper(array,piv_idx+1,high,pos);
        }
    }
}

int quickSelect(vector<int>& array,int pos)
{
    return selectHelper(array,0,array.size()-1,pos);
}

int main()
{
    vector<int> a;
    a.push_back(3);
    a.push_back(9);
    a.push_back(8);
    a.push_back(-1);
    a.push_back(67);
    a.push_back(2);
    a.push_back(5);
    a.push_back(4);
    int k;
    cin>>k;
    cout<<quickSelect(a,k-1);
    return 0;
}