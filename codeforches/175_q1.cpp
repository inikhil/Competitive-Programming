#include<iostream>
using namespace std;
int main()
{
    int n,k,i,t,j,f[2];
    cout<<" Enter your value of n and k: "<<endl;
    for(i=0;i<2;i++)
    {
        cin>>f[i];
    }
    n=f[0];
    k=f[1];
    int a[n],b[n];
    for(i=0;i<n;i++)
    {
        a[i]=n-i;
    }
    j=1;
    for(i=0;i<k;i++)
    {
        b[i]=a[i];
    }
    for(i=k;i<n;i++)
    {
        b[i]=a[n-j];
        j++;
    }
    for(i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
}
