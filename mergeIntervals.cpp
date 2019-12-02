vector<Interval> Solution::merge(vector<Interval> &array) 
{
    sort(array.begin(),array.end(),comp);

    stack<Interval> s;
    s.push(array[0]);

    for(int i=1;i<array.size();i++)
    {
        Interval& temp=s.top();

        if(top.end<array[i].start)
        {
            s.push(array[i]);
        }
        else if(top.end<array[i].end)
        {
            top.end=array[i].end;
        }
    }
    vector<Interval> res={};
    while(!s.empty())
    {
        res.insert(res.begin(),s.top());
        s.pop();
    }
    return res;
}