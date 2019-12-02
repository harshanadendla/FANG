int Solution::solve(int n, int s) 
{
    if(n==0)
    {
        return 0 
    }
    if(n==1)
    {
        if(s>=0 && s<=9)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(s+1,0));
    for(int i=1;i<min(9,s+1);i++)
    {
        dp[1][i]=1;
    }
    
    for(int i=2;i<n+1;i++)
    {
        for(int j=1;j<s+1;j++)
        {
            (j<=9) ? int k=1 : int k=j-9 ;
            for(;k<=j;k++)
            {
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
    return dp[n][s];
}