#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,k,i,m=0;
    long long t=0;
    scanf("%d %d",&n,&k);
    int *a=new int[n];
    for(i=0;i<n;i++){scanf("%d",&a[i]);}
    sort(a,a+n);
    for(i=0;i<n;i++){
        if(t+a[i]<=k){t=t+a[i];m++;}
        else{printf("%d\n",m);break;}
    }
}
