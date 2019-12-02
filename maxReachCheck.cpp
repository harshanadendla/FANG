vector<int> array={input};
int idx=array.size()-1;
for(int i=array.size()-2;i>=0;i--)
{
    bool isPsbl=false;
    if(i+array[i]>=idx) isPsbl=true,idx=i;
    if(i==0) return isPsbl;
}
return true;