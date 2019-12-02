#include<vector>
#include<climits>
#include<algorithm>
#include <iostream>
#define ll long long int
using namespace std;

int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    vector<ll> dists(n);
	    vector<ll> bunks(n);
	    
	    cin>>dists[0];
	    dists[0]*=2;
	    ll maxD=dists[0];
	    for(ll i=1;i<n;i++)
	    {
	        cin>>dists[i];
	        dists[i]*=2;
	        maxD=max(maxD,dists[i]);
	    }
	    for(ll i=0;i<n;i++)
	    {
	        cin>>bunks[i];
	    }
	    sort(bunks.begin(),bunks.end());
	    vector<ll> times(maxD+1,LLONG_MAX);
	    times[0]=0;

	    for(int j=0;j<bunks.size();j++)
	    {
            ll denom=bunks[j];
	        for(int amount=1;amount<times.size();amount++)
	        {
	            if(denom<=amount)
	            {
	                if(times[amount-denom]!=LLONG_MAX)
	                {
	                    times[amount]=min(times[amount],times[amount-denom]+1);
	                }
	            }
            }
	    }
        for(int i=0;i<times.size();i++)
        {
            cout<<times[i]<<" ";
        }
        cout<<endl;
	    ll sum=0;
	    for(ll i=0;i<dists.size();i++)
	    {
	        sum+=times[dists[i]];
	    }
	    cout<<sum<<endl;
	}
	return 0;
}