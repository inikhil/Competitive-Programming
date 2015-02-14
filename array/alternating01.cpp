#include<iostream>
using namespace std;

void print(int **a,int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve(int **a, int rs, int re, int cs, int ce){
    //print(a,re+1,ce+1);
    if(rs>re||cs>ce){return;}
    static int d=0;
    int c;
    if(d%2==0){c=1;}
    else{c=0;}
    int i,j;
    //print(a,re+1,ce+1);
    //cout<<rs<<" "<<re<<" "<<cs<<" "<<ce<<endl;
    for(i=rs;i<=re;i=(i+re-rs)){
        for(j=cs;j<=ce;j++){
            a[i][j]=c;
        }
        if(re==rs){break;}
    }
    //print(a,re+1,ce+1);
    for(j=cs;j<=ce;j=j+(ce-cs)){
        for(i=rs;i<=re;i++){
            a[i][j]=c;
        }
        if(cs==ce){break;}
    }
    d++;
    //print(a,re+1,ce+1);
    solve(a,rs+1,re-1,cs+1,ce-1);
}

int main(){
    int n,m,i;
    cin>>m>>n;
    int **a=new int*[m];
    for(i=0;i<n;i++){
        a[i]=new int[n];
    }
    //print(a,m,n);
    solve(a,0,m-1,0,n-1);
    print(a,m,n);
}
