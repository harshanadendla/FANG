#include<iostream>
#include<vector>
using namespace std;

#define mod 1000000007

int num_non_ints_chords(int n)
{
    int m=2*n;
    vector<int> chords(m+1,0);
    chords[2]=1;

    for(int i=4;i<=m;i+=2)
    {
        int sum=0;
        for(int j=0;j<i;j+=2)
        {
            int half1=j;
            int half2=i-j-2;

            if(chords[half1]==0)
            {
                sum+=chords[half2];
                sum%=mod;
            }
            else if(chords[half2]==0)
            {
                sum+=chords[half1];
                sum%=mod;
            }
            else
            {
                sum+=((chords[half1]*chords[half2])%mod);
            }
        }
        chords[i]=sum;
    }
    return chords[m];
}

int main()
{
    int n;
    cin>>n;
    cout<<num_non_ints_chords(n)<<endl;;
    return 0;
}





chords[m+1]=0;
chords[2]=1;

for(int i=4;i<=m;i+=2)
{
    for(int j=0;j<i;j+=2)
    {
        int sum=0;
        int half1=j;
        int half2=i-j-2;

        if(chords[half1]==0)
        {
            sum+=chords[half2];
        }
        else if(chords[half2]==0)
        {
            sum+=chords[half1];
        }
        else
        {
            sum+=(chords[half1]*chords[half2]);
        }
    }
    chords[i]=sum;
}