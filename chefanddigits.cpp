#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
    int n,m,i,x,ans;
    scanf("%d %d",&n,&m);
    int *a=new int[n];
    int *b=new int[n];
    char c[n];scanf("%s",&c);
    for(i=0;i<n;i++){a[i]=c[i]-'0';}
    b[0]=0;
    for(i=1;i<n;i++){
        b[i]=abs((i-1)*(a[i]-a[i-1])+b[i-1]);
    }
    while(m--){
        scanf("%d",&x);//ans=0;
        //for(i=0;i<x-1;i++){
          //  ans+=abs(a[x-1]-a[i]);
        //}
        printf("%d\n",b[x-1]);
    }
    //for(i=0;i<4;i++){scanf("%c",&c);a[i]=c-'0';cout<<a[i]<<" ";}
    //cout<<a[8]+a[9];
}
