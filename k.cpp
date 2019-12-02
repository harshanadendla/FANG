int Solution::pow(int base, int exponent, int m) 
{
    if(m==1)
    {
      return 0;
    } 

    ll ans=1,y=base%m;

    while(exponent>0)
    {
        if(exponent&1)
        {
          ans=((ans)*y)%m;
        }
        y=(y*y)%m;
        if(y<0)
        {
           y+=m;  
        } 
        exponent=exponent>>1;
    }
    if(ans<0)
    {
        ans=(m-abs(ans)%m);
        return ans;
    }
    return ans%m;
}