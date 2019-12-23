#include<bits/stdc++.h>
using namespace std;

void update(vector<int>& segTree,int id,int s,int e,int num)
{
    if(s==num && e==num)
    {
        segTree[id]=1;
        return ;
    }
    if(num<s || num>e)
    {
        return ;
    }
    int mid=(e+s)>>1;
    update(segTree,2*id,s,mid,num);
    update(segTree,2*id+1,mid+1,e,num);

    segTree[id]=segTree[2*id] + segTree[2*id+1];
    return ;
}

int query(vector<int> segTree,int id,int s,int e,int qs,int qe)
{
    if(s>=qs && e<=qe)
    {
        return segTree[id];
    }
    if(e<qs || s>qe)
    {
        return 0;
    }
    int mid=(e+s)>>1;

    return query(segTree,2*id,s,mid,qs,qe) + query(segTree,2*id+1,mid+1,e,qs,qe);
}

int main()
{
    int ans=0;
    vector<int> array={3,2,4,1};
    vector<int> segTree(4*array.size(),0);
    for(int i=0;i<array.size();i++)
    {
        ans+=query(segTree,1,1,4,array[i]+1,4);
        update(segTree,1,1,4,array[i]);
    }
    cout<<"ans :"<<ans;
    return 0;
}