#include<iostream>
using namespace std;
int main()
{
    int n,m,i,c,d,j,f,e=0,x;
    cin>>n;
    cin>>m;
    int a[n];
    f=n;
    int b[m][2];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<2;j++)
        {
            cin>>b[i][j];
        }
    }
    for(i=0;i<m;i++)
    {
       c=b[i][0]-1;
       d=b[i][1]-1;
       f=n;
       x=0;
       if(c==d)
       {
           cout<<"Yes"<<endl;
           x=1;
       }
       else
       {
            for(j=c;j<=f;j++)
            {
                if(a[j+1]>a[j])
                {
                    e=j+1;
                    f=j+1;
                }
                if((a[j+1]<a[j])&&(a[j+2]>a[j+1]))
                {
                    cout<<"No"<<endl;
                    x=2;
                }
                else
                {
                    e=j;
                }
            }
            for(j=e;j<d;j++)
            {
                if(a[j+1]>a[j])
                {
                    if(x!=2)
                    {
                        cout<<"No"<<endl;
                        #include<iostream>
using namespace std;
int main()
{
    int n,m,i,c,d,j,f,e=0,x;
    cin>>n;
    cin>>m;
    int a[n];
    f=n;
    int b[m][2];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<2;j++)
        {
            cin>>b[i][j];
        }
    }
    for(i=0;i<m;i++)
    {
       c=b[i][0]-1;
       d=b[i][1]-1;
       f=n;
       x=0;
       if(c==d)
       {
           cout<<"Yes"<<endl;
           x=1;
       }
       else
       {
       for(j=c;j<=f;j++)
       {
           if(a[j+1]>a[j])
           {
               e=j+1;
               f=j+1;
           }
           if((a[j+1]<a[j])&&(e!=j))
           {
               cout<<"No"<<endl;
               x=2;
           }
       }
       if(x!=2)
       {
            for(j=e;j<d;j++)
            {
                if(a[j+1]>a[j])
                {
                    cout<<"No"<<endl;
                    x=1;
                }
            }
       }
       if(x!=1||x!=2)
       {
            cout<<"Yes"<<endl;
       }
       }
    }
return 0;

}
