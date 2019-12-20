int all3X1(vector<int> array)
{
    int res=0;
    for(int i=0;i<32;i++)
    {
        int sum=0;
        int x=(1<<i);
        for(int j=0;j<a.size();j++)
        {
            if(x&a[j]) sum++;
        }
        if(sum%3) res|=x;
    }
    return res;
}