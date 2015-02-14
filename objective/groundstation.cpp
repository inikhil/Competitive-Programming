#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

class node{
public:
    int key;
    node *next;
    node(int d,node *pp){key=d;next=pp;}
};


int main(){
    int nt,i;
    int m,x,y;
    long long z;
    int *a=new int[100001];
    node **p=new node*[100001];
    node *r;
    scanf("%d",&nt);
    while(nt--){
        scanf("%d",&m);int cnt=0;
        for(i=0;i<100001;i++){a[i]=0;}
        for(i=0;i<100001;i++){p[i]=new node(i,0);}
        for(i=1;i<=m;i++){
            scanf("%d",&x);scanf("%d",&y);
            if(x==0){
                a[y]++;cnt++;
                r=p[y]->next;
                p[y]->next=new node(cnt,0);
                p[y]->next->next=r;
            }
            if(x==1){
                z=(long long)a[y]*(a[y]-1);
                z=(long long)z/2;
                r=p[y];
                //while(r!=NULL){cout<<r->key<<" ";r=r->next;}
                while(r->next!=NULL){
                    r=r->next;
                    z=(long long)z+a[r->key];
                }
                printf("%lld\n",z);
            }
        }
    }
}
