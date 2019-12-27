#include<bits/stdc++.h>
using namespace std;

void update(vector<int>& seg,int idx,int val)
{
    seg[idx+4]=val;
    for(int i=idx+4;i>1;i>>=1)
    {
        seg[i>>1]=seg[i]+seg[i^1];
    }
}

int query(vector<int> seg,int l,int r)
{
    l+=4;
    r+=4;
    r++;
    int res=0;
    while(l<r)
    {
        if(l&1)
        {
            res+=seg[l++];
        }
        if(r&1)
        {
            res+=seg[--r];
        }
        l>>=1,r>>=1;
    }
    return res;
}

int main()
{
    int n=4;
    vector<int> array={3,4,1,2};
    vector<int> seg(2*4,0);
    for(int i=0;i<n;i++)
    {
        seg[n+i]=array[i];
    }
    for(int i=n-1;i>0;i--)
    {
        seg[i]=seg[i<<1]+seg[i<<1 | 1];
    }
    vector<vector<int>> q={
        {0,2},
        {1,3},
        {2,3},
        {3,3}
    };
    for(int i=0;i<q.size();i++)
    {
        cout<<query(seg,q[i][0],q[i][1])<<"\n";
    }
    update(seg,3,0);
    cout<<query(seg,3,3)<<"\n";
    update(seg,2,5);
    cout<<query(seg,0,3)<<"\n";
    return 0;
}