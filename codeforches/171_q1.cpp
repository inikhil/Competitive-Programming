#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int n,t,i,count=0,m=0,b=0,j;
    cin>>n;
    cin>>t;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<=n-b;i++)
    {
        for(j=i;count<=(t-a[j])&&j<n;j++)
        {
            count=count+a[j];
            //cout<<count<<" "<<j<<" ";
            m=m+1;

        }
        count=0;
        if(m>b)
        {
            b=m;
        }
        m=0;
    }
    cout<<b;
    return 0;
}
