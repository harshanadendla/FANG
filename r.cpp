#include<climits>
#include<vector>
#include <iostream>
using namespace std;

int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    vector<long long int> array(n);
	    vector<long long int> rsum(n);
	    vector<long long int> lsum(n);
	    cin>>array[0];
	    rsum[0]=array[0];
	    for(long long int i=1;i<array.size();i++)
	    {
	        cin>>array[i];
	        rsum[i]=rsum[i-1]+array[i];
	    }
	    lsum[array.size()-1]=array[array.size()-1];
	    for(int i=array.size()-2;i>=0;i--)
	    {
	        lsum[i]=array[i]+lsum[i+1];
	    }
	    long long int maxDish=INT_MIN;
	    for(long long int i=0;i<array.size()-1;i++)
	    {
	        long long int x=abs(rsum[i]-lsum[i+1]);
	        long long int y=abs(rsum[i+1]-lsum[i]);
	        maxDish=max(maxDish,max(x,y));
	    }
	    cout<<maxDish<<endl;
	}
	return 0;
}