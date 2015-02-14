#include <iostream>

using namespace std;

int main()
{
    int n,m,t,i,c=0,d=0,f;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    cin>>t;
    if(m==t)
    {
        cout<<0;
        return 0;
    }
    if(m<t)
    {
        for(i=m-1;i<(t-1);i++)
        {
            c=c+a[i];
        }
        if(m>1)
        {
            for(i=m-2;i>=0;i--)
            {
            d=d+a[i];
            }
        }
        for(i=n-1;i>=(t-1);i--)
        {
            d=d+a[i];
        }
    }
    if(m>t)
    {
        f=t;
        t=m;
        m=f;
        for(i=m-1;i<(t-1);i++)
        {
            c=c+a[i];
        }
        if(m>1)
        {
            for(i=m-2;i>=0;i--)
            {
            d=d+a[i];
            }
        }
        for(i=n-1;i>=(t-1);i--)
        {
            d=d+a[i];
        }

    }
    if(c>=d)
    {
        cout<<d;
    }
    else
    {
        cout<<c;
    }
    return 0;
}
