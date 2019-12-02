#include  <vector>
#include <iostream>
using namespace std;
using namespace std;

int findMax(int low,vector<int> array)
{
	int localMax=low+1;
	int t=low;
	for(int i=low+1;i<array.size();i++)
	{
		if(array[i]>array[t])
		{
			return i;
		}
		if(array[i]>=array[localMax])
		{
			localMax=i;
		}
	}
	return localMax;
}

int waterArea(vector<int> array) 
{
    int maxI=0;
	int area=0;
	int j=0;
	while(array[j]==0)
	{
		j++;
	}
	for(int i=j;i<array.size();)
	{
		int curr=i;
		int maxI=findMax(i,array);
		if(array[i]<array[maxI])
		{
		    while(i<maxI)
		    {
		    	i++;
		   	    area+=(array[curr]-array[i]);
                //    if(i==maxI-1)
                //    {
                //        break;
                //    }
		    }
    	}
		else
		{
			while(i<maxI)
			{
				i++;
				area+=(array[maxI]-array[i]);
                //  if(i==maxI-1)
                //    {
                //        break;
                //    }
			}
		}
	}
	return area;
}

int main()
{
    vector<int> array;
    array.push_back(0);
    array.push_back(8);
    array.push_back(0);
    array.push_back(0);
    array.push_back(5);
    array.push_back(0);
    array.push_back(0);
    array.push_back(10);
    array.push_back(0);
    array.push_back(0);
    array.push_back(1);
    array.push_back(1);
    array.push_back(0);
    array.push_back(3);
    cout<<waterArea(array)<<endl;
    return 0;
}