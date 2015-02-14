#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long A,B,C;
long long int* rev(long long *a,int i,int n){
    int j;
    long long m=a[n-1];
    for(j=n-1;j>i;j--){a[j]=a[j-1]%C;}
    a[i]=m%C;
    return a;
}
long long int* add(long long *a,int i,int n){
    int j;long long t;
    for(j=i;j<n;j++){a[j]=(a[j]+A)%C;}
    return a;
}
long long int* mult(long long *a,int i,int n){
    int j,k;float f;int t;
   // for(j=i;j<n;j++){
     //   for(t=1;t<B;t=t*10){
       //     f=((a[j]%C)*10)%C;
        //}
    //}
    //f=(a[j]%C)*(B%C);a[j]=fmod(f,C);
    return a;
}
void ancient(long long *a,int n,char *s){
    int i;
    for(i=0;i<n;i++){
        if(s[i]=='R'){a=rev(a,i,n);}
        else if(s[i]=='A'){a=add(a,i,n);}
        else if(s[i]=='M'){a=mult(a,i,n);}
        printf("%lld ",a[i]);
    }
    printf("\n");
}
int main(){
    int nt,n,i;scanf("%d",&nt);
    char s[1000];
    while(nt--){
        scanf("%d",&n);
        long long *a=new long long[n];
        for(i=0;i<n;i++){scanf("%lld",&a[i]);}
        scanf("%lld %lld %lld",&A,&B,&C);
        scanf("%s",s);
        ancient(a,n,s);
    }
}
