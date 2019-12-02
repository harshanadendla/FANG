#include<vector>
#include<iostream>
using namespace std;

int max_sum(vector<int> array)
{
    int maxHere=array[0];
    int maxSoFar=array[0];
    for(int i=1;i<array.size();i++)
    {
        int curr=array[i];
        maxHere=max(curr,maxHere+curr);
        maxSoFar=max(maxHere,maxSoFar);
    }
    return maxSoFar;
}

int main()
{
    vector<int> a;
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    a.push_back(6);
    a.push_back(5);
    cout<<max_sum(a);
    return 0;
}