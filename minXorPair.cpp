//...xor ante......difference in two numbers....if seen in right way.....so xor min undedi....if dif between two numbers is min....this is acheived by sorting
//and then just checking for consecutive pairs.

int minXorPair(vector<int> array)
{
    int res=INT_MAX;
    for(int i=0;i<a.size()-1;i++)
    {
        int x=a[i]^a[i+1];
        if(x<res) res=x;
    }
    return res;
}