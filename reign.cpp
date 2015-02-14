#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int nt,n,k,i,j;
    long long s,t,m;
    scanf("%d",&nt);
    while(nt--){
        scanf("%d %d",&n,&k);
        int *a=new int[n];s=0;t=0;m=-pow(10.0,10);
        for(i=0;i<n;i++){scanf("%d",&a[i]);}
        long long *b=new long long[n-k-1];
        long long *c=new long long[n];
        for(i=0;i<n-k;i++){
            s=s+a[i];
            if(a[i]>s){b[i]=a[i];s=a[i];}
            else{b[i]=s;}
        }
        //for(i=0;i<n-k-1;i++){cout<<b[i]<<" ";}
        //cout<<"\n";
        for(i=1;i<n-k-1;i++){b[i]=max(b[i-1],b[i]);}
        //for(i=0;i<n-k-1;i++){cout<<b[i]<<" ";}
        //cout<<"\n";
        for(i=0;i<=k;i++){c[i]=0;}
        for(i=n-1;i>=k+1;i--){
            t=t+a[i];
            if(a[i]>t){t=a[i];c[i]=a[i];}
            else{c[i]=t;}
        }
        //for(i=0;i<n;i++){cout<<c[i]<<" ";}
        //cout<<"\n";
        for(i=n-2;i>=k+1;i--){c[i]=max(c[i+1],c[i]);}
        //for(i=0;i<n;i++){cout<<c[i]<<" ";}
        //cout<<"\n";
        for(i=0;i<n-k-1;i++){
            m=max(m,b[i]+c[i+k+1]);
        }
        printf("%lld\n",m);
        delete[] a;
        delete[] b;
        delete[] c;

    }
}
