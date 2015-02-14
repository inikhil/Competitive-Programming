#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,k,i,m=0,j;
    long long t=0;
    scanf("%d %d",&n,&k);
    int *a=new int[n];
    for(i=0;i<n;i++){scanf("%d",&a[i]);}
    sort(a,a+n);
    for(i=0;i<n-1;i++){
        for(j=i+1;m!=1;j++){
            if(a[j]==k+a[i]){t++;m=1;}
            if((j==n-1)||(a[j]>k+a[i])){m=1;}
        }
        m=0;
    }
    printf("%lld\n",t);
}
