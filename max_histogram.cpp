#include<bits/stdc++.h>
using namespace std;

vector<int> pop_greater_rects(vector<int>& pos,vector<int>& ht,int val)
{
    int last_pop_ht;
    int last_pop_pos;
    vector<int> temp(2);
    while(val<ht.back())
    {
        last_pop_ht=ht.back();
        last_pop_pos=pos.back();
        ht.pop_back();
        pos.pop_back();
    }
    temp[1]=last_pop_ht;
    temp[0]=last_pop_pos;
    return temp;
}

int main()
{
    int n;
    cin>>n;
    int area_here=0,area=0;
    vector<int> pos;
    vector<int> a(n);
    vector<int> ht;
    vector<int> temp(2);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    pos.push_back(0);
    ht.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        if(a[i]>ht.back())
        {
            ht.push_back(a[i]);
            pos.push_back(i);
        }
        else if(a[i]<ht.back())
        {
            temp=pop_greater_rects(pos,ht,a[i]);
            area_here=temp[1]*(i-temp[0]);
            area=max(area,area_here);
        }
    }
    for(int i=pos.size()-1;i>=0;i--)
    {
        area_here=ht[i]*(n-pos[i]);
        area=max(area,area_here);
    }
    cout<<area<<"\n";
    return 0;
}