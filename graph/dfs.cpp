#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

class node{
public:
    char col;
    int d;
    int index;
    node* prev;
    int f;
    node(int i){col='w';d=0;prev=NULL;index=i;f=0;}
};

int ** generatematrix(int n){
    int i,j;
    int **a=new int*[n];
    for(i=0;i<n;i++){
        a[i]=new int[n];
        for(j=0;j<n;j++){
            a[i][j]=rand()%2;
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return a;
}

int time=0;

void dfsvisit(node **p,int **a,int n,int u){
    p[u]->col='g';
    time=time+1;
    p[u]->d=time;
    int j;
    for(j=0;j<n;j++){
        if(a[u][j]==1 && p[j]->col=='w'){
            p[j]->prev=p[u];
            dfsvisit(p,a,n,j);
        }
    }
    p[u]->col='b';
    time=time+1;
    p[u]->f=time;
}

void dfs(node **p,int n,int **a){
    int i;
    for(i=0;i<n;i++){
        if(p[i]->col=='w'){
            dfsvisit(p,a,n,i);
        }
    }
}


int main(){
    int n,i;
    cin>>n;
    int **a;
    a=generatematrix(n);
    node **p=new node*[n];
    for(i=0;i<n;i++){p[i]=new node(i);}
    dfs(p,n,a);
    for(i=0;i<n;i++){cout<<p[i]->d<<" ";}
    cout<<"\n";
    for(i=0;i<n;i++){cout<<p[i]->f<<" ";}
    cout<<"\n";
    node *r;
    for(i=0;i<n;i++){r=p[i]->prev;if(r){cout<<r->index<<" ";}else{cout<<"NULL"<<" ";}}
}

