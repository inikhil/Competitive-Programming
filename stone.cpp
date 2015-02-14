#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long * func(long long *d,int n){
    int m,i;
    m = *max_element(d,d+n);
    for(i=0;i<n;i++){
        d[i]=m-d[i];
    }
    return d;
}
int main(){
    int n,k,i,m;
    scanf("%d %d",&n,&k);
    long long *a=new long long[n];
    long long *b=new long long[n];
    long long *c=new long long[n];
    long long *d=new long long[n];
    for(i=0;i<n;i++){scanf("%lld",&a[i]);}
    if(k==0){
        for(i=0;i<n;i++){printf("%lld ",a[i]);}
    }
    else{
        b=func(a,n);
        for(i=0;i<n;i++){d[i]=b[i];}
        c=func(d,n);
        k=k%2;
        if(k==0){for(i=0;i<n;i++){printf("%lld ",c[i]);}}
        else if(k==1){for(i=0;i<n;i++){printf("%lld ",b[i]);}}
    }
}
