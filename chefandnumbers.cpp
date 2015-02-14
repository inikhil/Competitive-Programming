#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int nt,n,i,m,t,b;
    long long ans,k;
    scanf("%d",&nt);
    while(nt--){
        scanf("%d",&n);m=0;t=0,ans=0;
        for(i=0;i<n;i++){
            scanf("%d",&b);
            if(b==0||b==1){m++;}
            if(b==2){t++;}
        }
        ans=(long long)n*m-(long long)m*(m+1)/2+(long long)t*(t-1)/2;
        ans=(long long)n*(n-1)/2-(long long)ans;
        printf("%lld\n",ans);
    }
}
