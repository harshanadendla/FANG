//...from starting....check all bits...if a bit is 1....set its conjugate as 1.....this setting is done by xoring.

int revBits(unsiged int a)
{
    int res=0;
    for(int i=0;i<32;i++)
    {
        if((a>>i)&1) res|=(1<<(31-i));
    }
    return res;
}