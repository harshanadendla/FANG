#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int> array,int target,int left,int right)
{
    while(left<=right)
    {
        int mid=(left+right)/2;
        int l_num=array[left];
        int r_num=array[right];
        int dummy=array[mid];

        if(dummy==target)
        {
            return mid;
        }
        else if(l_num<=dummy)
        {
            if(target>=l_num && target<dummy)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        else
        {
            if(target>dummy && target<=r_num)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
    }
    return -1;
}

int search(vector<int> array,int target)
{
    return helper(array,target,0,array.size()-1);
}

int main()
{
    vector<int> a;
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    cout<<search(a,6);
    return 0;
}