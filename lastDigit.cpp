#include<iostream>
using namespace std;

int power(int a,long long int b)
{
    if(b==0) return 1;
    int f=power(a,b/2);
    f*=f;
    if(f&1) f*=a;
    return f%10;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int a,b;
        cin>>a>>b;
        cout<<power(a%10,b)<<endl;
    }
    return 0;
}