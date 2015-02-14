#include<iostream>
#include<cstdio>
#include<cstdlib>
int main(){
    int nt,n,k,m,c;
    long long t;
    scanf("%d",&nt);
    while(nt--){
        c=0;
        scanf("%d",&n);m=n;
        while(n--){
            scanf("%d",&k);
            //if(k>=1 && k<=m){c++;}
        }
        t=(long long)m*(m-1);
        printf("%lld\n",t/2);
    }
}
