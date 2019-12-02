int Solution::atoi(const string a) 
{
    long long int res=0;
    int k=0;
    bool flag=true;
    int sign_count=0;
    int sign=0;
    while(1)
    {
        if(a[k]==' ')
        {
            if(sign_count==1)
            {
                return 0;
            }
            k++;
        }
        else if(a[k]>='0' && a[k]<='9')
        {
            break;
        }
        else if(a[k]=='+')
        {
            if(sign_count==1)
            {
                return 0;
            }
            sign=0;
            sign_count++;
            k++;
        }
        else if(a[k]=='-')
        {
            if(sign_count==1)
            {
                return 0;
            }
            sign=1;
            sign_count++;
            k++;
        }
        else
        {
            flag=false;
            break;
        }
    }
    if(!flag)
    {
        return 0;
    }
    for(int i=k; (a[i]>='0' && a[i]<='9') ;i++)
    {
        res=res*10 +(a[i]-'0');
        if(res>=INT_MAX)
        {
            if(sign==0)
            {
                return INT_MAX;
            }
            else
            {
                return INT_MIN;
            }
        }
    }
    return (sign==0) ? (int)res : -(int)res;
}

or

solution(string a)
{
    stringstream ss;
    ss<<a;
    long long i;
    ss>>i;
    if(i<=INT_MIN)
    {
        return INT_MIN;
    }
    if(i>=INT_MAX)
    {
        return INT_MAX;
    }
    return i;
}