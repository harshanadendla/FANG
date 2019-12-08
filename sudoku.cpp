bool isVal(vector<vector<char>> &a,int row,int col,char ch)
{
    for(int i=0;i<9;i++)
    {
        if(a[i][col]==ch && i!=row) return false;
        if(a[row][i]==ch && i!=col) return false;
    }
    
    int x=(row/3)*3;
    int y=(col/3)*3;
    
    for(int i=x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
        {
            if(a[i][j]==ch && (i!=row || j!=col)) return false;
        }
    }
    return true;
}

bool sudoku(vector<vector<char>> &a,int row,int col)
{
    if(row==9)
    {
        return true;
    }
    if(col==9)
    {
        return sudoku(a,row+1,0);
    }
    if(a[row][col]!='.')
    {
        return sudoku(a,row,col+1);
    }
    for(char i='1';i<='9';i++)
    {
        if(isVal(a,row,col,i))
        {
            a[row][col]=i;
            if(sudoku(a,row,col+1))
            {
                return true;
            }
            a[row][col]='.';
        }
    }
    return false;
}