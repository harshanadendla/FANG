int coinGameWin(vector<int> array)
{
    vector<vector<vector<int>>> dp(array.size(),vector<vector<int>>(array.size(),vector<int>(2,0)));

    for(int i=0;i<array.size();i++)
    {
        dp[i][i][0]=array[i];
        dp[i][i][1]=0;
    }

    for(int len=1;len<array.size();i++)
    {
        for(int i=0,j=len;j<array.size();i++,j++)
        {
            int x=array[i]+dp[i+1][j][1];
            int y=array[j]+dp[i][j-1][1];

            if(x>y)
            {
                dp[i][j][0]=x;
                dp[i][j][1]=dp[i+1][j][0];
            }
            else
            {
                dp[i][j][0]=y;
                dp[i][j][1]=dp[i][j-1][0];
            }
        }
    }
    return dp[0][array.size()-1][0];
}