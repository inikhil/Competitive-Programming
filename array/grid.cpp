#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int solvecol(char** a,int &cnt,int m,int n,int n1,int m1){
    int i,j=n,k=0;
    for(i=m;i<n1;i++){
        if(a[i][j]=='.'||a[i][j]=='R'){break;}
        else if(a[i][j]=='B'){a[i][j]='X';k=1;}
        else if(a[i][j]=='G'){a[i][j]='R';k=1;}
    }
    if(k==1){cnt=cnt+1;}
    return i;
}

int solverow(char **a, int &cnt,int m,int n,int n1,int m1){
    int i=m,j,k=0;
    for(j=n;j<m1;j++){
        if(a[i][j]=='.'||a[i][j]=='X'){break;}
        else if(a[i][j]=='R'){a[i][j]='X';k=1;}
    }
    if(k==1){cnt=cnt+1;}
    return j;
}

int main(){
    int n,m;
    cin>>n>>m;
    char **a=new char*[n];
    int i,j;
    for(i=0;i<n;i++){
        a[i]=new char[m+1];
        for(j=0;j<m;j++){
            cin>>a[i][j];
            //cout<<a[i][j];
        }
    }
    int cnt=0;
    for(j=0;j<m;j++){
        for(i=0;i<n;i++){
            i=solvecol(a,cnt,i,j,n,m);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            j=solverow(a,cnt,i,j,n,m);
        }
    }
    cout<<cnt;
}
