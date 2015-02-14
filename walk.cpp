#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int nt,n,i,ii,t;
    scanf("%d",&nt);
    while(nt--){
        scanf("%d",&n);
        int *a = new int[n];
        for(i=0;i<n;i++){scanf("%d",&a[i]);}t=a[n-1];
        for(i=n-2;i>=0;i--){t=max(t+1,a[i]);}
        printf("%d\n",t);
    }
}
