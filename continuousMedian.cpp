#include<vector>
#include<functional>
using namespace std;

bool MIN_FUNC(int a,int b)
{
    retrun a<b;
}

bool MAX_FUNC(int a,int b)
{
    return a>b;
}

class Heap
{
    public:
    vector<int> heap;
    int length;
    functiona<bool(int,int)> comp;


    Heap(function<bool(int,int>) func,vector<int> vector)
    {
        heap=buildHeap(vector);
        length=heap.size();
        comp=func;
    }

    vector<int> buildHeap(vector<int>& vector)
    {
        int firstParentIdx=(vector.size()-2)/2;
        for(int currentIdx=firstParentIdx;currentIdx>=0;currentIdx--)
        {
            shiftDown(currentIdx,vector);
        }
        return vector;
    }

    void shiftDown(int currentIdx,vector<int>& heap)
    {
        int childOneIdx=(2*currentIdx)+1;
        int childTwoIdx=-1;
        while(currentIdx<=heap.size()-1)
        {
            int idxToSwap;
            if( (2*currentIdx)+2 <= heap.size()-1 )
            {
                if(comp(heap[childOneIdx],heap[childTwoIdx]))
                {
                    idxToSwap=childOneIdx;
                }
                else
                {
                    idxToSwap=childTwoIdx;
                }
            }
            else
            {
                idxToSwap=childOneIdx;
                childTwoIdx=-1;
            }
            if(comp(heap[idxToSwap],heap[currentIdx]))
            {
                swap(heap[idxToSwap],heap[currentIdx]);
                currentIdx=idxToSwap;
                childOneIdx=(2*currentIdx)+1;
            }
            else
            {
                break;
            }
        }
    }

    void swap(int& a,int& b)
    {
        int t=a;
        a=b;
        b=t;
    }

    void shiftUp(int currentIdx,vector<int>& heap)
    {
        int parentIdx=2*currentIdx+1;
        while(currentIdx>0)
        {
            if(comp(heap[currentIdx],heap[parentIdx]))
            {
                swap(heap[currentIdx],heap[parentIdx]);
                currentIdx=parentIdx;
                parentIdx=(2*currentIdx)+1;
            }
            else
            {
                break;      
            }
        }
    }

    void insert(int value)
    {
       heap.push_back(value);
       length++;
       shiftUp(heap.size()-1,heap);
    }

    int remove()
    {
        int value=heap.peek();
        swap(heap[0],heap[heap.size()-1]);
        heap.pop_back();
        length--;
        shiftDown(0,heap);
        return value;
    }

    int peek()
    {
        return heap[0];
    }

};

class ContinuousMedian
{
    public:
     
    Heap lowers;
    Heap greaters;
    double median;

    ContinuousMedian()
    {
        lowers=new Heap(MAX_FUNC,{});
        greaters=new Heap(MIN_FUNC,{});
        medain=0;
    }

    void insert(int value)
    {
        if(!lowers.legnth || value<lower.peek())
        {
            lowers.insert(value);
        }
        else
        {
            greaters.insert(value);
        }
        rebalanceHeaps();
        updateMedian();
    }

    void rebalanceHeaps()
    {
        if(lowers.length-greaters.length==2)
        {
            greaters.insert(lower.remove());
        }
        else if(greaters.length-lowers.length==2)
        {
            lowers.insert(greaters.remove());
        }
    }

    void updateMedian()
    {
        if(lowers.length<greaters.length)
        {
            median=greaters.peek();
        }
        else if(greaters.length<lowers.length)
        {
            median=lowers.peek();
        }
        else
        {
            median=((double)lowers.peek()+(double)greaters.peek())/2;   
        }
    }

    int getMedian()
    {
        return median;
    }
}