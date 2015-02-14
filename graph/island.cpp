#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

class node{
public:
    int n;
    char col;
    node(int n){
        this->n=n;
        this->col='w';
    }
};

void print(int **a,int m){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int** generatematrix(int m){
    int i,j;
    int **a=new int*[m];
    for(i=0;i<m;i++){
        a[i]=new int[m];
        for(j=0;j<m;j++){
            a[i][j]=rand()%2;
        }
    }
    return a;
}

int **inputmatrix(int m){
    int i,j;
    int **a=new int*[m];
    for(i=0;i<m;i++){
        a[i]=new int[m];
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    return a;
}

void dfs(node **p,int **a,int m,int k){
    p[k]->col='g';
    int i;
    for(i=0;i<m;i++){
        if(i!=k && a[k][i]==1 && p[i]->col=='w'){
            dfs(p,a,m,i);
        }
    }
    p[k]->col='b';
}

int solve(int **a,int m){
    int i;
    node **p=new node*[m];
    for(i=0;i<m;i++){
        p[i]=new node(m);
    }
    int cnt=0;
    for(i=0;i<m;i++){
        if(p[i]->col=='w'){
            cnt++;
            dfs(p,a,m,i);
        }
    }
    return cnt;
}

int main(){
    int m,t;
    cin>>m;
    //int **a=generatematrix(m);
    int **a=inputmatrix(m);
    print(a,m);
    t=solve(a,m);
    cout<<t<<endl;
}

