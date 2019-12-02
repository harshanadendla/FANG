double Solution::findMedianSortedArrays(const vector<int> &a, const vector<int> &b)
{
    if(a.size()>b.size())
    {
        return findMedianSortedArrays(b,a);
    }   
    int x=a.size();
    int y=b.size();    
    int low=0;
    int high=x;    
    while(low<=high)
    {
        int partitionX=(low+high)/2;
        int partitionY=(x+y+1)/2 - partitionX;
        
        int lmaxX = (partitionX==0) ? INT_MIN : a[partitionX-1];
        int rminX = (partitionX==x) ? INT_MAX : a[partitionX];
        
        int lmaxY = (partitionY==0) ? INT_MIN : b[partitionY-1];
        int rminY = (partitionY==y) ? INT_MAX : b[partitionY];
        
        if(lmaxX<=rminY && lmaxY<=rminX)
        {
            if((x+y)%2==0)
            {
                return (double)(max(lmaxX,lmaxY)+min(rminX,rminY))/2;
            }
            else
            {
                return (double)(max(lmaxX,lmaxY));
            }
        }
        else if(lmaxX>rminY)
        {
            high=partitionX-1;
        }
        else
        {
            low=partitionX+1;
        }
    }
}