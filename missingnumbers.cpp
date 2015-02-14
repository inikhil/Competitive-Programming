#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int* input(){
    int n,i,t;
    scanf("%d",&n);
    int *a=new int[20001];
    for(i=0;i<=20000;i++){a[i]=0;}
    for(i=0;i<n;i++){scanf("%d",&t);a[t+10000]++;}
    return a;
}
int main(){
    int n,m,i,t;
    int *a=new int[20001];
    int *b=new int[20001];
    a=input();b=input();
    for(i=0;i<=20000;i++){
        if(b[i]>a[i]){printf("%d ",i-10000);}
    }
}
