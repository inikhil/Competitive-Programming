#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int nt,n,k,i,m;scanf("%d",&nt);
    long long t;
    while(nt--){
        scanf("%d %d",&n,&k);m=0;
        int *a=new int[n];
        int *b=new int[n];
        for(i=0;i<n;i++){scanf("%d",&a[i]);}
        for(i=0;i<n;i++){scanf("%d",&b[i]);}
        sort(a,a+n);sort(b,b+n);
        for(i=0;i<n;i++){
            if(a[i]+b[n-i-1]<k){printf("NO\n");m=1;break;}
        }
        if(m==0){printf("YES\n");}
    }
}
