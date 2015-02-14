#include<iostream>
#include<cstdio>
using namespace std;
struct obj{
    int index;
    int min_track;
};
int main(){
    int n,k,i,m=10000000,t,x=0;
    scanf("%d %d",&n,&k);
    int *a=new int[n];
    for(i=0;i<n;i++){scanf("%d",&a[i]);}
    obj* b =new obj[1000001];
    b[0].index=0;b[0].min_track=0;
    for(i=1;i<=1000000;i++){b[i].index=0;b[i].min_track=10000000;}
    for(i=0;i<n;i++){b[a[i]].index=1;b[a[i]].min_track=min(i+1,b[a[i]].min_track);}
    for(i=n-1;i>=0;i--){b[a[i]].min_track=min(n-i,b[a[i]].min_track);}
    for(i=1;i<k;i++){
        if(b[i].index==1){
            t=k-i;
            if(t!=i && b[t].index==1){
                m=min(m,max(b[i].min_track,b[t].min_track));
            }
        }
    }
    if(m==10000000){printf("-1\n");}
    else{printf("%d\n",m);}
}
