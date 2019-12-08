string temp="";

void generate(int n,int open,int close,vector<string> &res)
{
    if(close==n)
    {
        res.push_back(temp);
    }
    else
    {
        if(open<n)
        {
            temp+='(';
            generate(n,open+1,close,res);
            temp.pop_back();
        }
        if(open>close)
        {
            temp+=')';
            generate(n,open,close+1,res);
            temp.pop_back();
        }
    }
    
}

vector<string> genPar2(int n)
{
    vector<string> res;
    generate(n,0,0,res);
    return res;
}