int isItCcolourful(int x)
{
    vector<int> a;
    unordered_map<long long int,bool> hash;
    while(x)
    {
        a.insert(a.begin(),x%10);
        x/=10;
    }
    for(int i=0;i<a.size();i++)
    {
        for(int j=i;j<a.size();j++)
        {
            ll mul=1;
            for(int k=i;k<=j;k++)
            {
                nul*=a[k];
            }
            if(hash.find(mul)!-hash.end()) return 0;
            else hash[mul]=1;
        }
    }
    return 1;
}