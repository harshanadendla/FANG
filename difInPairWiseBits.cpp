// logic entante....instead of running naive two loops and xor&counting....instead.....xor ante dif in bits(sarigga chooste)...so traverse all bits of all 
//nums......count how many are 1....rest are a.size()-count.....P&C...count*)a.size()-count...reps kabatti....*2......keep adding to final sum...for larger
//inputs...declare things as ll....take care of mod arithmetic.

int difInPairWiseBits(vector<int> a)
{
    ll res=0;
    for(int i=0;i<31;i++)
    {
        ll count=0;
        for(int j=0;j<a.size();j++)
        {
            if(a[j]&(1<<i))
            {
                count++;
            }
        }
        res+=(count*(a.size()-count)*2)%mod;
        res%=mod;
    }
    return ((int)res)%mod;
}