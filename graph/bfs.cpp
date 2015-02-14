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
    node(int i){col='w';d=INT_MAX;prev=NULL;index=i;}
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

void bfs(node **p,int n,int **a){
    p[0]->d=0;
    p[0]->col='g';
    queue<node* > q;
    q.push(p[0]);
    node* r;
    int j,i;
    while(!q.empty()){
        r=q.front();q.pop();
        i=r->index;
        for(j=0;j<n;j++){
            if(a[i][j]==1 && p[j]->col=='w'){
                p[j]->col='g';
                p[j]->d=(p[i]->d)+1;
                p[j]->prev=p[i];
                q.push(p[j]);
            }
        }
        r->col='b';
    }
}

int main(){
    int n,i;
    cin>>n;
    int **a;
    a=generatematrix(n);
    node **p=new node*[n];
    for(i=0;i<n;i++){p[i]=new node(i);}
    bfs(p,n,a);
    for(i=0;i<n;i++){cout<<p[i]->d<<" ";}
    cout<<"\n";
    node *r;
    for(i=0;i<n;i++){r=p[i]->prev;if(r){cout<<r->index<<" ";}else{cout<<"NULL"<<" ";}}
}
