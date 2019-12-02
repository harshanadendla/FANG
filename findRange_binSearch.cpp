#include<iostream>
using namespace std;

int helper(vector<int> array,int target,int left,int right,vector<int>& range,bool goLeft)
{
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(array[mid]<target)
        {
            left=mid+1;
        }
        else if(array[mid]>target)
        {
            right=mid-1;
        }
        else
        {
            if(goLeft)
            {
                if(mid==0 || array[mid-1]!=target)
                {
                    range[0]=mid;
                    return;
                }
                else
                {
                    right=mid-1;
                }
            }
            else
            {
                if(mid==array.size()-1 || array[mid+1]!=target)
                {
                    range[1]=mid;
                    return;
                }
                else
                {
                    left=mid+1;
                }
            }
        }
    }
}

int main()
{
    vector<int> range{-1,-1};
    helper(array,target,0,array.size()-1,range,true);
    helper(array,target,0,array.size()-1,range,false);
    return range;
}