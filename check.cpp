#include<vector>
#include<iostream>
using namespace std;

void rotateTheseFour(int& a,int& b,int& c,int& d)
{
    int t1=a;
    int t2=b;
    int t3=c;
    int t4=d;
    
    a=t4;
    b=t1;
    c=t2;
    d=t3;
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    rotateTheseFour(a[0],a[1],a[2],a[3]);
    for(int i=0;i<4;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}