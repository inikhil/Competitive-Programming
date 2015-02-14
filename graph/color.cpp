#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int x;int y;
    node(int m,int n){x=m;y=n;}
};

char ** build(int n, int m){
    int i,j;
    char **a=new char*[n];
    for(i=0;i<n;i++){
        a[i]=new char[m];
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    return a;
}

int ** buildin(int n, int m){
    int i,j;
    int **a=new int*[n];
    for(i=0;i<n;i++){
        a[i]=new int[m];
        for(j=0;j<m;j++){
            a[i][j]=0;
        }
    }
    return a;
}
bool issafe(int x,int y,int n,int m){
    if(y<0||y>=m){return false;}
    if(x<0||x>=n){return false;}
    return true;
}

int main(){
    queue<node* > s;
    int n,m;
    cin>>n>>m;
    char **a=build(n,m);
    int xx,yy,i,j;
    cin>>xx>>yy;
    node *p=new node(xx,yy);
    s.push(p);
    int **b=buildin(n,m);
    while(s.empty()==false){
        node *q=s.front();
        s.pop();
        xx=q->x;yy=q->y;
        b[xx][yy]=1;
        if(issafe(xx-1,yy,n,m)&& a[xx-1][yy]==a[xx][yy]){
            q->x=xx-1;q->y=yy;
            s.push(q);
        }
        if(issafe(xx,yy-1,n,m)&& a[xx][yy-1]==a[xx][yy]){
            q->x=xx;q->y=yy-1;
            s.push(q);
        }
        if(issafe(xx,yy+1,n,m)&& a[xx][yy+1]==a[xx][yy]){
            q->x=xx;q->y=yy+1;
            s.push(q);
        }
        if(issafe(xx+1,yy,n,m)&& a[xx+1][yy]==a[xx][yy]){
            q->x=xx+1;q->y=yy;
            s.push(q);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(b[i][j] == 1){cout<<i<<" "<<j<<endl;}
        }
    }
}
