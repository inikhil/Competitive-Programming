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
        long long int *b=new long long int[n-k-1];
        long long int *c=new long long int[n-k-1];
        for(i=0;i<n-k;i++){
            s=s+a[i];
            if(a[i]>s){b[i]=a[i];s=a[i];}
            else{b[i]=s;}
        }
        for(i=1;i<n-k-1;i++){b[i]=max(b[i-1],b[i]);}
        for(i=n-1;i>=k+1;i--){
            t=t+a[i];
            if(a[i]>t){t=a[i];c[i-k-1]=a[i];}
            else{c[i-k-1]=t;}
        }
        for(i=n-3-k;i>=0;i--){c[i]=max(c[i+1],c[i]);}
        for(i=0;i<n-k-1;i++){
            m=max(m,b[i]+c[i]);
        }
        printf("%lld\n",m);
        delete[] a,b,c;a=0;b=0;c=0;

    }
}
