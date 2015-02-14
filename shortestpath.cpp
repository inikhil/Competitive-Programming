#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class node{
public:
    int k;
    node *p;
    node(int key,node *next){k=key;p=next;}
};
int main(){
    int n,i,j,t,cnt,m,mn,mn1;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&i,&j);m=0;cnt=0;
        mn=min(i,j);mn1=max(i,j);
        i=mn;j=mn1;
        node *a=new node(i,0);t=i/2;
        node *b;b=a;
        while(t!=0){
            a->p=new node(t,0);
            a=a->p;
            t=t/2;
        }
        //while(b!=0){cout<<b->k<<" ";b=b->p;}
        while(m!=1){
            if(j>b->k){j=j/2;cnt++;}
            else if(j<b->k){b=b->p;cnt++;}
            else if(j==b->k){printf("%d\n",cnt);m=1;}
        }
    }
}
