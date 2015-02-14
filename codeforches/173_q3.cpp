#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
    int m,n,i,j;
    string a,b,c,d;
    int p,q;
    cin>>a;
    cin>>b;
    //cout<<a.length()<<" "<<b.length()<<endl;
    m=a.length();
    n=b.length();
    c=a;
    d=a;
    if(m!=n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(i=0;i<m;i++)
    {
        if(c==b||d==b)
        {
            cout<<"YES";
            return 0;
        }
        if(i==m-1)
        {
            cout<<"N0";
            return 0;
        }
        else
        {
            c=a;
            d=a;
            if(((c[i]==0)&&(c[i+1]==0))||((c[i]==1)&&(c[i+1]==1)))
            {
                p=0;
            }
            if(c[i]!=c[i+1])
            {
                p=1;
            }
            if((c[i]==0)&&(c[i+1]==0))
            {
                q=0;
            }
            if((c[i]!=0)||(c[i+1]!=0))
            {
                q=1;
            }
            //cout<<p<<" "<<q<<" ";
            c[i]=p+48;
            c[i+1]=q+48;
            //cout<<c<<" ";
            d[i]=q+48;
            d[i+1]=p+48;
            //cout<<d;
        }
    }
    cout<<"NO";
    return 0;

}
