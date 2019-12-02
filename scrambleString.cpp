int isScramble(string a,string b)
{
    if(a==b)
    {
        return true;
    }

    int hash[26]={0};
    for(int i=0;i<a.length();i++)
    {
        hash[a[i]-'a']++;
        hash[b[i]-'a']--;
    }

    for(int i=0;i<a.length();i++)
    {
        if(hash[i]!=0)
        {
            return false;
        }
    }

    for(int i=1;i<a.length();i++)
    {
        if(isScramble(a.substr(0,i),b.substr(0,i)) && isScramble(a.substr(i),b.substr(i)))
        {
            return true;
        }
        if(isScramble(a.substr(0,i),b.substr(a.length()-i)) && isScramble(a.substr(i),b.substr(0,a.length()-i))
        {
            return true;
        }
    }
    return false;
}