#include<iostream>
using namespace std;
int main()
{
    int n,s,t,i,d,e,g=0;
    cout<<"Input your value of n,s and t: "<<endl;
    cin>>n;
    cin>>s;
    cin>>t;
    int a[n],b[n],c[n];
    cout<<"Enter your second line "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(i=0;i<n;i++)
    {
        a[i]=c[i];
    }
    if(t==s)
    {
        cout<<0;
        return 0;
    }
    else
    {
        while(c[s]!=a[t])
        {

            for(i=0;i<n;i++)
            {
                d=c[i];
                b[d-1]=a[i];
            }
            for(i=0;i<n;i++)
            {
                a[i]=b[i];
            }
            if(a[s]==c[s])
            {
                cout<<-1;
                return 0;
            }
            g++;
        }
        cout<<g;
    }
    return 0;
}
