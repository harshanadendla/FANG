#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a,b,val=0,idx,t;
    
    cin>>t;
    while(t--)
    {
        val=0;
        cin>>a>>b;
    
        int len=max(64-__builtin_clzll(a),64-__builtin_clzll(b));
    
        for(int i=0;i<len;i++)
        {
            int temp=a^b;

            if(temp > val)
            {
                val=temp;
                idx=i;
            }

            b=(b>>1)|((b%2)<<len-1);
        }
        
        cout<<idx<<" "<<val<<"\n";
    }
    
	return 0;
}