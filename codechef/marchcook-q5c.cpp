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
    int n;
    double sum=0,m;
    for(i=0;i<t;i++)
    {
        cin>>n;
        double* a=new double[n];
        a[0]=26;
        if(n==1)
        {
            cout<<26<<endl;
        }
        else
        {
            a[1]=26;
            sum=52;
            for(j=2;j<n;j++)
            {
                a[j]=fmod(26*a[j-2],1000000007);
                sum=fmod(sum+a[j],1000000007);
            }
            printf("%0.0f",sum);
            cout<<"\n";
        }
        delete []a;
    }
    return 0;
}

