#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,i,j,q,x1,y1,x2,y2,t,cnt;
    scanf("%d",&n);
    int **a=new int*[n];
    for(i=0;i<n;i++){a[i]=new int[n];}
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int *b=new int[10];
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(i=0;i<10;i++){b[i]=0;}cnt=0;
        for(i=x1-1;i<x2;i++){
            for(j=y1-1;j<y2;j++){
                t=a[i][j]%10;
                if(b[t]==0){b[t]++;}
            }
        }
        for(i=0;i<10;i++){
            if(b[i]>0){cnt++;}
        }
        printf("%d\n",cnt);
    }
}
