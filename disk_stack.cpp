#include<vector>
#include<algorithm>
#define vv vector<vector<int>>
#define flag j_v[0]<i_v[0] && j_v[1]<i_v[1] && j_v[2]<i_v[2]
using namespace std;

vv buildSequence(vv disks,vector<int> seq,int idx)
{
    vv res;
    while(idx!=-1)
    {
        res.inert(res.begin(),disks[idx]);
        idx=seq[idx];
    }
    return res;
}

vv diskStacking(vv disks)
{
    sort(disks.begin(),disks.end(),[](vector<int>& p,vector<int>& q){return p[2]<q[2];});
    int maxIdx=0;

    vector<int> heights;
    for(vector<int> disk : disks)
    {
        heights.push_back(disk[2]);
    }

    vector<int> seq(disks.size(),-1);

    for(int i=0;i<disks.size();i++)
    {
        vector<int> i_v=disks[i];
        for(int j=0j<i;j++)
        {
            vector<int> j_v=disks[j];
            if(flag && heights[i]<=heights[j]+i_v[2])
            {
                heights[i]=heights[j]+i_v[2];
                seq[i]=j;
            }
        }
        if(heights[i]>=heights[maxIdx])
        {
            maxIdx=i;
        }
    }
    return buildSequence(disks,seq,maxIdx);
}