int minFibNums(int n)
{
    vecto<int> fib;
    fib.push_back(1);
    fib.push_back(1);
    for(int i=2;;i++)
    {
        int next=fib[i-1]+fib[i-2];
        if(next<=n)
        {
            fib.push_back(next);
        }
        else break;
    }
    while(n>0)
    {
        while(a<fib[i])
        {
            i--;
        }
        a-=fib[i];
        count++;
    }
    return count;
}