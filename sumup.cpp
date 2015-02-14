#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int length(int a){
    int m=0;
    while(a!=0){m++;a=a/10;}
    return m;
}
int base(int *a,int t){
    int m=0,i;
    for(i=0;i<t;i++){if(a[i]>m){m=a[i];}}
    return m+1;
}
int value(int *a,int t,int base){
    int i,m=0;
    for(i=t-1;i>=0;i--){
        m+=a[i]*pow(base,t-1-i);
    }
    return m;
}
int main(){
    int nt,a,b,t,m,i,base_a,base_b; scanf("%d",&nt);
    while(nt--){
        scanf("%d %d",&a,&b);
        t=length(a);m=length(b);
        int *c=new int[t];int *d=new int[m];
        for(i=t-1;i>=0;i--){c[i]=a%10;a=a/10;}
        for(i=m-1;i>=0;i--){d[i]=b%10;b=b/10;}
        base_a=base(c,t);base_b=base(d,m);
        a=value(c,t,base_a);b=value(d,m,base_b);
       // printf("%d %d ",a,b);
        printf("%d\n",a+b);
    }
}
