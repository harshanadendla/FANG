#define mod 10000003
#define ll long long int
ll painT(vector<int> a,int limit)
{
    ll sum=0;
    ll painters=1;
    for(ll i=0;i<a.size();i++)
    {
        sum+=a[i];
        if(sum>limit)
        {
            sum=a[i];
            painters++;
        }
    }
    return painters;
}

int Solution::paint(int k, int cost, vector<int> &times) 
{
    ll low=INT_MIN;
    for(ll i=0;i<times.size();i++)
    {
        if(times[i]>low)
        {
            low=times[i];
        }
    }
    ll high=accumulate(times.begin(),times.end(),0);
    
    while(low<high)
    {
        ll mid=low+(high-low)/2;
        ll reqPainters=painT(times,mid);
        if(reqPainters<=k)
        {
            high=mid;
        }
        else
        {
            low=mid+1;
        }
    }
    return (int)((low*cost)%mod);
}