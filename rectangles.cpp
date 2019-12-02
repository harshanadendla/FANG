#include<iostream>
using namespace std;

int numOfRects(int n)
{
    int count=0;
    for(int length=1;length*length<=n;length++)
    {
        for(int height=length;length*height<=n;height++)
        {
            count++:
        }
    }
    return count;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<numOfRects(n)<<endl;
    }
    return 0;
}