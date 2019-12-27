#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// Source https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/

struct box
{
    ll val,idx,prob;
};

vector<box> boxes(100100);
vector<int> tree(100100);

bool how(box a,box b)
{
    if(a.val==b.val) return a.idx<b.idx;
    return a.val<b.val;
}

ll query(ll idx)
{
    ll res=0;
    while(idx>0)
    {
        res+=tree[idx];
        idx-=(idx&(-idx));
    }
    return res;
}

void update(ll idx,ll val)
{
    while(idx<100100)
    {
        tree[idx]+=val;
        idx+=(idx&(-idx));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,d,temp;
        cin>>n>>d;
        for(ll i=1,j=1;i<=n;i++,j++)
        {
            cin>>temp;
            boxes[j].val=temp;
            boxes[j].idx=i;
            j++;
            boxes[j].val=temp+d;
            boxes[j].idx=i;
        }
        for(ll i=1,j=1;i<=n;i++,j++)
        {
            cin>>temp;
            boxes[j].prob=100-temp;
            j++;
            boxes[j].prob=temp;
        }
        fill_n(tree.begin(),2*n,0);
        sort(boxes.begin()+1,boxes.begin()+1+2*n,how);
        double ans=0;
        for(ll i=2*n;i>0;i--)
        {
            ans+=(boxes[i].prob*query(boxes[i].idx-1))/10000.0;
            update(boxes[i].idx,boxes[i].prob);
        }
        printf("%.4lf\n",ans);
    }
    return 0;
}