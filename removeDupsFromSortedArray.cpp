int removeDups(vector<int>& a)
{
    int k=0;
    for(int i=1;i<a.size();i++)
    {
        if(a[k]!=a[i])
        {
            a[++k]=a[i];
        }
    }
    a.erase(a.begin()+k+1,a.end());
    return k+1;
}