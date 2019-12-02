#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    int c=0;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='1')
	        {
	            c++;
	        }
	    }
	    if(c<=1)
	    {
	        cout<<c<<endl;
	    }
	    else
	    {
	        cout<<(((c*(c-1))/2)+c)<<endl;
	    }
	}
	return 0;
}