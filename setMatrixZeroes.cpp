#include<vector>

vector<vector<int> > setZeroes(vector<vector<int> > array)
{
    int r=array.size();
    int c=array[0].size();

    int i=0,j=0;
    bool row_flag=false,col_flag=false;


    while(i<r)
    {
        if(array[i][0]==0)
        {
            row_flag=true;
            break;
        }
        i++;
    }
    while(j<r)
    {
        if(array[0][j]==0)
        {
            row_flag=true;
            break;
        }
        j++;
    }

    for(int i=1;i<r;i++)
    {
        for(int j=1;i<c;j++)
        {
            if(array[i][j]==0)
            {
                array[0][j]=1;
                array[i][0]=1;
            }
        }
    }

    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(array[0][j]==1 || array[i][0]==1)
            {
                array[i][j]=0;
            }
        }
    }

    if(row_flag)
    {
        i=0;
        while(i<r)
        {
            array[i][0]=0;
            i++;
        }
    }

    if(col_flag)
    {
        j=0;
        while(j<c)
        {
            array[0][j]=0;
            j++;
        }
    }
    return array;
}