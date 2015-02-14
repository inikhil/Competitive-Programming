#include<iostream>
#include<cmath>
using namespace std;
double printvalue(int n)
{
    if(n==1)
    {
        return 26;
    }
    if(n==2)
    {
        return 26;
    }
    else
    {
        return 26*printvalue(n-2);
    }
}

int main()
{
    int t,i,j;
    cin>>t;
    int *n=new int[t];
    double sum=0,m;
    for(i=0;i<t;i++)
    {
        cin>>n[i];
    }
    for(i=0;i<t;i++)
    {
        sum=0;
        for(j=0;j<n[i];j++)
        {
            sum=sum+printvalue(j+1);
        }
        m=fmod(sum,1000000007);
        printf("%f",m);
        cout<<"\n";
    }
    return 0;
}
