#include<iostream>
#include<vector>
using namespace std;

int lis(vector<int> array)
{
    int maxIdx=0;
    vector<int>lis_array(array.size(),1);
    for(int i=1;i<array.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(array[j]<array[i] && lis_array[i]<lis_array[j]+1)
            {
                lis_array[i]=lis_array[j]+1;
            }
        }
        if(lis[i]>=lis[maxIdx])
        {
            maxIdx=i;
        }
    }
    return lis_array[maxIdx];
}

int main()
{
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(3);
    a.push_back(12);
    a.push_back(5);
    a.push_back(6);
    a.push_back(9);
    cout<<lis(a)<<endl;
    return 0;
}