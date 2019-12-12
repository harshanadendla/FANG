//--------------------------------------LOGIC--------------------------------------------//
// Check all poosible numbers starting from 1,2,3,....9
//since the difference should be 1....u can either decrease 1 or increase 1 after
//multiplying with 10....however....this is not the case with 0 and 9
//for 0....there is only +1
//for 9....there is only -1
//for every other number both -1 and +1
//--------------------------------------SOLUTION-----------------------------------------//
#define ll long long int

void solve(int n,int m,vector<int> &res,ll i)
{
    if(i>m) return ;
    int last=i%10;
    
    if(i>=n)
    {
        res.push_back(i);
    }
    
    if(last==0)
    {
        solve(n,m,res,i*10+1);
    }
    else if(last==9)
    {
        solve(n,m,res,i*10+last-1);
    }
    else
    {
        solve(n,m,res,i*10+last-1);
        solve(n,m,res,i*10+last+1);
    }
}

vector<int> Solution::stepnum(int n, int m) 
{
    vector<int> res;
    if(n>m) return res;
    if(n==0) res.push_back(0);
    for(ll i=1;i<=9;i++)
    {
        solve(n,m,res,i);
    }
    
    if(!res.empty()) sort(res.begin(),res.end());
    return res;
}