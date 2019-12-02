int maxReach(vector<int> array)
{
    int currend=0,currfarthest=0,steps=0;
    for(int i=0;i<=currend;i++)
    {
        currfarthest=max(currfarthest,i+array[i]);
        if(currfarthest>=array.size()-1)
        {
            return steps;
        }
        if(i==currend)
        {
            steps++;
            currend=currfarthest;
        }
    }
    if(currfarthest<array.size()-1)
    {
        return -1;
    }
    return steps;
}