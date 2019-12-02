#inlcude<bits/stdc++.h>
using namespace std;

int waterArea(vector<int> array)
{
    vector<int> lmaxes(array.size());
    vector<int> rmaxes(array.size());
    int area=0;

    int lmax=0;
    for(int i=0;i<array.size();i++)
    {
        int curr=array[i];
        lmaxes[i]=lmax;
        lmax=max(lmax,curr);
    }

    int lmax=0;
    for(int i=0;i<array.size();i++)
    {
        int curr=array[i];
        lmaxes[i]=lmax;
        lmax=max(lmax,curr);
    }

    int rmax=0;
    for(int i=array.size()-1;i>=0;i--)
    {
        int curr=array[i];
        rmaxes[i]=rmax;
        rmax=max(rmax,curr);
    }

    int rmax=0;
    for(int i=array.size()-1;i>=0;i--)
    {
        int curr=array[i];
        rmaxes[i]=rmax;
        rmax=max(rmax,curr);
    }

    for(int i=0;i<array.size();i++)
    {
        if(array[i]<min(lmaxes[i],rmaxes[i]))
        {
            area+=(min(lmaxes[i],rmaxes[i])-array[i]);
        }
    }
	return area;
}

int main()
{
    cout<<waterArea(array)<<endl;
    return 0;
}