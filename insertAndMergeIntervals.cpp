#include<vector>
#include<iostream>

bool doesIntersectWith(Interval a,Interval b)
{
    if(min(a.end,b.end)<max(a.start,b.start))
    {
        return false;
    }
    return true;
}

vector<Interval> insert(vector<Interval> intervals,Interval newInterval)
{
    
    if(newInterval.end<newInterval.start)
    {
        int t=newInterval.end;
        newIntervla.end=newInterval.start;
        newIntervla.start=t;
    }

    if(intervals.size()==0)
    {
        intervals.push_back(newInterval);
        return intervals;
    }

    int n=intervals.size();
    vector<Interval> res;

    if(newInterval.end<intervals[0].start || newInterval.start>intervals[n-1].end)
    {
        if(newInterval.end<intervals[0].start)
        {
            intervals.insert(intervals.begin(),newInterval);
        }
        else
        {
            intervals.push_back(newInterval);
        }
        return inetervals;
    }

    for(int i=0;i<n;i++)
    {
        bool interseting = doesIntersectWith(intervals[i],newInterval);

        if(!intersecting)
        {
            res.push_back(intervals[i]);

            if(i<n-1 && newInterval.end<intervals[i+1].start)
            {
                res.push_back(newInterval);
            }
            continue;
        }

        int fromHere=i;

        while(i<n && intersecting)
        {
            i++;
            if(i==n)
            {
                intersectng=false;
            }
            else
            {
                intersecting=doesIntersectWith(intervals[i],newInterval);
            }
        }
        i--;

        Interval gettingMerged ( min(intervals[fromHere].start,newInterval.start),max(intervals[i].end,newInterval.end));
        res.push_back(gettingMerged);
    }

    return res;
}