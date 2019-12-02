#include<iostream>
#include<vector>
using namespace std;

void swap(int& a,int& b)
{
    int t=a;
    a=b;
    b=t;
}

void shiftDown(int currentIdx,int endIdx,vector<int>& array)
{
    int childOneIdx=(2*currentIdx)+1;
    int childTwoIdx=-1;
    while(childOneIdx<=endIdx)
    {
        int idxToSwap;
        if((2*currentIdx)+2 <= endIdx)
        {
            childTwoIdx=(2*currentIdx)+2;
            if(array[childOneIdx]>array[childTwoIdx])
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
        if(array[idxToSwap]>array[currentIdx])
        {
            swap(array[idxToSwap],array[currentIdx]);
            currentIdx=idxToSwap;
            childOneIdx=(2*currentIdx)+1;
        }
        else
        {
            break;
        }
    }
}

void buildHeap(vector<int>& array)
{
    int firstParentIdx=(array.size()-2)/2;
    for(int currentIdx=firstParentIdx;currentIdx>=0;currentIdx--)
    {
        shiftDown(currentIdx,array.size()-1,array);
    }
}

vector<int> heapSort(vector<int>& array)
{
    buildHeap(array);
    for(int endIdx=array.size()-1;endIdx>=0;endIdx--)
    {
        swap(array[0],array[endIdx]);
        shiftDown(0,endIdx-1,array);
    }
    return array;
}

int main()
{
    vector<int> array;
    array.push_back(5);
    array.push_back(4);
    array.push_back(6);
    array.push_back(1);
    array.push_back(8);
    array.push_back(3);
    array.push_back(9);

    array=heapSort(array);
    for(int i=0;i<array.size();i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}