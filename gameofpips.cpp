#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long hcf(int i,int j){
    if(i==1||j==1){return 1;}
    else if(j%i==0 && i<=j){return i;}
    else if(i%j==0 && j<=i){return j;}
    else if(i<j){return hcf(j%i,i);}
    else{return hcf(i%j,j);}
}
int main(){
    int n,i,b=0,p=10;
    long long t,j,m,k,q;
    scanf("%d",&n);b=0;
    long long *a=new long long[n];
    for(i=0;i<n;i++){scanf("%lld",&a[i]);}
    sort(a,a+n);
    t=a[0];k=a[0];
    for(i=1;i<n;i++){k=hcf(a[i],k);}
    q=k;
    for(j=1;q!=1;j++){
        if(k%j==0){
            q=(long long)k/j;
            if(fmod(q,2)!=0){printf("%lld\n",q);b=1;break;}
        }
    }
    if(b==0){printf("1\n");}
}
