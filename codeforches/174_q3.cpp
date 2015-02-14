#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n,m,a,x,j,i;
    float t,count,k;
    cout<<"the no of operations are : "<<endl;
    cin>>n;
    vector<int> seq;
    seq.push_back(0);
    for(i=0;i<n;i++)
    {
        cin>>m;
        count=0;
        if(m==1)
        {
            cin>>a;
            cin>>x;
            for(j=0;j<a;j++)
            {
                seq[j]=seq[j]+x;
            }
            count=0;
            for(j=0;j<seq.size();j++)
            {
                count=count+seq[j];
            }
            t=(double)count/(seq.size());
            printf("%lf",t);
            cout<<"\n";
        }
        if(m==2)
        {
            cin>>a;
            seq.push_back(a);
            count=0;
            for(j=0;j<seq.size();j++)
            {
                count=count+seq[j];
            }
            //cout<<count<<endl;
            k=seq.size();
            t=(double)count/(seq.size());
            printf("%lf",t);
            cout<<"\n";
        }
        if(m==3)
        {
            k=seq.size();
            if(k>=2){
                seq.pop_back();
            }
            count=0;
            for(j=0;j<seq.size();j++)
            {
                count=count+seq[j];
            }
            t=(double)count/(seq.size());
            printf("%lf",t);
            cout<<"\n";
        }
    }
}
