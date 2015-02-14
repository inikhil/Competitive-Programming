#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<new>
using namespace std;
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
        sum=52;
        double* a=new double[n[i]];
        a[0]=26;
        if(n[i]==1)
        {
            cout<<26<<endl;
        }
        else
        {
            a[1]=26;
            for(j=2;j<n[i];j++)
            {
                a[j]=fmod(26*a[j-2],1000000007);
                sum=fmod(sum+a[j],1000000007);
            }
            printf("%0.0f",sum);
            cout<<"\n";
        }
        delete []a;
    }
    delete []n;
    return 0;
}
