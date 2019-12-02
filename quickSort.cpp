#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& array,int low,int high)
{
    int i=low-1;
    int pivot=array[high];

    for(int j=low;j<high;j++)
    {
        if(array[j]<=pivot)
        {
            i++;
            int t=array[i];
            array[i]=array[j];
            array[j]=t;
        }
    }
    int t=array[i+1];
    array[i+1]=array[high];
    array[high]=t;
    
    return (i+1);
}

void quickHelper(vector<int>& array,int low,int high)
{
    if(low<high)
    {
        int pivIdx=partition(array,low,high);
        quickHelper(array,0,pivIdx-1);
        quickHelper(array,pivIdx+1,high);
    }
}

void quickSort(vector<int>& array)
{
    return quickHelper(array,0,array.size()-1); 
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(6);
    a.push_back(4);
    a.push_back(8);
    a.push_back(7);
    a.push_back(3);
    a.push_back(5);
    quickSort(a);

    for(int i=0;i<array.size();i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}

