#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int nt,x,y,n;scanf("%d",&nt);
    long long int ans;
    while(nt--){
        scanf("%d %d",&x,&y);
        n=y-x+1;
        if(n%2==0){ans=(long long)(n/2)*(n-1);}
        else{ans=(long long)(n)*((n-1)/2);}
        printf("%lld\n",ans);
    }
}
