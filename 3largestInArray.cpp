#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void shift(vector<int>& res,int num,int idx)
{
    for(int i=0;i<idx;i++)
    {
        res[i]=res[i+1];
    }
    res[idx]=num;
}

void find3max(vector<int> array,vector<int>& res)
{
    for(int num : array)
    {
        if(num>=res[2])
        {
           shift(res,num,2);
        }
        else if(num>=res[1])
        {
           shift(res,num,1);
        }
        else if(num>=res[0])
        {
           shift(res,num,0); 
        }
    }
}

int main()
{
    vector<int> array {/*.......*/};
    vector<int> res(3,INT_MIN);
    find3max(array,res);
    retrun res;
}