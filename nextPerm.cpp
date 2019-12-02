void nextPerm(vector<int>& array)
{
    if(array.size()<=1)
    {
        return;
    }
    int i,j;
    int n=array.size();

    for(i=n-2;i>=0;i--)
    {
        if(array[i]<array[i+1])
        {
            break;
        }
    }

    if(i==-1)
    {
        reverse(array.begin(),array.end());
        return;
    }

    for(j=n-1;j>i;j--)
    {
        if(arra[j]>array[i])
        {
            break;
        }
    }

    swap(array[i],array[j]);
    reverse(array.begin()+i+1,array.end());
}